#ifndef _ETUDIANT_H
#define _ETUDIANT_H


#include <stdio.h>
#include <string.h>
#include <stdlib.h>



/**
 *	Structure représentant la classe Etudiant
 **/
typedef struct TEtudiant_s{
	char* nom;
	char* prenom;
	float notePartiel;
	float noteCC;
	float noteExam1;
	float noteExam2;
} TEtudiant;

/**
 * Constructeur : 
 *		char* nom : nom de l'étudiant
 *		char* prenom : prenom de l'étudiant
 */
TEtudiant* creerEtudiant(char* nom, char* prenom);

/**
 * Destructeur
 *		TEtudiant* etudiant : etudiant à supprimer
 */
void supprimerEtudiant(TEtudiant** etudiant );

/**
 * Donne la note "note" a "etudiant" pour l'interro de "typeNote"
 *		TEtudiant* etudiant : etudiant à modifier
 *		float note : la note à attribuer
 *		int typeNote : le type d'interro (voir constantes)
 */
void setNote(TEtudiant* etudiant, float note, int typeNote);

/**
 * Retourne la note "typeNote" de "etudiant"
 *		TEtudiant* etudiant : etudiant interrogé
 *		int typeNote : le type d'interro (voir constantes)	
 */
float getNote(TEtudiant* etudiant, int typeNote);

/**
 * Retourne la note de "etudiant" à la première session
 *		TEtudiant* etudiant : etudiant à modifier
 * ==> note = MAX (NoteExam1, (2*NoteExam1 + NoteCC + NotePartiel)/4)
 */
float getNotePremiereSession(TEtudiant* etudiant);

/**
 * Retourne la note de "etudiant" à la deuxieme session
 *		TEtudiant* etudiant : etudiant à modifier
 * ==> note = MAX (NoteExam1, (2*NoteExam1 + NoteCC + NotePartiel)/4)
 */
float getNoteDeuxiemeSession(TEtudiant* etudiant);

/**
 * Retourne la note finale de "etudiant"
 *		TEtudiant* etudiant : etudiant à modifier
 */
float getNoteFinale(TEtudiant* etudiant);

/**
 * Détermine si etudiant est reçu 
 *		TEtudiant* etudiant : etudiant à modifier
 *	0 = non recu, 1 recu à la session 1, 2 recu a la session 2
 */
int estRecu(TEtudiant* etudiant);

#endif