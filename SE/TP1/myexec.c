#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>



int main (int argc, char** argv){

	if(argc < 2){
		printf("Un paramètre (commande) est nécessaire\n");
		return 1;
	}

	char* argv2[argc-1];

	memcpy(argv2, argv+1, sizeof argv2);

	argv2[argc-1] = NULL;
	
	execvp(argv[1],argv2);
}