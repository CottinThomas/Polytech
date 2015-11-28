/* --------------------- */
/* --- chaine_test.c --- */
/* --------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "chaine.h"

/* ---------------------- */
void test_arabe_romain(void)
/* ---------------------- */
{
    // comversion de nombres compris entre [1..4999]
    
    int i;
    
    // exemples de test unitaires
    printf("Par tableau :\n");
    arabe_romain_table(1);
    arabe_romain_table(4);
    arabe_romain_table(5);
    arabe_romain_table(9);
    arabe_romain_table(10);
    arabe_romain_table(14);
    arabe_romain_table(19);

    printf("\n");

    printf("Par calcul :\n");
    arabe_romain_calc(1);
    arabe_romain_calc(4);
    arabe_romain_calc(5);
    arabe_romain_calc(9);
    arabe_romain_calc(10);
    arabe_romain_calc(14);
    arabe_romain_calc(19);
    // en ajouter d'autres si necessaire ...
    
    // boucle de test (servira pour validation de tous les cas possibles)
    // sera activer pour valider vos resultats
    /*for(i=1; i<=4999; i++) {
        arabe_romain_table(i);
        arabe_romain_calc(i);
	}*/
}
/* ----------------- */
void test_str_end(void)
/* ----------------- */
{
    char *str, *ptr;
    puts("--------------------");
    puts("--- test_str_end ---");
    puts("--------------------");
    
    // ptr doit pointer ver '\0'
    // donc ptr -1 doit pointer vers le dernier char de la chaine, celui qu'on affiche
    // le second affichage est pour le debug
    
    str = "abcdef"; ptr = str_end(str); printf("%s\n", ptr-1); CHAINE_VERBOSE(printf("%s: %p %p\n", str, str, ptr));
    str = "a";      ptr = str_end(str); printf("%s\n", ptr-1); CHAINE_VERBOSE(printf("%s: %p %p\n", str, str, ptr));
    str = "";       ptr = str_end(str); printf("%s\n", ptr-1); CHAINE_VERBOSE(printf("%s: %p %p\n", str, str, ptr));
}
/* ----------------- */
void test_str_len(void)
/* ----------------- */
{
    char *str;
    puts("--------------------");
    puts("--- test_str_len ---");
    puts("--------------------");
    
    str = "abc"; printf("str_len(\"%s\") = %d\n", str, str_len(str));
    str = "a";   printf("str_len(\"%s\") = %d\n", str, str_len(str));
    str = "";    printf("str_len(\"%s\") = %d\n", str, str_len(str));
}
/* ----------------- */
void test_str_dup(void)
/* ----------------- */
{
    // necessite que str_len soit correct
    
    char *str, *ptr;
    int len;
    
    puts("--------------------");
    puts("--- test_str_dup ---");
    puts("--------------------");
    
    str = "abc";
    ptr = str_dup(str);
    len = str_len(ptr); 
    printf("ptr = \"%s\", str_len(ptr)= %d, ptr[len-1] = '%c' (%d), ptr[len] = '%c' (%d)\n", ptr, len, ptr[len-1], ptr[len-1], ptr[len], ptr[len]);
    free(ptr); ptr = NULL; // desallocation de la memoire allouee dans str_dup
    
    str = "a";
    ptr = str_dup(str); 
    len = str_len(ptr); 
    printf("ptr = \"%s\", str_len(ptr)= %d, ptr[len-1] = '%c' (%d), ptr[len] = '%c' (%d)\n", ptr, len, ptr[len-1], ptr[len-1], ptr[len], ptr[len]);
    free(ptr); ptr = NULL; // desallocation de la memoire allouee dans str_dup
    
    str = "";
    ptr = str_dup(str); 
    len = str_len(ptr); 
    printf("ptr = \"%s\", str_len(ptr)= %d, ptr[len-1] = '%c' (%d), ptr[len] = '%c' (%d)\n", ptr, len, ptr[len-1], ptr[len-1], ptr[len], ptr[len]);
    free(ptr); ptr = NULL; // desallocation de la memoire allouee dans str_dup
}
/* ----------------- */
void test_str_cat(void)
/* ----------------- */
{
    char *str1, *str2, *ptr;
    int len;
    
    puts("--------------------");
    puts("--- test_str_cat ---");
    puts("--------------------");
    
    str1 = "abc";
    str2 = "defg";
    ptr = str_cat(str1, str2); len = str_len(ptr);
    printf("\"%s\" + \"%s\" = \"%s\"\n", str1, str2, ptr);
    free(ptr); ptr = NULL; // desallocation de la memoire allouee dans str_cat
    
    str1 = "abc";
    str2 = NULL;
    ptr = str_cat(str1, str2); len = str_len(ptr);
    printf("\"%s\" + \"%s\" = \"%s\"\n", str1, str2, ptr);
    free(ptr); ptr = NULL; // desallocation de la memoire allouee dans str_cat
    
    str1 = NULL;
    str2 = "defg";
    ptr = str_cat(str1, str2); len = str_len(ptr);
    printf("\"%s\" + \"%s\" = \"%s\"\n", str1, str2, ptr);
    free(ptr); ptr = NULL; // desallocation de la memoire allouee dans str_cat
    
    str1 = NULL;
    str2 = NULL;
    ptr = str_cat(str1, str2); len = str_len(ptr);
    printf("\"%s\" + \"%s\" = \"%s\"\n", str1, str2, ptr);
    free(ptr); ptr = NULL; // desallocation de la memoire allouee dans str_cat
}
/* ---------------------- */
void test_str_ndupchar(void)
/* ---------------------- */
{
    char c;
    int n;
    char buffer[BUFFER_SIZE];
    
    puts("-------------------------");
    puts("--- test_str_ndupchar ---");
    puts("-------------------------");
    
    c = '1';
    n = 2;
    str_ndupchar(buffer, c, n);
    printf("%d x '%c' = \"%s\"\n", n, c, buffer);
    
    c = '1';
    n = 1;
    str_ndupchar(buffer, c, n);
    printf("%d x '%c' = \"%s\"\n", n, c, buffer);
    
    c = '1';
    n = 0;
    str_ndupchar(buffer, c, n);
    printf("%d x '%c' = \"%s\"\n", n, c, buffer);
    
}
/* ----------------- */
void test_int_len(void)
/* ----------------- */
{
    int x, n;
    
    puts("-------------------------");
    puts("--- test_int_len ---");
    puts("-------------------------");
    
    x = 9; n = int_len(x); printf("int_len(%d) = %d\n", x, n);
    x = 99; n = int_len(x); printf("int_len(%d) = %d\n", x, n);
    x = 999; n = int_len(x); printf("int_len(%d) = %d\n", x, n);
    x = 9999; n = int_len(x); printf("int_len(%d) = %d\n", x, n);
    x = 99999; n = int_len(x); printf("int_len(%d) = %d\n", x, n);
    x = 999999; n = int_len(x); printf("int_len(%d) = %d\n", x, n);
    x = 9999999; n = int_len(x); printf("int_len(%d) = %d\n", x, n);
    x = 99999999; n = int_len(x); printf("int_len(%d) = %d\n", x, n);
    x = 999999999; n = int_len(x); printf("int_len(%d) = %d\n", x, n);
    x = 1234567890; n = int_len(x); printf("int_len(%d) = %d\n", x, n);
}
/* ----------------- */
void test_int2str(void)
/* ----------------- */
{
    int x;
    char *str;
    
    x = 9;
    str = i2str(x); printf("%d = \"%s\"\n", x, str);
    free(str); str = NULL; 
    
    x = 10;
    str = i2str(x); printf("%d = \"%s\"\n", x, str);
    free(str); str = NULL; 
    
    x = 100;
    str = i2str(x); printf("%d = \"%s\"\n", x, str);
    free(str); str = NULL; 
    
    x = 1000;
    str = i2str(x); printf("%d = \"%s\"\n", x, str);
    free(str); str = NULL; 
}
/* ---------------- */
void test_ic2str(void)
/* ---------------- */
{
    int x;
    char c; 
    char *str;
    
    x = 1; c = '1';
    str = ic2str(x, c); printf("%d x %c= \"%s\"\n", x, c, str);
    free(str); str = NULL; 
    
    x = 10; c = '2';
    str = ic2str(x, c); printf("%d x %c = \"%s\"\n", x, c, str);
    free(str); str = NULL; 
    
    x = 99; c = '9';
    str = ic2str(x, c); printf("%d x %c = \"%s\"\n", x, c, str);
    free(str); str = NULL; 
}
/* ------------------- */
void test_str_count(void)
/* ------------------- */
{
    char *str, *ptr;
    char c;
    int count;
    
    puts("----------------------");
    puts("--- test_str_count ---");
    puts("----------------------");
    
    str = "abc";  ptr = str_count(str, &c, &count); printf("%s = %d x '%c' + %s (%c=%d)\n", str, count, c, ptr, *ptr, *ptr);
    str = "aabc"; ptr = str_count(str, &c, &count); printf("%s = %d x '%c' + %s (%c=%d)\n", str, count, c, ptr, *ptr, *ptr);
    str = "aa";   ptr = str_count(str, &c, &count); printf("%s = %d x '%c' + %s (%c=%d)\n", str, count, c, ptr, *ptr, *ptr);
    str = "a";    ptr = str_count(str, &c, &count); printf("%s = %d x '%c' + %s (%c=%d)\n", str, count, c, ptr, *ptr, *ptr);
    str = "";     ptr = str_count(str, &c, &count); printf("%s = %d x '%c' + %s (%c=%d)\n", str, count, c, ptr, *ptr, *ptr);
    
}
/* ---------------------------- */
void routine_str_count2(char *str)
/* ---------------------------- */
{
    char *ptr;
    char c;
    int count;
    
    puts("------------------------");
    puts("-- routine_str_count2 --");
    puts("------------------------");
    
    ptr = str;
    puts(str);
    
    do {
        ptr = str_count(str, &c, &count); printf("%s = %d x '%c' + %s (%c=%d)\n", str, count, c, ptr, *ptr, *ptr);
        str = ptr;
    } while (count); // Question: que pourrait etre une autre condition de sortie ?
}
/* -------------------- */
void test_str_count2(void)
/* -------------------- */
{    
    char *str;
    
    puts("-----------------------");
    puts("--- test_str_count2 ---");
    puts("-----------------------");
    
    str = "abc";  routine_str_count2(str);
    str = "aabc"; routine_str_count2(str);
    str = "aa";   routine_str_count2(str);
    str = "a";    routine_str_count2(str);
    str = "";     routine_str_count2(str);
}
/* --------------------- */
void test_palyndrome1(void)
/* --------------------- */
{
    puts("------------------------");
    puts("--- test_palyndrome1 ---");
    puts("------------------------");
    
    /*printf("%d\n", is_palyndrome1("radar"));
    printf("%d\n", is_palyndrome1("radrar"));
    printf("%d\n", is_palyndrome1("1221"));
    printf("%d\n", is_palyndrome1("11"));
    printf("%d\n", is_palyndrome1("1"));
    printf("%d\n", is_palyndrome1(""));*/
    
    printf("%d\n", is_palyndrome1("radar"));
    printf("%d\n", is_palyndrome1("radrar"));
    printf("%d\n", is_palyndrome1("1221"));
    printf("%d\n", is_palyndrome1("11"));
    printf("%d\n", is_palyndrome1("1"));
    printf("%d\n", is_palyndrome1(""));
}
/* --------------------- */
void test_palyndrome2(void)
/* --------------------- */
{
    puts("------------------------");
    puts("--- test_palyndrome2 ---");
    puts("------------------------");
    
    printf("%d\n", is_palyndrome2("r a d a r"));
    printf("%d\n", is_palyndrome2("radrar"));
    printf("%d\n", is_palyndrome2("1  2   2   1 "));
    printf("%d\n", is_palyndrome2("1  2  2 2   1 "));
    printf("%d\n", is_palyndrome2("11"));
    printf("%d\n", is_palyndrome2("1"));
    printf("%d\n", is_palyndrome2(""));
    printf("%d\n", is_palyndrome2(" "));
    printf("%d\n", is_palyndrome2("  "));
    printf("%d\n", is_palyndrome2("eliot ruse traca sa carte sur toile"));
}
/* --------------------- */
void test_commentaire(void)
/* --------------------- */
{
    char *str, *ptr;
    puts("--------------------------------");
    puts("--- test_commentaire_itere_1 ---");
    puts("--------------------------------");
    
    str = "1121"; ptr = commentaire(str); printf("%s -> %s\n", str, ptr);
    free(ptr); ptr = NULL;
}
/* --------------------------- */
void test_commentaire_itere(void)
/* --------------------------- */
{
    int iter;
    char *str, *ptr;
    puts("------------------------------");
    puts("--- test_commentaire_itere ---");
    puts("------------------------------");
    
    str = "1";
    iter = 10;
    ptr = commentaire_itere(str, iter); printf("(%s) ^ %d => %s\n", str, iter, ptr);
    free(ptr); ptr = NULL;
    
    str = "111";
    iter = 10;
    ptr = commentaire_itere(str, iter); printf("(%s) ^ %d => %s\n", str, iter, ptr);
    free(ptr); ptr = NULL;/**/
}
/* --------------------------------------------- */
int main_test_chaine(void)
/* --------------------------------------------- */
{
    // insert code here...
    puts("========================");
    puts("=== main_test_chaine ===");
    puts("========================");
    
    test_arabe_romain();
    
    test_str_end();
    test_str_len();
    test_str_dup();
    test_str_cat();
    // test_str_ndupchar();
    test_int_len();
    // test_int2str();
    // test_ic2str();
    
    // test_str_count();
    // test_str_count2();
    // test_palyndrome1();
    // test_palyndrome2();
    
    // test_commentaire();
    // test_commentaire_itere();
    return 0;
}
