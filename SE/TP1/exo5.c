#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

const int DEBUG = 1;

/**
 * Print messages if DEBUG = 1
 */ 
void debug (char* message){
	if(DEBUG == 1){
		printf("[DEBUG] %s\n",message);
	}
}

/**
 * Replace the last character of a string by 'o'
 */
void replace(char* input){
	int strSize = strlen(input);
	input[strSize-1] = 'o';
}


int main (int argc, char *argv[]){


	/* Check if the number of parmeters is correct */
	debug("Check if correct number of params");
	if(argc < 2){
		printf("Une liste de fichiers .c est nécessaire\n");
		return 1;
	}
	debug("End of check");




	/* Creates all the object files */
	debug("Loop and fork on files in order to generate the object file.");
	for(int i = 1; i < argc; i++){
		pid_t pid = fork();
		if(pid == -1){
			printf("Fork failed. Exiting.");
			exit(1);
		}
		if(pid == 0){
			char* argv2[4];
			argv2[0] = "gcc";
			argv2[1] = "-c";
			argv2[2] = argv[i];
			argv2[3] = NULL;
			execvp("gcc", argv2);
			printf("Compilation failed. Exiting.");
			exit(2);
		}
		else{
			waitpid(pid,NULL,0);
		}

	}
	debug("End of the loop");






	/* Creates the params for compilation */
	debug("Creation of gcc args list");
	char* paramsGcc[argc+3];
	paramsGcc[0] = "gcc";
	for(int i = 1; i < argc; i++){
		paramsGcc[i] = argv[i];
		debug(paramsGcc[i]);
		replace(paramsGcc[i]);
	}
	paramsGcc[argc] = "-o";
	paramsGcc[argc+1] = "output";
	paramsGcc[argc+2] = NULL;
	debug("Creation of gcc args list terminated");



	/* Assembly the object files and generates an output program */
	debug("Creation of the executable file.");
	execvp("gcc",paramsGcc);
	printf("FAILED");
	

}