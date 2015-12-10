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
const int TRUE = 1;
const int FALSE = 0;

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
    int taille = 0;
    if(x == 0)
        return 1;
    while(x > 0){
        taille = taille+1;
        x = x/10;
    }
    return taille;
}
/* ------------ */
char* i2str(int x)
/* ------------ */
{
    int taille = int_len(x);
    char *result = malloc(taille+1);
    result[taille]='\0';
    int cpt = 1;
    int mod = x%10;
    while(x > 0){
        char temp = mod + '0';
        result[taille-cpt] = temp;
        x = x/10;
        cpt = cpt+1;
        mod = x%10;
    }
    return result; // a modifier
}
/* --------------------- */
char* ic2str(int x, char c)
/* --------------------- */
{
    char *chaine1 = i2str(x);
    char chaine2[2];
    chaine2[0] = c;
    chaine2[1] = '\0';
    return str_cat(chaine1,chaine2); // a modifier
}
/* ----------------------------------------- */
char* str_count(char *str, char *c, int *count)
/* ----------------------------------------- */
{
    char *firstChar = malloc(str_len(str));
    firstChar[0] = '\0';
    count[0] = 0;
    if(str==NULL){
        str[0] = '\0';
        c[0] = '\0';
        return "\0";
    }
    c[0] = str[0];
    c[1] = '\0';
    while(str[0] != '\0' && firstChar[0] == '\0'){
        if(str[0] == c[0])
            count[0] = count[0] + 1;
        else if(firstChar[0] == '\0'){
            firstChar = str;
        }
        str = str+sizeof(char);
    }
    return firstChar; // a modifier
}
/* ----------------------- */
int is_palyndrome1(char *str)
/* ----------------------- */
{    
    if(str == NULL)
        return TRUE;
    int taille = str_len(str);
    int cpt = 0;
    while(cpt <= taille/2){
        if(str[cpt] != str[taille-1-cpt])
            return FALSE;
        cpt = cpt+1;
    }
    return TRUE; // a modifier
}
/* ----------------------- */
int is_palyndrome2(char *str)
/* ----------------------- */
{
    if(str == NULL)
        return TRUE;
    int taille = str_len(str);
    int cptUp = 0;
    int cptDown = taille-1;
    while(cptUp < cptDown){
        while(str[cptUp] == ' '){
            cptUp = cptUp + 1;
        }
        while(str[cptDown] == ' '){
            cptDown = cptDown - 1;
        }
        if(str[cptUp] != str[cptDown])
            return FALSE;
        cptUp = cptUp + 1;
        cptDown = cptDown - 1;
    }
    return TRUE;
}
/* ---------------------- */
char* commentaire(char *str)
/* ---------------------- */
{
    
    int cpt = 1;
    char *temp;
    char *toDisplayImpair;
    char *toDisplayPair;
    char *reste = malloc(str_len(str)+1);
    reste = str_dup(str);
    while(reste[0] != '\0'){

        char lettre;
        int occurrence;
        reste = str_count(reste,&lettre,&occurrence);
        printf(i2str(occurrence));
        if(cpt%2==0){
            temp = ic2str(occurrence,lettre);
            printf("%s\n", temp);
            toDisplayPair = str_cat(toDisplayImpair,temp);
            printf("%s\n", toDisplayPair);
//            free(toDisplayImpair);
            toDisplayImpair = NULL;
        }else {
            temp = ic2str(occurrence,lettre);
            printf("%s\n", temp);
            toDisplayImpair = str_cat(toDisplayPair,temp);
 //           free(toDisplayPair);
            toDisplayPair = NULL;
        }
        cpt = cpt+1;
    }
    if(cpt%2==0){
        toDisplayImpair[2*cpt] = '\0';
        return toDisplayImpair;
    }
    toDisplayPair[2*cpt] = '\0';
    return toDisplayPair;
}
/* -------------------------------------- */
char* commentaire_itere(char *str, int iter)
/* -------------------------------------- */
{
    // Ne pas oublier de faire un free quand une zone memoire allouee dynamiquement n'est plus utilisee par un pointeur
    // buffer statique interdit

    return NULL; // a modifier
}
