/* ----------------------- */
/* --- test_fraction.h --- */
/* ----------------------- */

#ifndef _TEST_FRACTION_H_
#define _TEST_FRACTION_H_ 

// mode debug
#define ENABLE_FRACTION_DEBUG
#ifdef ENABLE_FRACTION_DEBUG
#define FRACTION_DEBUG(X) X
#else
#define FRACTION_DEBUG(X)
#endif

// routines pour tests unitaires
void test_gcd(void);
void test_fraction_zero(void);
void test_fraction_fraction(void);
void test_fraction_copy(void);
void test_fraction_add(void);
void test_fraction_sub(void);
void test_fraction_mul(void);
void test_fraction_div(void);

// fonction principale de test
void main_test_fraction(void);

#endif