/* -------------------- */
/* --- liste_test.c --- */
/* -------------------- */

#include <stdio.h>

#include "param_perl.h" // tests unitaires

#include "liste.h"
#include "liste_test.h"

/* -------------------------- */
void test_node_constructor(void)
/* -------------------------- */
{
    node *n = NULL;
    
    LISTE_DEBUG(printf("-----------------------------\n"));
    LISTE_DEBUG(printf("--- test_node_constructor ---\n"));
    LISTE_DEBUG(printf("-----------------------------\n"));
    
    n = node_constructor(10);
    node_display(n, "node");
    node_destructor(n);
}
/* ------------------- */
void test_node_copy(void)
/* ------------------- */
{
    node *n1 = NULL;
    node *n2 = NULL;
    
    LISTE_DEBUG(printf("----------------------------------\n"));
    LISTE_DEBUG(printf("--- test_node_constructor_copy ---\n"));
    LISTE_DEBUG(printf("----------------------------------\n"));
    
    n1 = node_constructor(10);
    node_display(n1, "node1");
    
    n2 = node_copy(n1);
    node_display(n1, "node2");
    
    node_destructor(n1);
    node_destructor(n2);
}
/* --------------------- */
void test_liste_empty(void)
/* --------------------- */
{
    node *n = NULL;
    
    LISTE_DEBUG(printf("------------------------\n"));
    LISTE_DEBUG(printf("--- test_liste_empty ---\n"));
    LISTE_DEBUG(printf("------------------------\n"));
    
    printf("empty = %d\n", liste_empty(n));
    
    n = node_constructor(10);
    printf("empty = %d\n", liste_empty(n));
    
    node_destructor(n);
}
/* ------------------- */
void test_liste_len(void)
/* ------------------- */
{
    node *n = NULL;
    
    LISTE_DEBUG(printf("----------------------\n"));
    LISTE_DEBUG(printf("--- test_liste_len ---\n"));
    LISTE_DEBUG(printf("----------------------\n"));
    
    printf("len = %d\n", liste_len(n));
    
    n = node_constructor(10);
    printf("len = %d\n", liste_len(n));
    
    node_destructor(n);
}
/* --------------------------- */
void test_liste_insert_tail(void)
/* --------------------------- */
{
    node *liste = NULL;
    node *x = NULL;
    
    LISTE_DEBUG(printf("------------------------------\n"));
    LISTE_DEBUG(printf("--- test_liste_insert_tail ---\n"));
    LISTE_DEBUG(printf("------------------------------\n"));
    
    liste = node_constructor(1);
    liste_display(liste, "liste1");
    
    x = node_constructor(2);
    liste = liste_insert_tail(liste, x);
    liste_display(liste, "liste2");
    
    x = node_constructor(3);
    liste = liste_insert_tail(liste, x);
    liste_display(liste, "liste3");
  
    // a decommenter apres avoir ecrit le code de liste_destructor
    //liste_destructor(liste);
}
/* -------------------------- */
void test_liste_destructor(void)
/* -------------------------- */
{
    node *liste = NULL;
    node *x = NULL;
    
    LISTE_DEBUG(printf("-----------------------------\n"));
    LISTE_DEBUG(printf("--- test_liste_destructor ---\n"));
    LISTE_DEBUG(printf("-----------------------------\n"));
    
    liste = node_constructor(1);
    liste_display(liste, "liste1");
    
    x = node_constructor(2);
    liste = liste_insert_tail(liste, x);
    liste_display(liste, "liste2");
    
    x = node_constructor(3);
    liste = liste_insert_tail(liste, x);
    liste_display(liste, "liste3");
    
    liste_destructor(liste);
}
/* --------------------------- */
void test_liste_insert_head(void)
/* --------------------------- */
{
    node *liste = NULL;
    node *x = NULL;
    
    LISTE_DEBUG(printf("------------------------------\n"));
    LISTE_DEBUG(printf("--- test_liste_insert_head ---\n"));
    LISTE_DEBUG(printf("------------------------------\n"));
    
    liste = node_constructor(1);
    liste_display(liste, "liste1");
    
    x = node_constructor(2);
    liste = liste_insert_head(liste, x);
    liste_display(liste, "liste2");
    
    x = node_constructor(3);
    liste = liste_insert_head(liste, x);
    liste_display(liste, "liste3");
    
    // a decommenter apres avoir ecrit le code de liste_destructor
    //liste_destructor(liste);
}
/* ---------------------- */
void test_liste_insert(void)
/* ---------------------- */
{
    node *liste = NULL;
    node *x = NULL;
    
    LISTE_DEBUG(printf("-------------------------\n"));
    LISTE_DEBUG(printf("--- test_liste_insert ---\n"));
    LISTE_DEBUG(printf("-------------------------\n"));
    
    liste = node_constructor(1);
    liste_display(liste, "liste1");
    
    x = node_constructor(2);
    liste = liste_insert_tail(liste, x);
    liste_display(liste, "liste2");
    
    x = node_constructor(3);
    liste = liste_insert_tail(liste, x);
    liste_display(liste, "liste3");
    
    x = node_constructor(4);
    liste = liste_insert(liste, 0, x);
    liste_display(liste, "liste4");
    
    x = node_constructor(5);
    liste = liste_insert(liste, 4, x);
    liste_display(liste, "liste5");
    
    x = node_constructor(6);
    liste = liste_insert(liste, 1, x);
    liste_display(liste, "liste6");
    
    x = node_constructor(7);
    liste = liste_insert(liste, 3, x);
    liste_display(liste, "liste7");
    
    // a decomenter pour valider que cette insertion genere effectivement une erreur
    //x = node_constructor(8);
    //liste = liste_insert(liste, 8, x);
    //liste_display(liste, "liste8");
    
    // a decommenter apres avoir ecrit le code de liste_destructor
    //liste_destructor(liste);
}
/* ---------------------------- */
void test_liste_extract_tail(void)
/* ---------------------------- */
{
    node *liste = NULL;
    node *x = NULL;
    
    LISTE_DEBUG(printf("-------------------------------\n"));
    LISTE_DEBUG(printf("--- test_liste_extract_tail ---\n"));
    LISTE_DEBUG(printf("-------------------------------\n"));
    
    
    // creation et ajout
    liste = node_constructor(1);
    liste_display(liste, "liste1");
    
    x = node_constructor(2);
    liste = liste_insert_tail(liste, x);
    liste_display(liste, "liste2");
    
    x = node_constructor(3);
    liste = liste_insert_tail(liste, x);
    liste_display(liste, "liste3");
    
    x = node_constructor(4);
    liste = liste_insert_tail(liste, x);
    liste_display(liste, "liste4");
    
    // suppression  
    liste = liste_extract_tail(liste, &x);
    node_display(x, "x4");
    liste_display(liste, "liste5");
    
    liste = liste_extract_tail(liste, &x);
    node_display(x, "x3");
    liste_display(liste, "liste6");
    
    liste = liste_extract_tail(liste, &x);
    node_display(x, "x2");
    liste_display(liste, "liste7");
    
    // decomenter la suite pour valider la gestion des erreurs (liste8 est vide)
    //liste = liste_extract_tail(liste, &x);
    //node_display(x, "x1");
    //liste_display(liste, "liste8");
    
    
    //liste = liste_extract_tail(liste, &x);
    //node_display(x, "x0");
    //liste_display(liste, "liste8");
    
    // a decommenter apres avoir ecrit le code de liste_destructor
    //liste_destructor(liste);
}
/* ---------------------------- */
void test_liste_extract_head(void)
/* ---------------------------- */
{
    node *liste = NULL;
    node *x = NULL;
    
    LISTE_DEBUG(printf("------------------------------\n"));
    LISTE_DEBUG(printf("--- test_liste_remove_head ---\n"));
    LISTE_DEBUG(printf("------------------------------\n"));
    
    
    // creation et ajout
    liste = node_constructor(1);
    liste_display(liste, "liste1");
    
    x = node_constructor(2);
    liste = liste_insert_tail(liste, x);
    liste_display(liste, "liste2");
    
    x = node_constructor(3);
    liste = liste_insert_tail(liste, x);
    liste_display(liste, "liste3");
    
    x = node_constructor(4);
    liste = liste_insert_tail(liste, x);
    liste_display(liste, "liste4");
    
    // suppression  
    liste = liste_extract_head(liste, &x);
    node_display(x, "x4");
    liste_display(liste, "liste5");
    
    liste = liste_extract_head(liste, &x);
    node_display(x, "x3");
    liste_display(liste, "liste6");
    
    liste = liste_extract_head(liste, &x);
    node_display(x, "x2");
    liste_display(liste, "liste7");
    
    // decomenter la suite pour valider la gestion des erreurs
    //liste = liste_extract_head(liste, &x);
    //node_display(x, "x1");
    //liste_display(liste, "liste7");
    
    //liste = liste_extract_head(liste, &x);
    //node_display(x, "x0");
    //liste_display(liste, "liste8");
    
    // a decommenter apres avoir ecrit le code de liste_destructor
    //liste_destructor(liste);
}
/* ----------------------- */
void test_liste_extract(void)
/* ----------------------- */
{
    node *liste = NULL;
    node *x = NULL;
    
    LISTE_DEBUG(printf("-------------------------\n"));
    LISTE_DEBUG(printf("--- test_liste_remove ---\n"));
    LISTE_DEBUG(printf("-------------------------\n"));
    
    
    // creation et ajout
    liste = node_constructor(1);
    liste_display(liste, "liste1");
    
    x = node_constructor(2);
    liste = liste_insert_tail(liste, x);
    liste_display(liste, "liste2");
    
    x = node_constructor(3);
    liste = liste_insert_tail(liste, x);
    liste_display(liste, "liste3");
    
    x = node_constructor(4);
    liste = liste_insert_tail(liste, x);
    liste_display(liste, "liste4");
    
    // exteactop,  
    liste = liste_extract(liste, 2, &x);
    node_display(x, "x3");
    liste_display(liste, "liste5");
    
    liste = liste_extract(liste, 1, &x);
    node_display(x, "x2");
    liste_display(liste, "liste6");
    
    // decomenter la suite pour valider la gestion des erreurs
    //liste = liste_extract(liste, 2, &x);
    //node_display(x, "x");
    //liste_display(liste, "liste7");
        
    // a decommenter apres avoir ecrit le code de liste_destructor
    //liste_destructor(liste);
}
/* -------------------- */
void main_test_liste(void)
/* -------------------- */
{
    // ne rien ecrire en dessous de cette ligne
    
    LISTE_DEBUG(printf("=======================\n"));
    LISTE_DEBUG(printf("=== main_test_liste ===\n"));
    LISTE_DEBUG(printf("=======================\n"));

    // a mettre en commentaire
    //node_error(LISTE_EMPTY);
    
    // en dehors du protocole de test
    //test_node_constructor();
    //test_node_copy();
    
#ifdef TEST0
    test_liste_empty();
#endif
#ifdef TEST1
    test_liste_len();
#endif
#ifdef TEST2    
    test_liste_insert_tail();
#endif
#ifdef TEST3       
    test_liste_destructor();
#endif
#ifdef TEST4    
    test_liste_insert_head();
#endif
#ifdef TEST5    
    test_liste_insert();
#endif
#ifdef TEST6    
    test_liste_extract_tail();
#endif
#ifdef TEST7    
    test_liste_extract_head();
#endif
#ifdef TEST8    
    test_liste_extract();
#endif
}