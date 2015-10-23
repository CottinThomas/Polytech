/* ----------------------- */
/* --- test_fraction.c --- */
/* ----------------------- */

#include <stdio.h>

#include "param_perl.h" // tests unitaires

#include "fraction.h"
#include "fraction_test.h"

/* -------------- */
void test_gcd0(void)
/* ------------- */
{
    sint32 u, v, d;
    
    FRACTION_DEBUG(printf("=================\n"));
    FRACTION_DEBUG(printf("=== test_gcd0 ===\n"));
    FRACTION_DEBUG(printf("=================\n"));
    
    u = 120;
    v = 150;
    d = gcd(u, v);
    printf("gcd(%d,%d) = %d\n", u, v, d);
}
/* -------------- */
void test_gcd1(void)
/* ------------- */
{
    sint32 u, v, d;
    
    FRACTION_DEBUG(printf("-----------------\n"));
    FRACTION_DEBUG(printf("--- test_gcd1 ---\n"));
    FRACTION_DEBUG(printf("-----------------\n"));
    
    u = 120;
    v = 100;
    d = gcd(u, v);
    printf("gcd(%d,%d) = %d\n", u, v, d);
}
/* -------------- */
void test_gcd2(void)
/* ------------- */
{
    sint32 u, v, d;
    
    FRACTION_DEBUG(printf("-----------------\n"));
    FRACTION_DEBUG(printf("--- test_gcd2 ---\n"));
    FRACTION_DEBUG(printf("-----------------\n"));
    
    u = -120;
    v = 100;
    d = gcd(u, v);
    printf("gcd(%d,%d) = %d\n", u, v, d);
}
/* -------------- */
void test_gcd3(void)
/* ------------- */
{
    sint32 u, v, d;
    
    FRACTION_DEBUG(printf("-----------------\n"));
    FRACTION_DEBUG(printf("--- test_gcd3 ---\n"));
    FRACTION_DEBUG(printf("-----------------\n"));
    
    u = 120;
    v = -100;
    d = gcd(u, v);
    printf("gcd(%d,%d) = %d\n", u, v, d);
}
/* -------------- */
void test_gcd4(void)
/* ------------- */
{
    sint32 u, v, d;
    
    FRACTION_DEBUG(printf("-----------------\n"));
    FRACTION_DEBUG(printf("--- test_gcd4 ---\n"));
    FRACTION_DEBUG(printf("-----------------\n"));
    
    u = -120;
    v = -100;
    d = gcd(u, v);
    printf("gcd(%d,%d) = %d\n", u, v, d);
}
/* ----------------------- */
void test_fraction_zero(void)
/* ----------------------- */
{
    fraction z;
    
    FRACTION_DEBUG(printf("==========================\n"));
    FRACTION_DEBUG(printf("=== test_fraction_zero ===\n"));
    FRACTION_DEBUG(printf("==========================\n"));
    
    z = fraction_zero();
    fraction_display(z, NULL, NULL);
    fraction_display(z, "%3d", "z");
    fraction_display(z, NULL, "z");
    fraction_display(z, "%3d", NULL);
}
/* ---------------------------- */
void test_fraction_fraction0(void)
/* ---------------------------- */
{
    fraction f;
    
    FRACTION_DEBUG(printf("==============================\n"));
    FRACTION_DEBUG(printf("=== test_fraction_fraction ===\n"));
    FRACTION_DEBUG(printf("==============================\n"));
    
    f = fraction_fraction(1, 2);
    fraction_display(f, "%d", "f");
}
/* ---------------------------- */
void test_fraction_fraction1(void)
/* ---------------------------- */
{
    fraction f;
    
    FRACTION_DEBUG(printf("-------------------------------\n"));
    FRACTION_DEBUG(printf("--- test_fraction_fraction1 ---\n"));
    FRACTION_DEBUG(printf("-------------------------------\n"));
    
    f = fraction_fraction(12, 30);
    fraction_display(f, "%d", "f");
}
/* ---------------------------- */
void test_fraction_fraction2(void)
/* ---------------------------- */
{
    fraction f;
    
    FRACTION_DEBUG(printf("-------------------------------\n"));
    FRACTION_DEBUG(printf("--- test_fraction_fraction2 ---\n"));
    FRACTION_DEBUG(printf("-------------------------------\n"));
    
    f = fraction_fraction(-12, 30);
    fraction_display(f, "%d", "f");
}
/* ---------------------------- */
void test_fraction_fraction3(void)
/* ---------------------------- */
{
    fraction f;
    
    FRACTION_DEBUG(printf("-------------------------------\n"));
    FRACTION_DEBUG(printf("--- test_fraction_fraction3 ---\n"));
    FRACTION_DEBUG(printf("-------------------------------\n"));
    
    f = fraction_fraction(12, -30);
    fraction_display(f, "%d", "f");
}
/* ---------------------------- */
void test_fraction_fraction4(void)
/* ---------------------------- */
{
    fraction f;
    
    FRACTION_DEBUG(printf("-------------------------------\n"));
    FRACTION_DEBUG(printf("--- test_fraction_fraction4 ---\n"));
    FRACTION_DEBUG(printf("-------------------------------\n"));
    
    f = fraction_fraction(-12, 30);
    fraction_display(f, "%d", "f");
}
/* ----------------------- */
void test_fraction_copy(void)
/* ----------------------- */
{
    fraction f1, f2;
    
    FRACTION_DEBUG(printf("==========================\n"));
    FRACTION_DEBUG(printf("=== test_fraction_copy ===\n"));
    FRACTION_DEBUG(printf("==========================\n"));
    
    f1 = fraction_fraction(2, 4);
    f2 = fraction_copy(f1);
    fraction_display(f2, "%d", "f2");
}
/* ---------------------- */
void test_fraction_add(void)
/* ---------------------- */
{
    fraction f1, f2, f;
    
    FRACTION_DEBUG(printf("=========================\n"));
    FRACTION_DEBUG(printf("=== test_fraction_add ===\n"));
    FRACTION_DEBUG(printf("=========================\n"));
    
    f1 = fraction_fraction(1, 2);
    f2 = fraction_fraction(3, 2);
    f  = fraction_add(f1, f2);
    fraction_display(f, "%d", "f");
}
/* ---------------------- */
void test_fraction_sub(void)
/* ---------------------- */
{
    fraction f1, f2, f;
    
    FRACTION_DEBUG(printf("=========================\n"));
    FRACTION_DEBUG(printf("=== test_fraction_sub ===\n"));
    FRACTION_DEBUG(printf("=========================\n"));
    
    f1 = fraction_fraction(1, 2);
    f2 = fraction_fraction(3, 2);
    f  = fraction_sub(f1, f2);
    fraction_display(f, "%d", "f");
}
/* ---------------------- */
void test_fraction_mul(void)
/* ---------------------- */
{
    fraction f1, f2, f;
    
    FRACTION_DEBUG(printf("=========================\n"));
    FRACTION_DEBUG(printf("=== test_fraction_mul ===\n"));
    FRACTION_DEBUG(printf("=========================\n"));
    
    f1 = fraction_fraction(1, 2);
    f2 = fraction_fraction(3, 2);
    f  = fraction_mul(f1, f2);
    fraction_display(f, "%d", "f");
}
/* ---------------------- */
void test_fraction_div(void)
/* ---------------------- */
{
    fraction f1, f2, f;
    
    FRACTION_DEBUG(printf("=========================\n"));
    FRACTION_DEBUG(printf("=== test_fraction_div ===\n"));
    FRACTION_DEBUG(printf("=========================\n"));
    
    f1 = fraction_fraction(10, 2);
    f2 = fraction_fraction(30, 2);
    f  = fraction_div(f1, f2);
    fraction_display(f, "%d", "f");
}
/* ----------------------- */
void main_test_fraction(void)
/* ----------------------- */
{   
    // ne rien ecrire en dessous de cette ligne
    
    FRACTION_DEBUG(printf("=========================\n"));
    FRACTION_DEBUG(printf("=== main_test_tableau ===\n"));
    FRACTION_DEBUG(printf("=========================\n"));

#ifdef TEST17
    test_gcd0();
#endif
#ifdef TEST18
    test_gcd1();
#endif
#ifdef TEST19
    test_gcd2();
#endif
#ifdef TEST20
    test_gcd3();
#endif
#ifdef TEST21
    test_gcd4();
#endif
#ifdef TEST22
    test_fraction_zero();
#endif
#ifdef TEST23
    test_fraction_fraction0();
#endif
#ifdef TEST24
    test_fraction_fraction1();
#endif
#ifdef TEST25
    test_fraction_fraction2();
#endif
#ifdef TEST26
    test_fraction_fraction3();
#endif
#ifdef TEST27
    test_fraction_fraction4();
#endif
#ifdef TEST28
    test_fraction_copy();
#endif
#ifdef TEST29
    test_fraction_add();
#endif
#ifdef TEST30
    test_fraction_sub();
#endif
#ifdef TEST31
    test_fraction_mul();
#endif
#ifdef TEST32
    test_fraction_div();
#endif
}
