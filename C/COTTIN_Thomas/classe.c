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
	char* fileName = malloc(strlen(classe->nom)+12*sizeof(char));
	strcpy(fileName, classe->nom);
	strcat(fileName,".import.txt\0");
    fichier = fopen(fileName, "r");
    free(fileName);
    if(fichier != NULL){
    	char ligne[ 128 ]; /* or other suitable maximum line size */
 		while(fgets(ligne, sizeof(ligne), fichier) != NULL ){
 			int tailleLigne = sizeof(ligne);
 			char* nom = strtok(ligne,",");
 			char* prenom = strtok(NULL,",");
 			char* temp = strtok(NULL,",");
 			float notePartiel = atof(temp);
 			if(temp==NULL)
 				notePartiel = -1.0;
 			temp = strtok(NULL,",");
 			float noteCC = atof(temp);
 			if(temp==NULL)
 				noteCC = -1.0;
 			temp = strtok(NULL,",");
 			float noteExam1 = atof(temp);
 			if(temp==NULL)
 				noteExam1 = -1.0;
 			temp = strtok(NULL,",");
 			float noteExam2 = atof(temp);
 			if(temp==NULL)
 				noteExam2 = -1.0;
 			int pos = chercherEtudiant(classe, nom, prenom);
 			if(pos == -1){
 				ajouterEtudiant(classe,nom,prenom);
 				pos = chercherEtudiant(classe, nom, prenom);
 			}
 			if(pos != -1){
 				classe->etudiants[pos]->notePartiel = notePartiel;
 				classe->etudiants[pos]->noteCC = noteCC;
 				classe->etudiants[pos]->noteExam1 = noteExam1;
 				classe->etudiants[pos]->noteExam2 = noteExam2;
 			}
	    }
	    fclose ( fichier );
    }
    else 
    	printf("erreur\n");
    return 0;
}

/**
 * Ecrit la liste des étudiants présents dans le fichier "nom_classe.txt".
 * 		TClasse classe : la classe.
 */
int ecrireClasse(TClasse* classe){
	if (classe == NULL){
		return -1;
	}
	FILE* fichier = NULL;
	char* fileName = malloc(strlen(classe->nom)+13*sizeof(char));
	strcpy(fileName, classe->nom);
	strcat(fileName,".extract.txt\0");
	fichier = fopen(fileName, "w+");
	free(fileName);
	if(fichier != NULL){
		char* buffer = malloc(256*sizeof(char));
		sprintf(buffer,"Nom de la classe : %s\nNombre d'élèves maximum : %d / Nombre d'élèves actuels : %d\nListe des élèves :\n\n",
			classe->nom,
			classe->nbEtuMax,
			classe->nbEtu);
		fputs(buffer,fichier);
		int j;
		for(j = 0; j < classe->nbEtu; ++j){
			buffer[0] = '\0';
			sprintf(buffer,"\tNom : %s\t\tPrénom : %s\n",
				classe->etudiants[j]->nom,
				classe->etudiants[j]->prenom);
			fputs(buffer,fichier);
			if(classe->etudiants[j]->notePartiel != -1){
				sprintf(buffer, "\t\tNote partiel : %2.1f\n", classe->etudiants[j]->notePartiel);
				fputs(buffer, fichier);
			}
			if(classe->etudiants[j]->noteCC != -1){
				sprintf(buffer, "\t\tNote contrôle continu : %2.1f\n", classe->etudiants[j]->noteCC);
				fputs(buffer, fichier);
			}
			if(classe->etudiants[j]->noteExam1 != -1){
				sprintf(buffer, "\t\tNote au premier examen : %2.1f\n", classe->etudiants[j]->noteExam1);
				fputs(buffer, fichier);
			}
			if(classe->etudiants[j]->noteExam2 != -1){
				sprintf(buffer, "\t\tNote au second examen : %2.1f\n", classe->etudiants[j]->noteExam2);
				fputs(buffer, fichier);
			}
			float nps = getNotePremiereSession(classe->etudiants[j]);
			if(nps > -1){
				sprintf(buffer, "\t\tNote à la première session : %2.1f\n", nps);
				fputs(buffer,fichier);
				if(nps >= 10){
					sprintf(buffer, "\t\t[RECU A LA PREMIERE SESSION - Note finale : %2.1f]\n\n", nps);
					fputs(buffer, fichier);
				}
				else{
					float nss = getNoteDeuxiemeSession(classe->etudiants[j]);
					if(nss > -1){
						sprintf(buffer, "\t\tNote à la seconde session : %2.1f\n", nss);
						fputs(buffer, fichier);
						if(nss >= 10){
							sprintf(buffer, "\t\t[RECU A LA SECONDE SESSION - Note finale : %2.1f]\n\n", nss);
							fputs(buffer, fichier);
						}
						else {
							sprintf(buffer, "\t\t[NON RECU - Note finale : %2.1f]\n\n", getNoteFinale(classe->etudiants[j]));
							fputs(buffer, fichier);
						}
					}
				}
			}
		}
	}
	fclose(fichier);

	return 0;
}

/**
 * Classe les étudiants par ordre de mérite
 * 		TClasse classe : la classe.
 */
 int classer(TClasse* classe){
 	if (classe == NULL){
		return -1;
	}
	afficherClasse(classe);
	int n = classe->nbEtu;
	int i;
	for(i = n-1; i >= 1; i--){
		int j;
		for(j = 0; j <i; ++j){
			if(getNoteFinale(classe->etudiants[j]) < getNoteFinale(classe->etudiants[j+1])){
				TEtudiant tmp = *(classe->etudiants[j]);
				*(classe->etudiants[j])=*(classe->etudiants[j+1]);
				*(classe->etudiants[j+1]) = tmp;
			}
		}
	}
	afficherClasse(classe);
	return 0;
 }

/**
 * Fonction permettant un affichage formaté des classes. Utile pour les tests.
 *		TClasse* classe : la classe à afficher
 */
void afficherClasse(TClasse* classe){
	if(classe == NULL)
		printf("La classe n'existe pas\n");
	else{
		printf("Classe : %s\n", classe->nom);
		printf("Nombre d'élèves max : %d / nombre d'élève actuel : %d\n", classe->nbEtuMax, classe->nbEtu);
		printf("Liste des élèves de la classe :\n");
		int j;
		for(j = 0; j < classe->nbEtu; ++j)
			afficherEtudiant(classe->etudiants[j]);
	}
}


