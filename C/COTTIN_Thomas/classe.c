#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "classe.h"


/**
 * Constructeur
 */
TClasse* creerClasse(char* nom, int nbEtu){
	TClasse* classe = (TClasse*) malloc(sizeof(TClasse));
	classe->nom = malloc(strlen(nom)*sizeof(char)+1);
	classe->etudiants = malloc(nbEtu)*sizeof(TEtudiant));
	strcpy(classe->nom, nom);
	classe->nbEtu = nbEtu;
	return classe;
}

/**
 * Destructeur
 */
void supprimerClasse(TClasse* classe){
	if( classe != NULL){
		if(classe->nom != NULL)
			free(classe->nom);
		if(classe->etudiants != NULL){
			int j;
			for(j=0; j<nbEtu; ++j)
				supprimerEtudiant(classe->etudiants[j]);
			free(classe->etudiants);
		}
		free(classe);
	}
}

/**
 * Cherche si un étudiant est présent dans la classe
 *		TClasse classe : la classe dans laquelle il faut chercher l'étudiant
 *		char* nom : le nom de l'étudiant à chercher
 *		char* prenom : le prenom de l'étudiant à chercher
 */
int chercherEtudiant(TClasse* classe, char* nom, char* prenom){
	int j;
	for(j=0; j<nbEtu; ++j)
		if(strcmp(classe->etudiants[j]->nom,nom) == 0 && strcmp(classe->etudiants[j]->prenom,prenom) == 0 )
			return j;
	return NULL;
}