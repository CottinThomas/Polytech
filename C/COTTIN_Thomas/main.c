#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "etudiant.h"
#include "classe.h"
#include "main.h"



int main (int argc, const char * argv[]){
	TEtudiant* leo = creerEtudiant("DONNY", "Leo");

	printf("L'étudiant %s %s a été créé.\n", leo->prenom, leo->nom);

	setNote(leo, 18.2, NOTE_PARTIEL);
	printf("Note au partiel: %2.1f\n", getNote(leo, NOTE_PARTIEL));

	setNote(leo, 11.4, NOTE_CC);
	printf("Note au CC: %2.1f\n", getNote(leo, NOTE_CC));

	setNote(leo, 5.3, NOTE_EXAM1);
	printf("Note au CC: %2.1f\n", getNote(leo, NOTE_EXAM1));

	printf("L'étudiant %s %s à pour résultat à la première session %2.1f\n", leo->prenom, leo->nom, getNoteFinale(leo));

	switch(estRecu(leo)){
		case 0:
			printf("L'étudiant %s %s n'est pas reçu.", leo->prenom, leo->nom);
			break;
		case 1:
			printf("L'étudiant %s %s est recu à la première session.\n", leo->prenom, leo->nom);
			break;
		case 2:
			printf("L'étudiant %s %s est recu à la deuxième session.\n", leo->prenom, leo->nom);
			break;
	}

	supprimerEtudiant(leo);


	printf("Note au partiel: %2.1f\n", getNote(leo, NOTE_PARTIEL));

	printf("\n");
	return 0;
}