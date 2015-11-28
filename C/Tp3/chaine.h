/* ---------------- */
/* --- chaine.h --- */
/* ---------------- */

#ifndef _CHAINE_H_
#define _CHAINE_H_ 

// mode debug: activer le define ci-dessous
#define ENABLE_CHAINE_VERBOSE
#ifdef ENABLE_CHAINE_VERBOSE
#define CHAINE_VERBOSE(X) X
#else
#define CHAINE_VERBOSE(X)
#endif

// ne pas changer les valeurs
#define MALLOC_ERROR "malloc error"
#define BUFFER_TOO_SMALL "buffer too small"

#define BUFFER_SIZE 32

void arabe_romain_table(int n);
void arabe_romain_calc(int n);

char* str_end(char *str);
int   str_len(char *str);
char* str_dup(char *str);
char *str_cat(char *dst, char *str);
char* str_ndupchar(char* dst, char c, int n);

int int_len(int x);
char* i2str(int x);
char* ic2str(int x, char c);

char* str_count(char *str, char *c, int *count);

int is_palyndrome1(char *str);
int is_palyndrome2(char *str);

char* commentaire(char *str);
char* commentaire_itere(char *str, int iter);

#endif
