/* ---------------- */
/* --- chaine.c --- */
/* ---------------- */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "chaine.h"


const char* u[10] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
const char* d[10] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
const char* c[10] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
const char* m[5] = {"","M","MM","MMM","MMMM"};

/* ------------------- */
void str_error(char *msg)
/* ------------------- */
{
    printf("String Error: %s\n", msg);
    exit(-1);
}
/* ------------------------ */
void arabe_romain_table(int n)
/* ------------------------ */
{

    if(n<0 || n>4999)
        printf("Nombre trop grand.\n");

    int un,di,ce,mi;
    mi = n/1000;
    ce = (n-mi*1000)/100;
    di = (n-ce*100)/10;
    un = n-di*10;

    printf("%d = %s%s%s%s",n,m[mi],c[ce],d[di],u[un]);

    printf("\n");

}
/* ----------------------- */
void arabe_romain_calc(int n)
/* ----------------------- */
{
    printf("%d = ",n);

    /*
     * GESTION DES MILIERS
     */
    int mi = n/1000;
    n = n - mi*1000;
    for(int i = 0;i<mi;i++){
        printf("M");
    }

    /*
     * GESTION DES CENTAINES
     */

    int ce = n/100;
    n = n - ce*100;

    if(ce == 4 )
        printf("CD");
    else if(ce == 9 )
        printf("CM");
    else {
        if(ce >= 5){
            printf("M");
            ce -= 5;
        }
        for (int i = 0; i < ce; i++){
            printf("C");
        }
    }

    /*
     * GESTION DES DIZAINES
     */
    int di = n/10;
    n = n - di*10;

    if(di == 4 )
        printf("XL");
    else if(di == 9 )
        printf("XC");
    else {
        if(di >= 5){
            printf("L");
            di -= 5;
        }
        for (int i = 0; i < di; i++){
            printf("X");
        }
    }

    /*
     * GESTION DES UNITES
     */

    if(n == 4 )
        printf("IV");
    else if(n == 9 )
        printf("IX");
    else {
        if(n >= 5){
            printf("V");
            n -= 5;
        }
        for (int i = 0; i < n; i++){
            printf("I");
        } 
    }
    /*
     * doit contenir:
     * 1) printf("%d = ", n);
     * 2) l'ensemble des chiffres en romain
     * 3) se terminer par un retour chariot de type puts(""); ou printf("\n");
     */
    
    printf("\n");
}
/* ------------------ */
char* str_end(char *str)
/* ------------------ */
{
    char *end = str;
    while(*end != '\0'){
        end += 1;
    }
    // retourne l'adresse du char nul   
    return end; // a modifier
}
/* ---------------- */
int str_len(char *str)
/* ---------------- */
{
    char *start = str;
    char *end = str_end(str);
    int size=(end-start)/sizeof(char);
    return size; // a modifier
}
/* ------------------ */
char* str_dup(char *str)
/* ------------------ */
{
    char *strDup = malloc(str_len(str));
    char *strToReturn = strDup;
    char *tmp;
    while(*str != '\0'){
        *strDup = *str;
        str += sizeof(char);
        strDup += sizeof(char);
    }
    return strToReturn;
}
/* ------------------------------- */
char* str_cat(char *src1, char *src2)
/* ------------------------------- */
{
    // alloue une zone memoire pour concatener dst et src
    if(src1 == NULL && src2 == NULL) return malloc(sizeof(char));
    if(src1 == NULL){
        char *strToReturn = str_dup(src2);
        return strToReturn;
    }
    if(src2 == NULL){
        char *strToReturn = str_dup(src1);
        return strToReturn;
    }

    char *strCat = malloc(str_len(src1)+str_len(src2));
    char *strToReturn = strCat;
    while(*src1 != '\0'){
        *strCat = *src1;
        src1 += sizeof(char);
        strCat += sizeof(char);
    }
    while(*src2 != '\0'){
        *strCat = *src2;
        src2 += sizeof(char);
        strCat += sizeof(char);
    }
    return strToReturn;
}
/* -------------------------------------- */
char* str_ndupchar(char* dst, char c, int n)
/* -------------------------------------- */
{
    // copie n char c dans dst, sans en modifier l'adresse
    // dst doit etre suffisamment grand
    return NULL; // a modifier
}
/* ------------ */
int int_len(int x)
/* ------------ */
{
    char myNb[10];
    return sprintf(myNb,"%d",x);; // a modifier
}
/* ------------ */
char* i2str(int x)
/* ------------ */
{
    char *result = malloc(int_len(x));
    // USE atoi
    return NULL; // a modifier
}
/* --------------------- */
char* ic2str(int x, char c)
/* --------------------- */
{
    return NULL; // a modifier
}
/* ----------------------------------------- */
char* str_count(char *str, char *c, int *count)
/* ----------------------------------------- */
{
    return NULL; // a modifier
}
/* ----------------------- */
int is_palyndrome1(char *str)
/* ----------------------- */
{
    return 0; // a modifier
}
/* ----------------------- */
int is_palyndrome2(char *str)
/* ----------------------- */
{
    return 0; // a modifier
}
/* ---------------------- */
char* commentaire(char *str)
/* ---------------------- */
{
    // Ne pas oublier de faire un free quand une zone memoire allouee dynamiquement n'est plus utilisee par un pointeur
    // buffer statique interdit
    
    return NULL; // a modifier
}
/* -------------------------------------- */
char* commentaire_itere(char *str, int iter)
/* -------------------------------------- */
{
    // Ne pas oublier de faire un free quand une zone memoire allouee dynamiquement n'est plus utilisee par un pointeur
    // buffer statique interdit

    return NULL; // a modifier
}
