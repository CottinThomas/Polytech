# TP Streaming SIMD Extensions (SSE)

## 0.1 Quelle est la différence entre l’utilisation de la macro _MM_SHUFFLE et vfloat32_shuffle ? Quelle est l’utilité de vfloat32_shuffle ?

## 1

### 1.1
Gain = (Temps séquenciel) / (Temps SIMD)
Gain = (0.010688311) / (0.002868222) = 3.726458761 
Proche du gain espéré (4)

### 1.2
Gain = (0.011624017) / (0.002783253) = 4.03450387
Gain superieur avec la deuxieme méthode (> 4, AVX)

### 1.3
Gain = 0.344427768
Perte de 3,4 due à la suppression de -fno-tree-vectorize :
Les calculs de sum et sum_stl sont beaucoups plus rapides (passage de 0.013 à 0.0012)

