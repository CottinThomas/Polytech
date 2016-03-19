#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

#define DEBUG_MODE 0


void debug(char* message){
	if(DEBUG_MODE==1){
		printf("[DEBUG] %s\n",message);
	}
}

/**
 * Le programme lance la commande passée en paramètre.
 */
int main (int argc, char** argv){

	// Il faut que argv contienne au minimum le nom de ce programme, puis la commande à lancer (donc taille 2)
	if(argc < 2){
		printf("Un paramètre (commande) est nécessaire\nSyntaxe : myexec commande [param1 ... paramn]\n");
		return 1;
	}

	// On crée un nouveau tableau de chaîne afin de stocker les arguments que lon souhaite envoyer.
	// Pour rappel, argv contiens dans sa premiere case la commande, puis après la liste de ses paramètre
	char* argv2[argc-1];

	// Fonction de string.h permettant de copier dans argv2 le contenu de argv décalé de une case.
	memcpy(argv2, argv+sizeof(char), sizeof(argv2));

	// On met NULL dans la dernière case. Pourquoi ? Don't know, une convention pour s'assurer de ne pas sortir je pense...
	argv2[argc-1] = NULL;

	for(int i = 0; i < argc-1; i++){
		debug(argv2[i]);
	}
	
	// On lance la commande passée en paramètre avec ses propres paramètres
	execvp(argv[1],argv2);

	// Ce text serra uniquement affiché si exec plante, car pas de retour.
	printf("Il y a eu un problème.\n");
	exit(0);
}
