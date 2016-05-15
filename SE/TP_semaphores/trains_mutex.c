
//gcc -Wall -pthread fichier.c

#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

pthread_mutex_t tunnel;


void *train(void* arg)
{
	sleep(rand()%10);
    pthread_mutex_lock(&tunnel);

    printf("Moi, %s, j'entre dans le tunnel\n", (char*)arg);

    sleep(2);

    pthread_mutex_unlock(&tunnel);

    printf("Moi, %s, je sors du tunnel\n", (char*)arg);

    pthread_exit(NULL);
}


int main(int argc, char** argv)
{
	pthread_t threads[15];
	time_t t;
	srand((unsigned)time(&t));
    pthread_mutex_init(&tunnel, NULL);

    int i;
    char name[20][20];

    for(i = 0; i<15; i++){
    	int random = rand()%4;
    	switch(random){
    		case(0):
    			sprintf(name[i], "RER B %d", i);
    			break;
    		case(1):
    			sprintf(name[i], "RER D %d", i);
    			break;
    		case(2):
    			sprintf(name[i], "RER E %d", i);
    			break;
    		case(3):
    			sprintf(name[i], "Transilien SD %d", i);
    			break;
    	}
    	pthread_create(&threads[i], NULL, train, (void*)name[i]);
    }

    for(i = 0; i<15; i++){
    	pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&tunnel);

    return 0;
}