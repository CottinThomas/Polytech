/* --------------- */
/* --- liste.h --- */
/* --------------- */

#ifndef _LISTE_H_
#define _LISTE_H_

#include <stdio.h>

// mode debug: activer le define ci-dessous
#define ENABLE_LISTE_VERBOSE

#ifdef ENABLE_LISTE_VERBOSE
#define LISTE_VERBOSE(X) X
#define LISTE_DEBUG(X) X
#else
#define LISTE_VERBOSE(X)
#define LISTE_DEBUG(X)
#endif


#define NODE_EMPTY "node empty"
#define LISTE_EMPTY "liste empty"
#define LISTE_TOO_SHORT "liste too short"

/* --------------------------- */
/* --- gestion des erreurs --- */
/* --------------------------- */

void node_error(char *format, ...);

// ------------------------------------------- //
// -- structure de liste simplement chainee -- //
// ------------------------------------------- //

struct s_node{
    int data;
    struct s_node *next;
};
typedef struct s_node node;

// -------------------------------------------- //
// -- routines pour liste simplement chainee -- //
// -------------------------------------------- //

//node* node_constructor_empty(void); // constructeur par defaut
node* node_constructor(int x); // constructeur
node* node_copy(node *n);  // constructeur par copie
void  node_destructor(node* n);

void  liste_destructor(node* n);

void node_display(node *n, char *name);
void node_display_all(node *n, char *name);

int  liste_empty(node *n);
int  liste_len(node *n);

void liste_display(node *liste, char *name);

node* liste_insert_head(node *liste, node *x);
node* liste_insert     (node *liste, int n, node *x);
node* liste_insert_tail(node *liste, node *x);

node* liste_extract_head(node *liste, node **x);
node* liste_extract     (node *liste, int n, node **x);
node* liste_extract_tail(node *liste, node **x);

#endif