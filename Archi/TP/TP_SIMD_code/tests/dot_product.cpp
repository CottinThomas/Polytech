// Copyright © 2015 Université Paris-Sud, Written by Lénaïc Bagnères, lenaic.bagneres@u-psud.fr

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
#include <algorithm>
#include <limits>

#include <boost/align/aligned_allocator.hpp>

#include "hopp/time/now.hpp"
#include "hopp/print/std.hpp"
#include "hopp/random.hpp"

#include "simd.hpp"


int main(int argc, char * * argv)
{
	std::cout.precision(std::numeric_limits<float>::max_digits10);
	
	size_t const N = (argc > 1 && std::string(argv[1]) == "--test") ? (3 * 4) : (1 * 1000 * 1000 * 4);
	
	std::cout << argv[0] << " (N = " << N << ")" << std::endl;
	
	std::vector<float, boost::alignment::aligned_allocator<float, 16>> v(N);
	std::vector<float, boost::alignment::aligned_allocator<float, 16>> w(N);
	
	if (v.size() == 12)
	{
		for (size_t i = 0; i < v.size(); ++i)
		{
			v[i] = float(i + 1);
			w[i] = float(i + 1);
		}
		
		std::cout << v << std::endl;
	}
	else
	{
		for (auto & e : v)
		{
			e = hopp::random::uniform(0.1f, 0.2f);
		}
		
		for (auto & e : w)
		{
			e = hopp::random::uniform(0.1f, 0.2f);
		}
	}
	
	// Dot Product
	{
		auto const time_start = hopp::now::seconds();
		
		float dot_product = 0.f;
		
		for (size_t i = 0; i < v.size(); ++i)
		{
			dot_product += v[i] * w[i];
		}
		
		auto const time_end = hopp::now::seconds();
		
		std::cout << "dot_product     = " << dot_product << " (" << time_end - time_start << " seconds)" << std::endl;
	}
	
	// Dot Product SSE
	{
		auto const time_start = hopp::now::seconds();
		
		vfloat32_t vfloat32_dot_product = vfloat32_zero;
		
		for (size_t i = 0; i < v.size(); i += 4)
		{
			// TODO
		}
		
		float dot_product;
		{
			auto const array = to_array(vfloat32_dot_product);
			dot_product = std::accumulate(array.begin(), array.end(), 0.f);
		}
		
		auto const time_end = hopp::now::seconds();
		
		std::cout << "dot_product_sse = " << dot_product << " (" << time_end - time_start << " seconds)" << std::endl;
	}
	
	return 0;
}
