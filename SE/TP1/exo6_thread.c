#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void *killproc(pid_t pid){
	printf("Je suis %d, je vais tuer %d\n", getpid(), pid );
	kill(pidfils1, SIGTERM);
}

int main (int argc, char *argv[]){
	printf("Je suis le père, pid %d", gepid());
	pthread_t fils1, fils2;
	pthread_create(&fils1,NULL,killproc,getpid());
	pthread_create(&fils2,NULL,killproc,fils1);


}