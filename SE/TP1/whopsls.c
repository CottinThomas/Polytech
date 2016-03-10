#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>


int main (int argc, char** argv){

	char* params_who[2];
	char* params_ps[2];
	char* params_ls[3];

	pid_t pid_fork_who;
	pid_t pid_fork_ps;
	pid_t pid_fork_ls;

	params_who[0]="who"; params_who[1]=NULL;
	params_ps[0]="ps"; params_ps[1]=NULL;
	params_ls[0]="ls"; params_ls[1]="-l"; params_ls[2]=NULL;

	
	pid_fork_who = fork();
	if(pid_fork_who == -1){
		printf("Fork WHO failed\n");
		return -1;
	}
	else if (pid_fork_who == 0){
		execvp("who",params_who);
	}
	else{
		waitpid(pid_fork_who, NULL, 0);
		pid_fork_ps = fork();
		if(pid_fork_ps == -1){
			printf("Fork PS failed\n");
		}
		else if(pid_fork_ps == 0){
			execvp("ps", params_ps);
		}
		else{
			waitpid(pid_fork_ps, NULL, 0);
			pid_fork_ls = fork();
			if(pid_fork_ls == -1){
				printf("Fork LS failed\n");
			}
			else if(pid_fork_ls == 0){
				execvp("ls", params_ls);
			}
			else{
				waitpid(pid_fork_ls, NULL, 0);
				printf("Fini.\n");
			}
		}
	}

}