#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>


int main (int argc, char** argv){

	// On créé les tableaux dont on aura besoin pour lancer les exec
	char* params_who[2];
	char* params_ps[2];
	char* params_ls[3];

	pid_t pid_fork_1, pid_fork_2;

	params_who[0]="who"; params_who[1]=NULL;
	params_ps[0]="ps"; params_ps[1]=NULL;
	params_ls[0]="ls"; params_ls[1]="-l"; params_ls[2]=NULL;

	
	pid_fork_1 = fork();
	if(pid_fork_1 == -1){
		printf("Fork WHO failed\n");
		return -1;
	}
	else if(pid_fork_1 == 0){
		execvp(params_who[0], params_who);
	}
	else{
		pid_fork_2 = fork();
		if(pid_fork_2 == -1){
			printf("Fork PS failed\n");
		}
		else if(pid_fork_2 == 0){
			execvp(params_ps[0], params_ps);
		}
		else{
			execvp(params_ls[0], params_ls);
		}
	}
}