#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include <semaphore.h>
#include "fifo.h"

sem_t chevalierDispo; // 11
sem_t readyForGraal;
sem_t justiceRendue;

FileAttente *attenteJugement;


void appelerMerlin(){
    printf("\x1B[32m[Arthur] : Merlin arrive ! *Aaaaaaaaw* Apparition inexpliquée !\n");
}

void rendreJustice(){
    printf("\x1B[32m[Arthur] : je rends la justice !\n");
    sem_wait(&justiceRendue);
    defiler(attenteJugement);
    sleep(rand()%2);
    defiler(attenteJugement);
    sleep(rand()%2);
    defiler(attenteJugement);
    sleep(rand()%2);
    printf("\x1B[32m[Arthur] : la justice est rendue!\n");
    sem_post(&justiceRendue);
}

void nobleQuete(char* nom){
    printf("\x1B[34m[%s] : je pars réaliser une noble quête !\n", nom);
    sleep(rand()%10);
    printf("\x1B[34m[%s] : Ma quête est finie, j'attend le roi !\n", nom);
    sem_wait(&chevalierDispo);
}

void chevalierChercherGraal(char* nom){
    printf("\x1B[34m[%s] : je pars chercher le Graal !\n", nom);
    sleep(rand()%10);
    printf("\x1B[34m[%s] : toujours pas de Graal !\n", nom);
    sem_post(&chevalierDispo);
}

void etreJuge(char* nom){
    printf("\x1B[37m[%s] : je suis jugé !\n", nom);
    // printf("\x1B[37m[%s] : je suis en train d'être jugé !\n", nom);
    // int count;
    // sem_getvalue(&justiceRendue, &count);
    // while(count==1)
    //     sem_getvalue(&justiceRendue, &count);
    // printf("\x1B[37m[%s] : la sentence est rendue !\n", nom);
}

void *arthur (void* arg){
    while(1){
        int nombreDeChevaliersDisponibles;
        sem_getvalue(&chevalierDispo, &nombreDeChevaliersDisponibles);
        int count;
        sem_getvalue(&readyForGraal, &count);
        if(count==1){
            if(nombreDeChevaliersDisponibles == 0){
                
                appelerMerlin();
                sem_wait(&readyForGraal);

                sem_getvalue(&chevalierDispo, &nombreDeChevaliersDisponibles);
                while(nombreDeChevaliersDisponibles != 11) {
                    sleep(rand()%5);
                   printf("\x1B[32m[Arthur] : %d chevalierDispo.\n", nombreDeChevaliersDisponibles);
                   sem_getvalue(&chevalierDispo, &nombreDeChevaliersDisponibles);
               }    

                printf("\x1B[32m[Arthur] : Toujours pas de Graal... Foutue mission divine.\n");

                sem_post(&readyForGraal);
            }
        }
        if(attenteJugement->size >= 3){
            rendreJustice();
        }
    }    
    pthread_exit(NULL);
}


void *pecore (void* arg){
    pthread_t threadId = pthread_self();
    printf("\x1B[37m[%s] : Je demande à être jugé !\n", (char*)arg);
    enfiler(attenteJugement, threadId);
    printf("\x1B[37m[%s] : J'attend mon jugement !\n", (char*)arg);
    while(estDansLaFile(attenteJugement, threadId)==1);
    etreJuge((char*)arg);
    pthread_exit(NULL);
}


void *chevalier (void* arg){
    nobleQuete((char*)arg);
    int isReadyForGraal;
    sem_getvalue(&readyForGraal, &isReadyForGraal);
    while(isReadyForGraal!=0)
        sem_getvalue(&readyForGraal, &isReadyForGraal);
    chevalierChercherGraal((char*)arg);
    pthread_exit(NULL);
}



int main(int argc, char** argv){

    time_t t;
    srand((unsigned)time(&t));

    pthread_t chevaliers_t[11];
    pthread_t pecore_t[7];
    pthread_t arthur_t;

    char* nomsChevalier[] = {"Bohort", "Calogrenant", "Karadoc", "Dagonet", "Galessin", "Gauvain", "Hervé de Rinel", "Lancelot", "Léodagan", "Perceval", "Yvain"};
    char* nomsPecores[] = {"Guethenoc", "Roparzh", "Pecore En plus 1", "Pecore En plus 2", "Pecore En plus 3", "Pecore En plus 4", "Pecore En plus 5"};

    sem_init(&chevalierDispo, 0, 11);
    sem_init(&readyForGraal, 0, 1);
    sem_init(&justiceRendue, 0, 1);

    attenteJugement = initialiser();

    for(int i=0; i<11; i++){
        pthread_create(&chevaliers_t[i], NULL, chevalier, (void*)nomsChevalier[i]);
    }
    for(int i = 0; i<6; i++){
        pthread_create(&pecore_t[i], NULL, pecore, (void*)nomsPecores[i]);
    }
    pthread_create(&arthur_t, NULL, arthur, NULL);


    pthread_join(arthur_t, NULL);
    for(int i=0; i<11; i++){
        pthread_join(chevaliers_t[i], NULL);
    }
    for(int i = 0; i<6; i++){
        pthread_join(pecore_t[i], NULL);
    }
    sem_destroy(&chevalierDispo);
    sem_destroy(&readyForGraal);
    sem_destroy(&justiceRendue);
    return 0;
}