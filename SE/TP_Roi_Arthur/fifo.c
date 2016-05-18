#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include "fifo.h"

FileAttente *initialiser(){
    FileAttente *fa = malloc(sizeof(*fa));
    fa->premier = NULL;
    fa->size = 0;
    return fa;
}

void enfiler(FileAttente *file, pthread_t pecore){

    Pecore *aAjouter = malloc(sizeof(*aAjouter));
    aAjouter->pecore = pecore;
    aAjouter->suivant = NULL;

    if(file->premier == NULL){
        file->premier = aAjouter;
    }else{
        Pecore *actuel = file->premier;
        while(actuel->suivant != NULL)
            actuel = actuel->suivant;
        actuel->suivant = aAjouter;
    }
    file->size = (file->size)+1; 
}

pthread_t defiler(FileAttente *file){
    Pecore *aRetirer = file->premier;
    pthread_t thread = aRetirer->pecore;
    file->premier = aRetirer->suivant;
    file->size = (file->size)-1;
    free(aRetirer);
    return thread;
}

void afficher(FileAttente *file){
    Pecore *position = file->premier;
    while (position != NULL){
        printf("%d\n", (int)(position->pecore));
        position = position->suivant;
    }
    printf("\n");
}

int estDansLaFile(FileAttente *file, pthread_t thread){
    int estDedans = 0;
    Pecore *position = file->premier;
    while(estDedans == 0 && position != NULL){
        if(position->pecore == thread)
            estDedans = 1;
        position = position->suivant;
    }
    return estDedans;
}