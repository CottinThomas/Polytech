#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>



int main (int argc, char *argv[]){

	if(argc < 2){
		printf("Un paramètre est nécessaire\n");
		return 1;
	}

	int val = atoi(argv[1]);
	int ret;

	pid_t pidf1 = fork();

	if(pidf1 == -1){
		printf("Fork failed\n");
		return -1;
	}
	else if(pidf1 == 0){
		//printf("C'est le fils\n");
		for(int i = 1; i<=val/2; i++){
			printf("%d\t", i);
		}
	}
	else {

		waitpid(pidf1,&ret,0);
		pid_t pidf2 = fork();
		if(pidf2 == -1){
			printf("Fork failed\n");
			return -1;
		}
		else if(pidf2 == 0){
			for(int i = val/2+1; i<=val; i++){
				printf("%d\t", i);
			}
		}
		else{
			waitpid(pidf2,&ret,0);
			printf("\n");
		}
	}
}