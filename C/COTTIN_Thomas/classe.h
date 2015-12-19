#ifndef _CLASSE_H
#define _CLASSE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "etudiant.h"

/**
 *	Structure représentant la classe Classe
 **/
typedef struct TClasse_s{
	char* nom;
	TEtudiant** etudiants;
	int nbEtuMax;
	int nbEtu;
} TClasse;

/**
 * Constructeur : 
 *		char* nom : nom de la classe
 *		int nbEtu : nombre d'étudiants
 */
TClasse* creerClasse(char* nom, int nbEtuMax);

/**
 * Destructeur : 
 *		char* nom : nom de la classe-
 */
void supprimerClasse(TClasse** classe);

/**
 * Cherche si un étudiant est présent dans la classe
 *		TClasse classe : la classe dans laquelle il faut chercher l'étudiant
 *		char* nom : le nom de l'étudiant à chercher
 *		char* prenom : le prenom de l'étudiant à chercher
 */
int chercherEtudiant(TClasse* classe, char* nom, char* prenom);

/**
 * Ajout un étudiant à la classe si elle n'est pas complète et retourne l'adresse de l'étudiant ajouté.
 *		TClasse classe : la classe dans laquelle il faut ajouter l'étudiant
 *		char* nom : le nom de l'étudiant à ajouter
 *		char* prenom : le prenom de l'étudiant à ajouter
 */
TEtudiant* ajouterEtudiant(TClasse* classe, char* nom, char* prenom);

/**
 * Supprime un étudiant de la classe et supprime l'objet étudiant associé.
 *		TClasse classe : la classe dans laquelle il faut supprimer l'étudiant
 *		char* nom : le nom de l'étudiant à supprimer
 *		char* prenom : le prenom de l'étudiant à supprimer
 */
int enleverEtudiant(TClasse* classe, char* nom, char* prenom);

/**
 * Lit la liste des étudiants présents dans le fichier "nom_classe.txt" et ajoute les étudiants à la classe. S'ils existent, modifie les existants.
 * 		TClasse classe : la classe.
 */
int lireClasse(TClasse* classe);

#endif