#ifndef _ETUDIANT_H
#define _ETUDIANT_H


#include <stdio.h>
#include <string.h>
#include <stdlib.h>



/**
 *	Structure représentant la classe Etudiant
 **/
typedef struct struct TEtudiant_s{
	char* nom;
	char* prenom;
	float notePartiel;
	float noteCC;
	float noteExam1;
	float noteExam2;
} TEtudiant;

/**
 * Constructeur
 **/
TEtudiant* creerEtudiant(char* nom, char* prenom);

/**
 * Destructeur
 */
void supprimerEtudiant(TEtudiant* etudiant );

/**
 * Donne la note passée en paramètre a l'étudiant passé en parametre
 */
void setNote(TEtudiant* etudiant, float note, int typeNote);

/**
 * Accès a une note passée en paramètre
 */
float getNote(TEtudiant* etudiant, int typeNote);

/**
 * Retourne la note de l'étudiant à la première session
 * ==> note = MAX (NoteExam1, (2*NoteExam1 + NoteCC + NotePartiel)/4)
 */
float getNotePremiereSession(TEtudiant* etudiant);

/**
 * Retourne la note de l'étudiant à la première session
 * ==> note = MAX (NoteExam1, (2*NoteExam1 + NoteCC + NotePartiel)/4)
 */
float getNoteDeuxiemeSession(TEtudiant* etudiant);

/**
 * Retourne la note finale de l'étudiant
 */
float getNoteFinale(TEtudiant* etudiant);

/**
 * Détermine si l'étudiant est reçu (0 = non recu, 1 recu à la session 1, 2 recu a la session 2)
 */
int estRecu(TEtudiant* etudiant);

#endif