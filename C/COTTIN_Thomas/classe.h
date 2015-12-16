#ifndef _CLASSE_H
#define _CLASSE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 *	Structure représentant la classe Classe
 **/
typedef struct struct TClasse_s{
	char* nom;
	TEtudiant** etudiants;
	int nbEtu;
} TClasse;

/**
 * Constructeur : 
 *		char* nom : nom de la classe
 *		int nbEtu : nombre d'étudiants
 */
TClasse* creerClasse(char* nom, int nbEtu);

/**
 * Destructeur : 
 *		char* nom : nom de la classe-
 */
void supprimerClasse(TClasse* classe);

/**
 * Cherche si un étudiant est présent dans la classe
 *		TClasse classe : la classe dans laquelle il faut chercher l'étudiant
 *		char* nom : le nom de l'étudiant à chercher
 *		char* prenom : le prenom de l'étudiant à chercher
 */
int chercherEtudiant(TClasse* classe, char* nom, char* prenom);











#endif