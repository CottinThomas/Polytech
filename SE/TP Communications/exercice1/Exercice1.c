#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

# define STDOUT 1

int main (int argc, char** argv){

	int out;
	out = open("out", O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
	dup2(out, STDOUT);
	char* args[] = {"ls", NULL};
	close(out);
	execvp("ls", args);
	return 0;

}