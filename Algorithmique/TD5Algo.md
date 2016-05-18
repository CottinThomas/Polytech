# TD n° 5

## Exercice 1

```
Algorithme NombreElements
Input
	A un Arbre
Processus
	n <- 1
	pour i allant de 0 à nbFils
		n<- n+NombreElements(A.Fils[i]);
	retourner n
Output 
	le nombre de noeux
```



```
Algorithme ValeurMax
Input
	A un Arbre
Processus
	maxVal <- A.valeur;
	pour i allant de 0 à nbFils
		maxVal = max(ValeurMax(A.Fils[i]), maxVal)
	retourner maxVal
```


```
Algorithme SommeValeurs
Input
	A un Arbre
Processus
	somme <- A.valeur;
	pour i allant de 0 à nbFils
		somme <- somme + SommeValeurs(A.Fils[i])
	retourner somme
```



```
Algorithme DistanceMinimaleFeuilleRacine
Input 
	A un Arbre
Processus
	res <- 0;
	pour i allant de 0 à nbFils
		db <- DistanceMinimaleFeuilleRacine(A.Fils[i])
		si res = 0 ou db < res
			res <- db
	retourner 1+res

```


```
Algorithme NombreDeFilsMax
Input
	A un Arbre
Processus
	maxFils = A.nbFils
	pour i allant de 0 à nbFils
		maxFils = max(maxFils, NombreDeFilsMax(A.Fils[i]))
	retourner maxFils
```

## Exercice 2

```
Algorithme ParcoursPrefix
Input
	A un ArbreBinaire
Processus
	si A != None
		Afficher A.valeur
		ParcoursPrefix(A.filsGauche)
		ParcoursPrefix(A.filsDroit)

```

```
Algorithme ParcoursEnLargeur
Input
	A un ArbreBinaire
Processus
	L <- Liste vide
	L.ajouteFin(A)
	tant que (non L.vide())
		b <- L.tete()
		L.supprimerTete();
		si(b.filsGauche != None)
			L.ajouteFin(b.filsGauche)
		si (b.filsDroit != None)
			L.ajouteFin(b.filsDroit)
	
```


```
Algorithme SontEgaux
Input
	A et B deux ArbreBinaire
Processus
	si A = None ou B = None
		si A = None et B = None
			retourner vrai
		retourner faux
	si A.valeur = B.valeur
		retourner SontEgaux(A.filsGauche, B.filsGauche) et SontEgaux(A.filsDroit, B.filsDroit)
	retourner faux
```

## Exercice 3

### 1
Arbres binaires :
	1 noeud : 1 solution
	2 noeuds : 2 solutions
	3 noeuds : 5 solutions

### 2
Arbres généraux :
	2 noeuds : 1 solution
	3 noeuds : 2 solutions
	4 noeuds : 5 solutions
nbSolutionsArbresBinaires(n) = nbSolutionsArbresGeneraux(n+1)

### 3
```
Structure : Arbre
	premierFils : Arbre
	frere : Arbre
```

### 5
```
Algorithme Hauteur
Input
	A ArbreBinaire représentant un Arbre
Processus
	Si A est NULL
		retourner 0
	h1, h2 : entiers
	h1 =  Hauteur(premierFils)+1
	h2 = Hauteur(frere)
	retourner max(h1,h2);
```

### 6
```
Algorithme CompterFils
Input
	A ArbreBinaire représentant un Arbre
Processus
	Si A est NULL
		retourner 0
	Retourner 1+CompterFils
```
```
Algorithme MaxFils
Input
	A ArbreBinaire représentant un Arbre
Processus
	Si A est Null
		retourner 0
	nb1, nb2, nb3: entiers
	nb1 = CompterFils(A.fils)
	nb2 = MaxFils(A.frere)
	nb3 = MaxFils(A.fils)
	retourner max(nb1, nb2, nb3)
```
```
Algorithme LanceurMaxFils
Input
	A ArbreBinaire représentant un Arbre
Processus
	retourner max(CompterFils(A), MaxFils(A))
```

## Exercice 5

### 1
						4	
		2/						\5
	1/		\3				5/		\6
				\4


						4
			2/					\5
		1/		\3			5/		\6
					\4		


### 2
L'obtention de la liste triée se fait par parcours *infixe*

### 3
La suite {1,2,3,4,5,6,7} ou {7,6,5,4,3,2,1} ou {1,1,1,1,1,1,1} ou {7,1,6,2,5,3,4} donne un ABR 7

### 4
La suite {4,2,6,1,3,5,7} donne un ABR 3

## Exercice 6
