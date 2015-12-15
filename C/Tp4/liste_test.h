/* -------------------- */
/* --- liste_test.h --- */
/* -------------------- */

#ifndef _LISTE_TEST_H_
#define _LISTE_TEST_H_

// mode debug
#define ENABLE_LISTE_DEBUG

#ifdef ENABLE_LISTE_DEBUG
#define LISTE_DEBUG(X) X
#else
#define LISTE_DEBUG(X)
#endif



// fonction principale de test
void main_test_liste(void);

#endif
