# TP Streaming SIMD Extensions (SSE)

## 0.1 Quelle est la différence entre l’utilisation de la macro _MM_SHUFFLE et vfloat32_shuffle ? Quelle est l’utilité de vfloat32_shuffle ?

_MM_SHUFFLE(u,v,w,x) Se lit de droite à gauche. Le résultat obtenu sera donc a[x], a[w], bv], b[v]
vfloat32_shuffle(u,v,w,x) se lit lui dans l'ordre naturel. Le résultat ser donc a[u], a[v], b[w], b[x]

## 1

### 1.1
Gain = (Temps séquenciel) / (Temps SIMD)
Gain = (0.010688311) / (0.002868222) = 3.726458761 
Proche du gain espéré (4) mais pas égale (perte de performances car d'autres processus utilisent les ressources du système).

### 1.2
Gain = (0.011624017) / (0.002783253) = 4.03450387
Gain superieur avec la deuxieme méthode (> 4, AVX ?)

### 1.3
Gain = 0.344427768
Perte de 3,4 due à la suppression de -fno-tree-vectorize :
Les calculs de sum et sum_stl sont beaucoups plus rapides (passage de 0.013 à 0.0012)

## 2

Gain : 0,897247382
Gain faible par rapport aux gains précédents.

## 3 

### 3.1 
Les gains obtenus (peu importe la version) sont faibles. Par moments, la version 2 est même plus lente que la première implémentation.

## 4

## 5 

### 5.1
On travail ici sur un tableau à 2 dimensions, où chaque case est indépendante (par rapport aux précedentes). Le code est donc parallélisable.

### 5.2
Résultats des différents schedules
- none : 3.07878 s
- static : 2.88694 s
- dynamic : 1.35058 s
- guided : 1.50196 s
- auto : 2.87562 s
- runtime : 1.35509