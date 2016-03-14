#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main (int argc, char *argv[]){

	pid_t pidfils1, pidfils2;

	pidfils1 = fork();

	if(pidfils1 == -1){
		printf("FORK FAILED\n");
		exit(1);
	}
	else if(pidfils1 == 0){
		printf("Je suis %d et je vais tuer mon pere !\n",getpid());
		kill(getppid(),SIGTERM);
	}
	else{
		printf("Premier fils créé, pid = %d\n",pidfils1);
		pidfils2 = fork();
		if(pidfils2 == -1){
			printf("FORK FAILED\n");
			exit(2);
		}
		else if(pidfils2 == 0){
			printf("Je suis %d et je vais tuer mon frere !\n",getpid());
			kill(pidfils1, SIGTERM);

		}
		else{
			printf("Second fils créé; pid = %d\n",pidfils2);
		}
	}
}