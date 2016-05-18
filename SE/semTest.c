#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include <semaphore.h>


int main(int argc, char** argv){

    time_t t;
    srand((unsigned)time(&t));

    sem_t mySem;

    sem_init(&mySem, 0, 3);
    int count;
    sem_getvalue(&mySem, &count);

    printf("Le sémaphore est pris %d fois.\n", count);

    sem_wait(&mySem);
    sem_getvalue(&mySem, &count);
    printf("Le sémaphore est pris %d fois.\n", count);

    sem_post(&mySem);
    sem_destroy(&mySem);
    return 0;
}
