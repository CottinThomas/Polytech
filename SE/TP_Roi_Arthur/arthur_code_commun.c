#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include <semaphore.h>


enum etat_arthur {ATTENTE, RENDRE_JUSTICE, GRAAL, APPELER_MERLIN}

sem_t demanderJustice; // 3
sem_t rendreJustice;
sem_t chevalierDispo; // 11
sem_t readyForGraal;



void *arthur (void* arg){
    while(1){
        /*
            SI SEM_GETVALUE(CHEVALIERDISPO) == 11
                APPELERMERLIN()
            SI SEM_GETVALUE(DEMANDERJUSTICE) == 3
                RENDREJUSTICE()
        */
    }
}


void *pecore (void* arg)
{
    sem_wait(&demanderJustice);
    // executer EtreJuger()
    sem_post(&demanderJustice);
   

    sem_post(&arthur);
    pthread_exit(NULL);
}


void *chevalier (void* arg)
{
    sleep(rand()%10);
    sem_wait(&arthur);

   

    sem_post(&arthur);

    sem_wait(&arthur);

    // si sem_getvalue(readyForGraal) == 1 executer chercherGraal()

    pthread_exit(NULL);
}



int main(int argc, char** argv){
	


    return 0;
}