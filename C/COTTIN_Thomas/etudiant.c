#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "etudiant.h"

/**
 * Constructeur : 
 *		char* nom : nom de l'étudiant
 *		char* prenom : prenom de l'étudiant
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
 *		TEtudiant* etudiant : etudiant à supprimer
 */
void supprimerEtudiant(TEtudiant** etudiant ){
	if( etudiant[0] != NULL){
		if(etudiant[0]->prenom != NULL)
			free(etudiant[0]->prenom);
		if(etudiant[0]->nom != NULL)
			free(etudiant[0]->nom);
		free(etudiant[0]);
		etudiant[0] = NULL;
	}
}

/**
 * Donne la note "note" a "etudiant" pour l'interro de "typeNote"
 *		TEtudiant* etudiant : etudiant à modifier
 *		float note : la note à attribuer
 *		int typeNote : le type d'interro (voir constantes)
 */
void setNote(TEtudiant* etudiant, float note, int typeNote){
	if(etudiant == NULL){
		printf("L'étudiant spécifié n'est pas existant.\n");
		return;
	}
	if(note < 0.0 || note > 20.0){
		printf("ERREUR - La note doit être comprise entre 0 et 20.\n");
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
 * Retourne la note "typeNote" de "etudiant"
 *		TEtudiant* etudiant : etudiant interrogé
 *		int typeNote : le type d'interro (voir constantes)	
 */
float getNote(TEtudiant* etudiant, int typeNote){
	if(etudiant == NULL){
		printf("L'étudiant spécifié n'est pas existant.\n");
		return -2.0;
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
			printf("Aucun type de note associé à l'identifiant passé en paramètre : %d.\n", typeNote);
			return -1.0;
	}
}

/**
 * Retourne la note de "etudiant" à la première session
 *		TEtudiant* etudiant : etudiant à modifier
 * ==> note = MAX (NoteExam1, (2*NoteExam1 + NoteCC + NotePartiel)/4)
 */
float getNotePremiereSession(TEtudiant* etudiant){
	if(etudiant == NULL){
		printf("L'étudiant spécifié n'est pas existant.\n");
		return -2;
	}
	if(etudiant->notePartiel == -1.0 || etudiant->noteCC == -1.0 || etudiant->noteExam1 == -1.0){ // vérification du fait que les notes existent
		printf("L'une des note n'a pas été définie\n");
		return -1;
	}
	float note = (2*etudiant->noteExam1 + etudiant->noteCC + etudiant->notePartiel)/4;
	if(note > etudiant->noteExam1)
		return note;
	return etudiant->noteExam1;
}

/**
 * Retourne la note de "etudiant" à la deuxieme session
 *		TEtudiant* etudiant : etudiant à modifier
 * ==> note = MAX (NoteExam1, (2*NoteExam1 + NoteCC + NotePartiel)/4)
 */
float getNoteDeuxiemeSession(TEtudiant* etudiant){
	if(etudiant == NULL){
		printf("L'étudiant spécifié n'est pas existant.\n");
		return -2;
	}
	if(etudiant->notePartiel == -1.0 || etudiant->noteCC == -1.0 || etudiant->noteExam1 == -1.0 || etudiant->noteExam2 == -1.0){ // vérification du fait que les notes existent
		printf("L'une des note n'a pas été définie\n");
		return -1;
	}
	float note = (2*etudiant->noteExam2 + etudiant->noteExam1 + etudiant->noteCC + etudiant->notePartiel)/5;
	if(note > etudiant->noteExam2)
		return note;
	return etudiant->noteExam2;
}

/**
 * Retourne la note finale de "etudiant"
 *		TEtudiant* etudiant : etudiant à modifier
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
 * Détermine si etudiant est reçu 
 *		TEtudiant* etudiant : etudiant à modifier
 *	0 = non recu, 1 recu à la session 1, 2 recu a la session 2
 */
int estRecu(TEtudiant* etudiant){
	if (getNotePremiereSession(etudiant) >= 10)
		return 1;
	if (getNoteDeuxiemeSession(etudiant) >= 10)
		return 2;
	return 0;
}

/**
 * Fonction permettant un affichage formaté des étudiants. Utile pour les tests.
 *		TEtudiant* etudiant : l'étudiant à afficher
 */
void afficherEtudiant(TEtudiant* etudiant){
	if(etudiant != NULL){
		printf("%s, %s\n",etudiant->nom, etudiant->prenom);
		printf("\tNote partiel : %2.1f/20\n", etudiant->notePartiel);
		printf("\tNote contrôle continu : %2.1f/20\n", etudiant->noteCC);
		printf("\tNote premier examen : %2.1f/20\n", etudiant->noteExam1);
		printf("\tNote second examen : %2.1f/20\n\n", etudiant->noteExam2);
	}
}


