#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "classe.h"
#include "etudiant.h"


/**
 * Constructeur : 
 *		char* nom : nom de la classe
 *		int nbEtu : nombre d'étudiants
 */
TClasse* creerClasse(char* nom, int nbEtuMax){
	TClasse* classe = (TClasse*) malloc(sizeof(TClasse));
	classe->nom = malloc(strlen(nom)*sizeof(char)+1);
	classe->etudiants = malloc(nbEtuMax*sizeof(TEtudiant));
	strcpy(classe->nom, nom);
	classe->nbEtuMax = nbEtuMax;
	classe->nbEtu = 0;
	return classe;
}

/**
 * Destructeur : 
 *		char* nom : nom de la classe-
 */
void supprimerClasse(TClasse** classe){
	if( classe[0] != NULL){
		if(classe[0]->nom != NULL)
			free(classe[0]->nom);
		if(classe[0]->etudiants != NULL){
			int j;
			for(j=0; j<classe[0]->nbEtu; ++j)
				supprimerEtudiant(&(classe[0]->etudiants[j]));
			free(classe[0]->etudiants);
		}
		free(classe[0]);
		classe[0] = NULL;
	}
}

/**
 * Cherche si un étudiant est présent dans la classe
 *		TClasse classe : la classe dans laquelle il faut chercher l'étudiant
 *		char* nom : le nom de l'étudiant à chercher
 *		char* prenom : le prenom de l'étudiant à chercher
 */
int chercherEtudiant(TClasse* classe, char* nom, char* prenom){
	if(classe==NULL){
		printf("La classe spécifiée n'existe pas.\n");
		return -2;
	}
	int j;
	for(j=0; j<classe->nbEtu; ++j)
		if(strcmp(classe->etudiants[j]->nom,nom) == 0 && strcmp(classe->etudiants[j]->prenom,prenom) == 0 )
			return j;
	return -1;
}

/**
 * Ajout un étudiant à la classe si elle n'est pas complète et retourne l'adresse de l'étudiant ajouté.
 *		TClasse classe : la classe dans laquelle il faut ajouter l'étudiant
 *		char* nom : le nom de l'étudiant à ajouter
 *		char* prenom : le prenom de l'étudiant à ajouter
 */
TEtudiant* ajouterEtudiant(TClasse* classe, char* nom, char* prenom){
	if(classe==NULL){
		printf("La classe spécifiée n'existe pas.\n");
		return NULL;
	}
	if(classe->nbEtu == classe->nbEtuMax)
		return NULL;
	TEtudiant* etudiant = creerEtudiant(nom,prenom);
	classe->etudiants[classe->nbEtu] = etudiant;
	classe->nbEtu += 1;
	return etudiant;
}

/**
 * Supprime un étudiant de la classe et supprime l'objet étudiant associé.
 *		TClasse classe : la classe dans laquelle il faut supprimer l'étudiant
 *		char* nom : le nom de l'étudiant à supprimer
 *		char* prenom : le prenom de l'étudiant à supprimer
 */
int enleverEtudiant(TClasse* classe, char* nom, char* prenom){
	if(classe == NULL)
		return -2;
	int pos = chercherEtudiant(classe,nom,prenom);
	if(pos == -1)
		return 0;
	supprimerEtudiant(&(classe->etudiants[pos]));
	int j;
	for(j=pos; j<classe->nbEtu-1; ++j)
		classe->etudiants[pos] = classe->etudiants[pos+1];
	classe->nbEtu -= 1;
}

/**
 * Lit la liste des étudiants présents dans le fichier "nom_classe.txt" et ajoute les étudiants à la classe. S'ils existent, modifie les existants.
 * 		TClasse classe : la classe.
 */
int lireClasse(TClasse* classe){
	if (classe == NULL){
		return -1;
	}
	FILE* fichier = NULL;
	char* fileName = malloc(strlen(classe->nom)+4*sizeof(char));
	strcpy(fileName, classe->nom);
	strcat(fileName,".txt");
    fichier = fopen(fileName, "r");
    printf("%s\n", fileName);
    free(fileName);
    /*
    if(fichier != NULL)
    	printf("Fichier ouvert\n");
    else printf("erreur\n");

    fclose(fichier);*/
    return 0;
}