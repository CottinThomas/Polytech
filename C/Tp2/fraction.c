/* ------------------ */
/* --- fraction.c --- */
/* ------------------ */

#include <stdio.h>
#include <stdlib.h>
#include "fraction.h"

/* ------------------------ */
sint32 gcd(sint32 u, sint32 v)
/* ------------------------ */
{
    sint32 r;
    
    u = abs(u);
    v = abs(v);
    while(v) {
        r = u % v;
        u = v;
        v = r;
    }
    return u;
}
// gerer le cas des numerateurs ou denominateurs negatif
/* -------------------------------------------------- */
void fraction_display(fraction f, char *fmt, char *name)
/* -------------------------------------------------- */
{
    if(name) printf("%s = ", name);
    
    if(fmt) printf(fmt, f.a); else printf("%d", f.a);
    printf(" / ");
    if(fmt) printf(fmt, f.b); else printf("%d", f.b);
    printf("\n");
}
/* ---------------------- */
fraction fraction_zero(void)
/* ---------------------- */
{
    fraction f;
    f.a = 0;
    f.b = 1;
    return f;
}
/* ---------------------------------------- */
fraction fraction_fraction(sint16 a, sint16 b)
/* ---------------------------------------- */
{
    fraction f;  
    f.a = a;
    f.b = b;
    return f;
}
/* ---------------------------- */
fraction fraction_copy(fraction f)
/* ---------------------------- */
{
    fraction t;
    t.a = f.a;
    t.b = f.b;
    return t;
}
/* ----------------------------------------- */
fraction fraction_add(fraction f1, fraction f2)
/* ----------------------------------------- */
{
    fraction f;
    f.a=f1.a*f2.b+f1.b*f2.a;
    f.b=f1.b*f2.b;
    sint32 gcdF = gcd(f.a,f.b);
    f.a = f.a/gcdF;
    f.b = f.b/gcdF;
    return f;
}
/* ----------------------------------------- */
fraction fraction_sub(fraction f1, fraction f2)
/* ----------------------------------------- */
{
    fraction f;
    f.a=f1.a*f2.b-f1.b*f2.a;
    f.b=f1.b*f2.b;
    sint32 gcdF = gcd(f.a,f.b);
    f.a = f.a/gcdF;
    f.b = f.b/gcdF;
    return f;
}
/* ----------------------------------------- */
fraction fraction_mul(fraction f1, fraction f2)
/* ----------------------------------------- */
{
    fraction f;
    f.a=f1.a*f2.a;
    f.b=f2.b*f1.b; 
    sint32 gcdF = gcd(f.a,f.b);
    f.a = f.a/gcdF;
    f.b = f.b/gcdF;
    return f;
}
/* ----------------------------------------- */
fraction fraction_div(fraction f1, fraction f2)
/* ----------------------------------------- */
{
    fraction f;
    f.a=f1.a*f2.b;
    f.b=f2.a*f1.b; 
    sint32 gcdF = gcd(f.a,f.b);
    f.a = f.a/gcdF;
    f.b = f.b/gcdF;
    return f;
}
