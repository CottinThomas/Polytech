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
#include <string>
#include <algorithm>
#include <limits>

#include "simd.hpp"


int main()
{
	/* 
	 * Comparaison des macros _MM_SCHUFFLE et vfloat32_schuffle
	 */
	vfloat32_t a = _mm_setr_ps(1.f, 2.f, 3.f, 4.f);
	std::cout << "a = " << a << std::endl;
	vfloat32_t b = _mm_setr_ps(9.f, 8.f, 7.f, 6.f);
	std::cout << "b = " << b << std::endl;
	vfloat32_t tmp = _mm_shuffle_ps(a, b, _MM_SHUFFLE(0,1,3,2));
	std::cout << "_mm_shuffle_ps(a, b, _MM_SHUFFLE(0,1,3,2) = " << tmp << std::endl;
	vfloat32_t tmp_2 = _mm_shuffle_ps(a, b, vfloat32_shuffle(0,1,3,2));
	std::cout << "_mm_shuffle_ps(a, b, vfloat32_shuffle(0,1,3,2)) = " << tmp_2 << std::endl;

	/*
	 * Calcul de la somme des éléments du vecteur
	 * => On tente de placer le résultat (10) dans la première 'case' de celui-ci
	 */

	vfloat32_t floats = _mm_setr_ps(1.f, 2.f, 3.f, 4.f);
	std::cout << "floats = " << floats << std::endl;

	vfloat32_t tmp0 = _mm_shuffle_ps(floats, floats, vfloat32_shuffle(1,1,3,3));
	std::cout << "tmp0   = " << tmp0 << std::endl; // on obtiens (2,2,4,4)

	vfloat32_t tmp1 = _mm_add_ps(floats, tmp0);
	std::cout << "tmp1   = " << tmp1 << std::endl; // on obtiens (3,4,7,8)

	vfloat32_t tmp2 = _mm_shuffle_ps(tmp1, vfloat32_zero, vfloat32_shuffle(2,2,0,0));
	std::cout << "tmp2   = " << tmp2 << std::endl; // on obtiens (7,7,0,0)

	vfloat32_t res = _mm_add_ps(tmp1, tmp2);
	std::cout << "res   = " << res << std::endl; // on obtiens (10,11,7,8)

	res = _mm_shuffle_ps(res, vfloat32_zero, vfloat32_shuffle(0,0,0,0)); // on place deux zeros à la fin (il n'est pas possible d'en mettre en indice 1 car pas de 0 dans res)
	std::cout << "res   = " << res << std::endl; // on obtiens (10,10,0,0)

	res = _mm_shuffle_ps(res, vfloat32_zero, vfloat32_shuffle(0,3,0,0)); // on place un zero en 1 et on laisse zero en 2 et 3
	std::cout << "res   = " << res << std::endl; // on obtiens (10,0,0,0)
	


	return 0;
}
