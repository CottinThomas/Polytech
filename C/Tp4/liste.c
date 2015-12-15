/* --------------- */
/* --- liste.c --- */
/* --------------- */

#include <stdio.h>
#include <stddef.h>
#include <stdarg.h> // va_list
#include <stdlib.h>

#include "liste.h"

/* ---------------------------- */
void node_error(char *format, ...)
/* ---------------------------- */
/* global error handler */
{
    va_list pa;
    int n;
    char *s, c;
    float f;
    
    printf("Error: ");
    
    va_start(pa, format);
    
    while (*format != '\0') {
        if ( *format == '%' ) {
            switch (*++format) {
                case '%' : putchar('%'); break;
                case 'c' :
                    c = va_arg(pa, int); // 'char' is promoted to 'int' when passed through '...'
                    putchar(c);
                    break;
                case 'd' :
                    n = va_arg(pa, int);
                    printf("%d", n); 
                    break;
                case 'f' : /* affichage d'un float */ 
                    f = va_arg(pa, double);    // 'float' is promoted to 'double' when passed through '...'
                    printf("%f", f); 
                    break;
                case 's' :
                    s = va_arg(pa, char*);
                    for ( ; *s != '\0'; s++ ) 
                        putchar(*s);
                    break;
            }
        }
        else 
            putchar( *format);
        format++;
    }   
    va_end(pa);
    putchar('\n');
    exit(-1);
}
/* ----------------------- */
node* node_constructor(int x)
/* ----------------------- */
{
    node *n;
    
    n = (node*) malloc(sizeof(node));
    if(n == NULL) {
        node_error("liste_constructor_empty: malloc error");
    }
    n->next = NULL;
    n->data = x;
    return n;
}
/* ----------------------- */
void node_destructor(node* n)
/* ----------------------- */
{
    n->data = 0;
    n->next = NULL;
    free(n);
}
/* ------------------ */
node* node_copy(node *n)
/* ------------------ */
{
    return node_constructor(n->data);
}
/* ----------------- */
int node_empty(node *n)
/* ----------------- */
{
    // hypothese de fonctionnement: les pointeurs sont initialises a NULL lors de leur declaration
    // a completer
        return 0;
   
}
/* -------------------------------- */
void node_display(node *n, char *name)
/* -------------------------------- */
{
    // affichage de l'element courant
    
    // a completer
}

/* ------------------------------------ */
void node_display_all(node *n, char *name)
/* ------------------------------------ */
{
    // affichage de tous les elements
    // n'affiche le nom que pour le premier element
   // a completer
}
/* ---------------------------- */
void liste_destructor(node *liste)
/* ---------------------------- */
{
   // a completer
}
/* ---------------------- */
int liste_empty(node *liste)
/* ---------------------- */
{
    // hypothese de fonctionnement: les pointeurs sont initialises a NULL lors de leur declaration
   // a completer
    return 0;
}
/* -------------------- */
int liste_len(node *liste)
/* -------------------- */
{
    // a completer
    return 0;
}
/* ------------------------------------- */
void liste_display(node *liste, char *name)
/* ------------------------------------- */
{
    // affichage de tous les elements de la liste
    
   // a completer
}
/* ---------------------------------------- */
node* liste_insert_tail(node *liste, node *x)
/* ---------------------------------------- */
{
    // insertion en fin de liste
    // a completer
   
    return NULL;
}
/* ---------------------------------------- */
node* liste_insert_head(node *liste, node *x)
/* ---------------------------------------- */
{
    // insertion en debut de liste
    // a completer
   
    return NULL;
}
/* ------------------------------------------ */
node* liste_insert(node *liste, int n, node *x)
/* ------------------------------------------ */
{
    // insertion de x a la position 'pos'
    // on commence a numeroter a 0
    // x devra etre le n-ieme element


     // a completer
   
    return NULL;
}
/* ----------------------------------------- */
node* liste_extract_tail(node *liste, node **x)
/* ----------------------------------------- */
{
    // suppression en fin de liste
    // a completer
    return NULL;
}
/* ----------------------------------------- */
node* liste_extract_head(node *liste, node **x)
/* ----------------------------------------- */
{
    // suppression en debut de liste
    
    // a completer
   return NULL;
}
/* ------------------------------------------- */
node* liste_extract(node *liste, int n, node **x)
/* ------------------------------------------- */
{
    // a completer
   return NULL;
}
