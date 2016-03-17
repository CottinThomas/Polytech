#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pthread.h>



void *premier_fils(void* arg){
	pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	pthread_setcancelstate(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
	pthread_t pere= *((pthread_t*)arg);
	sleep(5);
	printf("Je suis %d\n", (int)pthread_self());
	printf("Je tue mon pere !\n");
	pthread_cancel(pere);
	printf("KILLED\n");
	return 0;
}

void *second_fils(void* arg){
	pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	pthread_setcancelstate(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
	pthread_t fils1= *((pthread_t*)arg);
	sleep(5);
	printf("Je suis %d\n", (int)pthread_self());
	printf("Je tue mon frere !\n");
	pthread_cancel(fils1);
	printf("KILLED\n");
	return 0;
}

void *familly(void* args){
	printf("Création des fils\n");
	pthread_t* mesFils = (pthread_t*) args;
	pthread_t moi = pthread_self();
	pthread_create(&(mesFils[0]),NULL,premier_fils,(void*)&moi);
	sleep(2);
	pthread_create(&(mesFils[1]),NULL,second_fils,(void*)&mesFils[0]);
	printf("Moi, pere %d, j'ai créé %d et %d\n",(int)pthread_self(), (int)mesFils[0], (int)mesFils[1]);
	return 0;
}

int main (int argc, char *argv[]){
	pthread_t pere;
	pthread_t fils[2];
	pthread_create(&pere,NULL,familly,(void*)&fils);
	pthread_join(pere, NULL);
	pthread_join(fils[0], NULL);
	pthread_join(fils[1],NULL);
	sleep(3);
	exit(0);
}