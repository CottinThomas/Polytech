# -------------- #
# -- Makefile -- #
# -------------- #

OBJ = etudiant.o classe.o
HEADER = etudiant.h classe.h

COTTIN_Thomas.exe: $(OBJ) $(HEADER)
	clang -o COTTIN_Thomas.exe $(OBJ)

etudiant.o: etudiant.c $(HEADER)
	clang -c etudiant.c

classe.o: classe.c $(HEADER)
	clang -c classe.c

clean:
	rm -f $(OBJ)
	rm -f COTTIN_Thomas.exe
