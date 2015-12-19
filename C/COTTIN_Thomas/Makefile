# -------------- #
# -- Makefile -- #
# -------------- #

OBJ = etudiant.o classe.o main.o
HEADER = etudiant.h classe.h main.h

COTTIN_Thomas.exe: $(OBJ) $(HEADER)
	gcc -o COTTIN_Thomas.exe $(OBJ)

etudiant.o: etudiant.c $(HEADER)
	gcc -c etudiant.c

classe.o: classe.c $(HEADER)
	gcc -c classe.c

main.o: main.c $(HEADER)
	gcc -c main.c

#clean:
#	rm -f $(OBJ)
#	rm -f COTTIN_Thomas.exe
clean:
	del $(OBJ)
	del COTTIN_Thomas.exe