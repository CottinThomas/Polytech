"""
	TD numero 0
	Thomas COTTIN
"""

"""
	CORRECTION DE L INDENTATION
"""
# 1
a=10
b=5
if a<b:
	print a
else:
	print b

# 2
a=100
b=3
if a>b:
	q=a/b
	r=a%b
	if r != 0:
		print a, "=", q,"*",b,"+",r
	else:
		a," est divisible par ",b

# 3
m=12342
h=0
if m>60:
	h = m/60
	m=h%60
print h,":",m


# 4
a=5
b=5
if a>5:
	if b>5:
		print "a et b sont superieurs a 5"
	else:
		print "seul a est superieurs a 5"
else:
	if b>5:
		print "seul b est superieur a 5"
	else:
		print "a et b sont inferieurs a 5"


"""
	VERIFICATIONS DES DATES
"""
def testDate(j,m,annee):
	valide=False
	bissextile=False
	if annee >=0:
		if (annee%4 == 0 and annee%100 != 0) or annee % 400 ==0:
			bissextile = True
		if m <= 12 or m >= 1:
			if m in [1,3,5,7,8,10,12]:
				if j >= 0 or j <= 31:
					valide=True
			else:
				if m == 2 and j>=1:
					if bissextile is True:
						if j<=29:
						 	valide=True
					else:
						if j<=28:
						 	valide=True
				else:
					if j<=30 and j>=0:
						 	valide=True
	if valide is True:
		print "Date",j,"/",m,"/",annee," VALIDE"
	else:
		print "Date",j,"/",m,"/",annee," INVALIDE"

testDate(31,3,1995) # VALIDE
testDate(23,10,2015) # VALIDE
testDate(29,2,1995) # INVALIDE
testDate(29,2,1996) # VALIDE
testDate(29,2,-1996) # VALIDE


"""
	BOUCLES WHILE
"""

# 1
a=0
n=100
while 2*a <= n:
	print a
	a=a+1
print n,"/2 = ",a-1

# 2
a=0
n=100
while 10**a <= n:
	print a
	a=a+1
print "log(",n,") = ",a-1

# 3
a=0
n=100
while a*a <= n:
	print a
	a=a+1
print "sqrt(",n,") = ",a-1


"""
	TESTS DES TYPES
"""

a=0
print a, "    ", type(a) #int
a=a+2
print a, "    ", type(a) #int
a=a-102
print a, "    ", type(a) #int
a=a+0.2
print a, "    ", type(a) #float

b=True
print a, "    ", type(a) #int
b=b+3
print b, "    ", type(b) #int
b=b-5
print b, "    ", type(b) #int

c="Bonjour"
c=c+" Toto"
print c, "    ", type(c)
# soustraction impossible
# add int impossible



d=123456789123456789123456789
print d, "    ", type(d)

"""
	PREMIER LONG
"""
a=2
b=2
while not isinstance(a,long):
	b=a
	a=a*10
a=b;
div = 10
while not isinstance(a,long):

	while not isinstance(a,long):
		b=a
		a=a+a/div
		print a
	div = div*10
	a=b
	if a/div == 0:
		a = a+1

print "Premier long : ",a, " Nombre precedent :",b," de type", type(b)

"""
	AFFICHER VALEURS LISTES
"""
def readList(a):	
	b=0
	while b<len(a):
		print a[b]
		b=b+1

readList(["chien","chat","vache","poisson","licorne"])

"""
	LISTE PAIRS 0-100
"""
a=[]
b=0
while b<=100:
	a.append(b)
	b=b+2
readList(a)

"""
	FONCTION RANGE
"""
i=[]
for a in range(20):
	i.append(a)
ii=[]
for a in range(10):
	ii.append(a+1)
iii=[]
for a in range (0,21,2):
	iii.append(a)
iv=[]
for a in range (10,0,-1):
	iv.append(a)
v=[]
for a in range (-20,0):
	v.append(a)
vi=[]
for a in range (-1,-21,-1):
	vi.append(a)
readList(i)
print
readList(ii)
print
readList(iii)
print
readList(iv)
print
readList(v)
print
readList(vi)
print

"""
	BOUCLE FOR
"""

def carre():
	res = 0
	for i in xrange(11):
		print i,"^2 = ",i*i
		pass
carre()

def occurenceListe(l,a):
	compteur = 0
	for i in xrange(len(l)):
		if l[i]==a:
			compteur = compteur+1
	return compteur

l = [2,3,3,2,4,4,2,3,2,4,5,2,2,3]
a = 3
print occurenceListe(l,a)

"""
	COMPREHENSION LISTE
"""
l = [i*i for i in xrange(50)]
readList(l)
print
l = [i for i in xrange(1,100,2)]
readList(l)
print
l = [i for i in xrange(1,100) if i%3==0]
readList(l)
print
l = [i for i in xrange(1,100) if i%3==0 and i%2==0]
readList(l)
print

"""
	FONCTIONS
"""

def absolue(a):
	if a<0:
		return -a
	return a
assert(absolue(4)==4)
assert(absolue(-3)==3)
assert(absolue(0)==0)
print "Les tests passent !"

def puissance(a,b):
	p=1
	for i in xrange(b):
		p=p*a
	return p
assert(puissance(2,3)==2**3)
assert(puissance(3,4)==3**4)
assert(puissance(-1,5)==-1)
print "Les tests passent !"

def sommen(n):
	s=0
	for i in xrange(n+1):
		s=s+i
	return s
assert(sommen(10)==55)
assert(sommen(13)==91)
print "Les tests passent !"

def maximumListe(l):
	maxi=l[0]
	for i in xrange(len(l)):
		if l[i]>maxi:
			maxi = l[i]
	return maxi
assert(maximumListe([2,4,2,5,7,7,2])==7)
assert(maximumListe([14,4,2,5,7,7,2])==14)
assert(maximumListe([2,4,2,5,7,7,23])==23)
print "Les tests passent !"