/* ------------------ */
/* --- fraction.h --- */
/* ------------------ */

#ifndef _FRACTION_H_
#define _FRACTION_H_ 

// mode debug
//#define ENABLE_FRACTION_DEBUG
#ifdef ENABLE_FRACTION_VERBOSE
#define FRACTION_VERBOSE(X) X
#else
#define FRACTION_VERBOSE(X)
#endif

typedef signed short sint16;
typedef signed short sint32;

typedef struct {
    sint16 a;
    sint16 b;
} fraction;

sint32 gcd(sint32 u, sint32 v);

void fraction_display(fraction f, char *fmt, char *name);

fraction fraction_zero(void);

fraction fraction_fraction(sint16 a, sint16 b);
fraction fraction_copy(fraction f);

fraction fraction_add(fraction f1, fraction f2);
fraction fraction_sub(fraction f1, fraction f2);
fraction fraction_mul(fraction f1, fraction f2);
fraction fraction_div(fraction f1, fraction f2);

#endif