// Copyright © 2016 Université Paris-Sud, Written by Lénaïc Bagnères, lenaic.bagneres@u-psud.fr

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include <boost/align/aligned_allocator.hpp>

#include "hopp/time/now.hpp"
#include "hopp/print/std.hpp"
#include "hopp/random.hpp"
#include "hopp/container/vector2D.hpp"
#include "hopp/color.hpp"
#include "hopp/time/now.hpp"

#include "simd.hpp"


// http://sdz.tdct.org/sdz/dessiner-la-fractale-de-mandelbrot.html
auto fractal_mandelbrot(double const zoom, size_t const i_max, bool color = false)
{
	double const x1 = -2.1;
	double const x2 = 0.6;
	double const y1 = -1.2;
	double const y2 = 1.2;
	
	size_t const size_x = size_t((x2 - x1) * zoom);
	size_t const size_y = size_t((y2 - y1) * zoom);
	std::cout << "Size = " << size_x << " x " << size_y << std::endl;
	
	hopp::vector2D<hopp::color> r(size_y, size_x, hopp::color::black());
	
	/*
	 * On place ici l'instruction OpenMP permettant de paralléliser le calcul. Le schedule le plus efficace est ici guided (voir CR) 
	 */
	#pragma omp parallel for schedule(runtime)
	for (size_t x = 0; x < size_x; ++x)
	{
		for (size_t y = 0; y < size_y; ++y)
		{
			double const c_r = double(x) / zoom + x1;
			double const c_i = double(y) / zoom + y1;
			
			double z_r = 0.0;
			double z_i = 0.0;
			
			size_t i = 0;
			
			do
			{
				double tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				++i;
			}
			while (z_r * z_r + z_i * z_i < 4 && i < i_max);
			
			if (color)
			{
				if (i != i_max)
				{
					r[y][x] = { 0, 0, hopp::uint8(i * 255 / i_max) };
				}
			}
			else
			{
				if (i == i_max)
				{
					r[y][x] = hopp::color::white();
				}
			}
		}
	}
	
	return r;
}


int main(int /*argc*/, char * * argv)
{
	float const zoom = 2000.0;
	size_t const i_max = 500;
	
	std::cout << argv[0] << " (zoom = " << zoom << ", i_max = " << i_max << ")" << std::endl;
	
	
	auto const time_start = hopp::now::seconds();
	
	auto const r = fractal_mandelbrot(zoom, i_max, true);
	
	auto const time_end = hopp::now::seconds();
	
	std::cout << time_end - time_start << " seconds" << std::endl;
	
	
	// https://fr.wikipedia.org/wiki/Portable_pixmap#PPM
	if (true)
	{
		std::ofstream out(std::string{argv[0]} + ".ppm");
		
		out << "P3" << "\n";
		out << r.nb_col() << " " << r.nb_row() << "\n";
		out << "255" << "\n";
		
		for (auto const line : r)
		{
			for (auto const color : line)
			{
				out << color.r << " " << color.g << " " << color.b << " ";
			}
			out << "\n";
		}
	}
	
	return 0;
}
