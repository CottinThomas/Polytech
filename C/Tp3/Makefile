# -------------- #
# -- Makefile -- #
# -------------- #

OBJ = chaine.o chaine_test.o main.o
HEADER = chaine.h chaine_test.h param_perl.h

tp3.exe: $(OBJ) $(HEADER)
	gcc -o tp3 $(OBJ)

chaine_test.o: chaine_test.c $(HEADER)
	gcc -c chaine_test.c

chaine.o: chaine.c $(HEADER)
	gcc -c chaine.c

main.o: main.c $(HEADER)
	gcc -c main.c

clean:
	rm -f $(OBJ)
	rm -f tp3
