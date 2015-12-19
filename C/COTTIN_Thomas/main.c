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

	supprimerEtudiant(&leo); // passage de l'adresse du pointeur pour mise a null

	int note = getNote(leo, NOTE_PARTIEL);
	if(note != -1.0)
		printf("La note obtenue au partiel est de : %f\n", note);


	TClasse* classe = creerClasse("Ma Classe", 5);
	ajouterEtudiant(classe,"COTTIN","Thomas");
	if(chercherEtudiant(classe,"COTTIN","Thomas") >= 0)
		printf("L'étudiant COTTIN Thomas est dans la classe.\n");
	else
		printf("L'étudiant COTTIN Thomas n'est pas dans la classe.\n");

	enleverEtudiant(classe, "COTTIN", "Thomas");
	if(chercherEtudiant(classe,"COTTIN","Thomas") >= 0)
		printf("L'étudiant COTTIN Thomas est dans la classe.\n");
	else
		printf("L'étudiant COTTIN Thomas n'est pas dans la classe.\n");

	supprimerClasse(&classe);
	if(chercherEtudiant(classe,"COTTIN","Thomas") != -2)
		printf("La classe existe\n");

	lireClasse(classe);

	printf("\n");
	return 0;
}