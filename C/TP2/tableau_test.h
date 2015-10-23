/* ---------------------- */
/* --- tableau_test.h --- */
/* ---------------------- */

#ifndef _TABLEAU_TEST_H_
#define _TABLEAU_TEST_H_

// taille des tableaux utilises
#define N 10

// mode debug
#define ENABLE_TABLEAU_DEBUG

#ifdef ENABLE_TABLEAU_DEBUG
#define TABLEAU_DEBUG(X) X
#else
#define TABLEAU_DEBUG(X)
#endif

// routines pour tests unitaires
void test_tableau_init_param(void);
void test_tableau_init_random(void);
void test_tableau_display(void);
void test_tableau_tri_insertion(void);
void test_tableau_tri_selection(void);
void test_tableau_max(void);
void test_tableau_max2(void);


// fonction principale de test
void main_test_tableau(void);

#endif
