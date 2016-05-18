#ifndef H_FIFO
#define H_FIFO

typedef struct Pecore Pecore;
struct Pecore{
    pthread_t pecore;
    Pecore *suivant;
};

typedef struct FileAttente FileAttente;
struct FileAttente{
    Pecore *premier;
    int size;
};

FileAttente *initialiser();
void enfiler(FileAttente *file, pthread_t thread);
pthread_t defiler(FileAttente *file);
void afficher(FileAttente *file);
int estDansLaFile(FileAttente *file, pthread_t thread);

#endif