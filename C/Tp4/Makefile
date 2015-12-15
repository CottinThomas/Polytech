# -------------- #
# -- Makefile -- #
# -------------- #

OBJ = liste.o liste_test.o main.o
HEADER = liste.h liste_test.h param_perl.h

tp4.exe: $(OBJ) $(HEADER)
	clang -o t.exe $(OBJ)

liste_test.o: liste_test.c $(HEADER)
	clang -c liste_test.c

liste.o: liste.c $(HEADER)
	clang -c liste.c

main.o: main.c $(HEADER)
	clang -c main.c

clean:
	rm -f $(OBJ)
	rm -f t.exe
