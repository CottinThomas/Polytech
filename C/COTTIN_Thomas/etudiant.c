#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "etudiant.h"

/**
 * Constructeur
 */
TEtudiant* creerEtudiant(char* nom, char* prenom){
	TEtudiant* etudiant = (TEtudiant*) malloc(sizeof(TEtudiant));
	etudiant->nom = malloc(strlen(nom)*sizeof(char)+1);
	etudiant->prenom = malloc(strlen(prenom)*sizeof(char)+1);
	strcpy(etudiant->nom, nom);
	strcpy(etudiant->prenom , prenom);
	etudiant->notePartiel = -1.0;
	etudiant->noteCC = -1.0;
	etudiant->noteExam1 = -1.0;
	etudiant-> noteExam2 = -1.0;
	return etudiant;
}

/**
 * Destructeur
 */
void supprimerEtudiant(TEtudiant* etudiant ){
	if( etudiant != NULL){
		if(etudiant->prenom != NULL)
			free(etudiant->prenom);
		if(etudiant->nom != NULL)
			free(etudiant->nom);
		free(etudiant);
	}
}

/**
 * Donne la note passée en paramètre a l'étudiant passé en parametre
 */
void setNote(TEtudiant* etudiant, float note, int typeNote){
	if(etudiant == NULL){
		printf("L'étudiant spécifié n'est pas existant.");
		return;
	}
	if(note < 0.0 || note > 20.0){
		printf("ERREUR - La note doit être comprise entre 0 et 20.");
		return;
	}
	switch(typeNote){
		case 0:
			etudiant->notePartiel = note;
			break;
		case 1:
			etudiant->noteCC = note;
			break;
		case 2:
			etudiant->noteExam1 = note;
			break;
		case 3:
			etudiant->noteExam2 = note;
			break;
	}
}

/**
 * Accès a une note passée en paramètre
 */
float getNote(TEtudiant* etudiant, int typeNote){
	if(etudiant == NULL){
		printf("L'étudiant spécifié n'est pas existant.");
		return -1.0;
	}
	switch(typeNote){
		case 0:
			return etudiant->notePartiel;
		case 1:
			return etudiant->noteCC;
		case 2:
			return etudiant->noteExam1;
		case 3:
			return etudiant->noteExam2;
		default:
			printf("Aucun type de note associé à l'identifiant passé en paramètre : %d.", typeNote);
			return -1.0;
	}
}

/**
 * Retourne la note de l'étudiant à la première session
 * ==> note = MAX (NoteExam1, (2*NoteExam1 + NoteCC + NotePartiel)/4)
 */
float getNotePremiereSession(TEtudiant* etudiant){
	if(etudiant == NULL){
		printf("L'étudiant spécifié n'est pas existant.");
		return -1;
	}
	if(etudiant->notePartiel == -1.0 || etudiant->noteCC == -1.0 || etudiant->noteExam1 == -1.0){ // vérification du fait que les notes existent
		printf("L'une des note n'a pas été définie");
		return -2;
	}
	float note = (2*etudiant->noteExam1 + etudiant->noteCC + etudiant->notePartiel)/4;
	if(note > etudiant->noteExam1)
		return note;
	return etudiant->noteExam1;
}

/**
 * Retourne la note de l'étudiant à la première session
 * ==> note = MAX (NoteExam1, (2*NoteExam1 + NoteCC + NotePartiel)/4)
 */
float getNoteDeuxiemeSession(TEtudiant* etudiant){
	if(etudiant == NULL){
		printf("L'étudiant spécifié n'est pas existant.");
		return -1;
	}
	if(etudiant->notePartiel == -1.0 || etudiant->noteCC == -1.0 || etudiant->noteExam1 == -1.0 || etudiant->noteExam2 == -1.0){ // vérification du fait que les notes existent
		printf("L'une des note n'a pas été définie");
		return -2;
	}
	float note = (2*etudiant->noteExam2 + etudiant->noteExam1 + etudiant->noteCC + etudiant->notePartiel)/5;
	if(note > etudiant->noteExam2)
		return note;
	return etudiant->noteExam1;
}

/**
 * Retourne la note finale de l'étudiant
 */
float getNoteFinale(TEtudiant* etudiant){
	int a = getNotePremiereSession(etudiant);
	if (a >= 10){
		return a;
	}
	int b = getNoteDeuxiemeSession(etudiant);
	if (a<b)
		return b;
	return a;
}

/**
 * Détermine si l'étudiant est reçu (0 = non recu, 1 recu à la session 1, 2 recu a la session 2)
 */
int estRecu(TEtudiant* etudiant){
	//int a = getNotePremiereSession(etudiant);
	if (getNotePremiereSession(etudiant) >= 10)
		return 1;
	if (getNoteDeuxiemeSession(etudiant) >= 10)
		return 2;
	return 0;
}


