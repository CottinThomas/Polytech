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
#include <array>

#include <x86intrin.h>


using vfloat32_t = __m128;


inline
std::array<float, 4> to_array(vfloat32_t const vfloat32)
{
	std::array<float, 4> r;
	_mm_store_ps(r.data(), vfloat32);
	return r;
}


inline
std::ostream & operator <<(std::ostream & out, vfloat32_t const vfloat32)
{
	auto array = to_array(vfloat32);
	out << "{ " << array[0] << ", " << array[1] << ", " << array[2] << ", " << array[3] << " }";
	return out;
}


#define vfloat32_shuffle(a, b, c, d) _MM_SHUFFLE(d, c, b, a)


vfloat32_t vfloat32_zero = _mm_set_ps(0.f, 0.f, 0.f, 0.f);


inline
vfloat32_t vfloat32_left_1(vfloat32_t const vfloat32, vfloat32_t const vfloat32_next)
{
	// TODO
	vfloat32_t r;
	return r;
}


inline
vfloat32_t vfloat32_right_1(vfloat32_t const vfloat32, vfloat32_t const vfloat32_prev)
{
	// TODO
	vfloat32_t r;
	return r;
}
