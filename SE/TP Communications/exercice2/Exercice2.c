#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



int main (int argc, char** argv){

	if(argc != 2){
		printf("ERREUR NOMBRE DE PARAMS\n");
		return 2;
	}
	
	pid_t process;

	process = fork();

	if(process == -1){
		printf("FORK FAILED\n");
		exit(1);
	}
	else if(process == 0){
		int out;
		out = open("/dev/null", O_WRONLY);
		dup2(out, 1);
		close(out);
		char* args[] = {argv[1], NULL};
		execvp(argv[1],args);
	}
	else{
		int ret;
		waitpid(process, &ret, 0);
		if(WEXITSTATUS(ret) == 0){
			printf("OK\n");
		}
		else{
			printf("ERREUR\n");
		}
	}
	return 0;

}