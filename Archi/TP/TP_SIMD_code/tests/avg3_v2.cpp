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
	
	if (v.size() == 12)
	{
		for (size_t i = 0; i < v.size(); ++i)
		{
			v[i] = float(i + 1);
		}
		
		std::cout << v << std::endl;
	}
	else
	{
		for (auto & e : v)
		{
			e = hopp::random::uniform(0.1f, 0.2f);
		}
	}
	
	// avg3
	{
		std::vector<float, boost::alignment::aligned_allocator<float, 16>> r(N);
		
		auto const time_start = hopp::now::seconds();
		
		for (size_t i = 4; i + 4 < v.size(); ++i)
		{
			r[i] = (v[i-1] + v[i] + v[i+1]) / 3.f;
		}
		
		auto const time_end = hopp::now::seconds();
		
		if (r.size() == 12) { std::cout << r << std::endl; }
		
		std::cout << "avg3     = (" << time_end - time_start << " seconds)" << std::endl;
	}
	
	// avg3 SSE
	{
		std::vector<float, boost::alignment::aligned_allocator<float, 16>> r(N);
		
		auto const time_start = hopp::now::seconds();
		
		vfloat32_t vfloat32_three = _mm_set_ps(3.f, 3.f, 3.f, 3.f);
		
		vfloat32_t vprev = _mm_load_ps(&v[0]);
		vfloat32_t ve = _mm_load_ps(&v[4]);
		
		for (size_t i = 4; i + 4 < v.size(); i += 4)
		{
			// TODO
		}
		
		auto const time_end = hopp::now::seconds();
		
		if (r.size() == 12) { std::cout << r << std::endl; }
		
		std::cout << "avg3_sse = (" << time_end - time_start << " seconds)" << std::endl;
	}
	
	return 0;
}
