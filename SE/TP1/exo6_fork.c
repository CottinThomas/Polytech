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
		sleep(1);
		printf("[%d] et je vais tuer mon pere !\n",getpid());
		kill(getppid(),SIGTERM);
		printf("[%d] AHAHA ! IL EST MOOOOOOORT !!!!\n",getpid());
		while(1);
	}
	else{
		printf("[%d] J'ai un fils ! Il s'appel %d\n",getpid(),pidfils1);
		pidfils2 = fork();
		if(pidfils2 == -1){
			printf("FORK FAILED\n");
			exit(2);
		}
		else if(pidfils2 == 0){
			sleep(5);
			printf("[%d] NOOOOOON ! Vangeance ! Je vais tuer mon frere !\n",getpid());
			kill(pidfils1, SIGTERM);
			printf("[%d] %d est mort ! Il ne me reste plus qu'a me suicider ! ",getpid(),pidfils1);
		}
		else{
			printf("[%d] J'ai de nouveau un fils ! Il s'appel %d\n",getpid(),pidfils2);
			while(1);
		}
	}
	exit(0);
}