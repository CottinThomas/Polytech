#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "etudiant.h"
#include "classe.h"
#include "main.h"



int main (int argc, const char * argv[]){


	printf("CREATION D'UN ETUDIANT - TEST DES DIFFERENTES FONCTIONS\n\n");

	TEtudiant* etu = creerEtudiant("NOM", "Prenom");
	printf("L'étudiant %s %s a été créé.\n", etu->prenom, etu->nom);

	setNote(etu, 18.2, NOTE_PARTIEL);
	printf("Note au partiel: %2.1f\n", getNote(etu, NOTE_PARTIEL));

	setNote(etu, 11.4, NOTE_CC);
	printf("Note au CC: %2.1f\n", getNote(etu, NOTE_CC));

	setNote(etu, 5.3, NOTE_EXAM1);
	printf("Note au premier examen: %2.1f\n", getNote(etu, NOTE_EXAM1));

	printf("L'étudiant %s %s à pour résultat à la première session %2.1f\n", etu->prenom, etu->nom, getNoteFinale(etu));

	switch(estRecu(etu)){
		case 0:
			printf("L'étudiant %s %s n'est pas reçu.", etu->prenom, etu->nom);
			break;
		case 1:
			printf("L'étudiant %s %s est recu à la première session.\n", etu->prenom, etu->nom);
			break;
		case 2:
			printf("L'étudiant %s %s est recu à la deuxième session.\n", etu->prenom, etu->nom);
			break;
	}

	printf("Suppression de l'étudiant %s %s\n", etu->prenom, etu->nom);
	supprimerEtudiant(&etu); // passage de l'adresse du pointeur pour mise a null


	float note = getNote(etu, NOTE_PARTIEL);
	if(note == -2)
		printf("L'étudiant spécifié n'existe pas");
	else if(note == -1)
		printf("La note de partiel de %s %s n'a pas été rentrée\n", etu->nom, etu->prenom);
	else if(note>=0)
		printf("La note de partiel de %s %s est %2.1f/20\n", etu->nom, etu->prenom, note);
	else
		printf("La fonction a retournée un code erreur inconnu\n");


	printf("\n\n\nCREATION D'UNE CLASSE - TEST DES DIFFERENTES FONCTIONS\n\n");

	TClasse* classe = creerClasse("Ma Classe", 5);
	ajouterEtudiant(classe,"NOMA","PrenomA");
	if(chercherEtudiant(classe,"NOMA","PrenomA") >= 0)
		printf("L'étudiant est dans la classe.\n");
	else
		printf("L'étudiant n'est pas dans la classe.\n");

	enleverEtudiant(classe, "NOMA", "PrenomA");
	if(chercherEtudiant(classe,"NOMA","PrenomA") >= 0)
		printf("L'étudiant  est dans la classe.\n");
	else
		printf("L'étudiant n'est pas dans la classe.\n");

	ajouterEtudiant(classe, "NOM1", "Prenom1");
	int pos = chercherEtudiant(classe,"NOM1", "Prenom1");
	if(pos >=0){
		setNote(classe->etudiants[pos], NOTE_PARTIEL, 2);
		setNote(classe->etudiants[pos], NOTE_CC, 8);
	}


	printf("\n\nEtat actuel de la classe\n");
	afficherClasse(classe);

	printf("\nAjouts d'étudiants depuis un fichier\n");
	lireClasse(classe);

	printf("\nEtat actuel de la classe\n");
	afficherClasse(classe);

	printf("\nTri des étudiants de la classe par ordre décroissant de note\n");
	classer(classe);

	printf("\nEtat actuel de la classe\n");
	ecrireClasse(classe);

	printf("\nSuppression de la classe\n");
	supprimerClasse(&classe);

	if(classe==NULL)
		printf("La classe a bien été supprimée\n");

	printf("\n");
	return 0;
}