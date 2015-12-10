"""
	TD numero 1
	Thomas COTTIN
"""

""" COMPLEXITE """

def complexiteNN(n):
	toto = 0
	for i in xrange(n):
		for j in range(n):
			toto = toto + 1
	return toto

def complexiteNNN(n):
	toto = 0
	for i in xrange(n):
		for j in range(n):
			for k in range(n):
				toto = toto + 1
	return toto

def complexiteSQRTN(n):
	toto = 0
	i=0
	while i*i < n:
		toto = toto+1
		i=i+1
	return toto

""" RECHERCHES """

def recherche(l, v):
	i=0
	while i < len(l)-1:
		if l[i]==v:
			return True
		i = i+1
	return False 
assert(recherche([5,2,4,2,6,4,6], 4))
assert(recherche([5,2,4,2,6,4,6], 5))
assert(recherche([5,2,4,2,6,4,6], 2))
assert(recherche([5,2,4,2,6,4,6], 6))
assert(not recherche([5,2,4,2,6,4,6], 10))

def rechercheDicho(l, v):
	debut = 0
	fin = len(l)-1
	milieu=(fin-debut)/2
	trouve = False
	while debut <= fin:
		if l[milieu] == v:
			return True
		if l[milieu] < v:
			debut = milieu+1
		else:
			fin = milieu-1
		milieu=(fin+debut)//2
	return False

assert(rechercheDicho([2,2,4,4,5,6], 4))
assert(rechercheDicho([2,2,4,4,5,6], 5))
assert(rechercheDicho([2,2,4,4,5,6], 2))
assert(rechercheDicho([2,2,4,4,5,6], 6))
assert(not rechercheDicho([2,2,4,4,5,6], 10))

def random_tableau(n):
	import random
	return [random.randint(1,n) for i in xrange(n)]

def getRandomOrderedTab(n):
	a = random_tableau(n)
	a.sort()
	return a


# Recherche de la valeur 4
t100 = getRandomOrderedTab(100)
# normal :	12 microsecondes
# dicho  :	13 microsecondes
t1000 = getRandomOrderedTab(1000)
# normal :	785 microsecondes
# dicho  :	21 microsecondes
t10000 = getRandomOrderedTab(10000)
# normal :	5.02 milisecondes
# dicho  :	18 microsecondes
t1000000 = getRandomOrderedTab(1000000)
# normal :	263 milisecondes
# dicho  :	35 microsecondes


def recherchePresqueDicho(l,v):
	l.sort()
	return rechercheDicho(l,v)
assert(recherchePresqueDicho([5,2,4,2,6,4,6], 4))
assert(recherchePresqueDicho([5,2,4,2,6,4,6], 5))
assert(recherchePresqueDicho([5,2,4,2,6,4,6], 2))
assert(recherchePresqueDicho([5,2,4,2,6,4,6], 6))
assert(not recherchePresqueDicho([5,2,4,2,6,4,6], 10))

# recherche de la valeur 156 dans le t1000000
# normal : 339 microsecondes
# presque dicho : 58.9 milisecondes



tab1=[1,2,3,4,5,6,7,8,9]
tab2=[1,3,4,6,7,9,8,2,5]

# RECHERCHES
#				   tab1				tab2
#----------------------------------------
#normal			|	9micros		|   11 micros
#dicho 			|	10 micros	|	/
#presque dicho 	|	729 micros 	| 	14 micros	
#natif 			|	6 micros	|	10 micros