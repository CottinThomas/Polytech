/* ----------------- */
/* --- tableau.h --- */
/* ----------------- */

#ifndef _TABLEAU_H_
#define _TABLEAU_H_

// mode verbeux
//#define ENABLE_TABLEAU_VERBOSE
#ifdef ENABLE_TABLEAU_VERBOSE
#define TABLEAU_VERBOSE(X) X
#else
#define TABLEAU_VERBOSE(X)
#endif

void tableau_zero(int *T, int n);
void tableau_init_param(int *T, int n, int x0, int xstep);
void tableau_init_random(int *T, int n, int a, int x0, int b, int m);
void tableau_display(int *T, int n, char *format, char *nom);

void tableau_tri_insertion(int *T, int n);
void tableau_tri_insertion_reverse(int *T, int n);

void tableau_tri_selection(int *T, int n);
void tableau_tri_selection_reverse(int *T, int n);


int  tableau_max(int *T, int n);
int  tableau_max2(int *T, int n);

#endif
