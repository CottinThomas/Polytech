/* ---------------------- */
/* --- tableau_test.h --- */
/* ---------------------- */

#include <stdio.h>

#include "param_perl.h" // tests unitaires

#include "tableau.h"
#include "tableau_test.h"

/* ----------------------------- */
void test_tableau_init_param0(void)
/* ----------------------------- */
{
    int T[N];
    
    
    TABLEAU_DEBUG(printf("================================\n"));
    TABLEAU_DEBUG(printf("=== test_tableau_init_param0 ===\n"));
    TABLEAU_DEBUG(printf("================================\n"));
    
    tableau_init_param(T, N, 1, 1);
    tableau_display(T, N, "%4d", "T1+1");
    TABLEAU_DEBUG(printf("\n"));
}
/* ----------------------------- */
void test_tableau_init_param1(void)
/* ----------------------------- */
{
    int T[N];
    
    
    TABLEAU_DEBUG(printf("--------------------------------\n"));
    TABLEAU_DEBUG(printf("--- test_tableau_init_param1 ---\n"));
    TABLEAU_DEBUG(printf("--------------------------------\n"));
    
    tableau_init_param(T, N, 0, -1);
    tableau_display(T, N, "%4d", "T0-1");
    TABLEAU_DEBUG(printf("\n"));
}
/* ----------------------------- */
void test_tableau_init_random(void)
/* ----------------------------- */
{
    int T[N];
    
    TABLEAU_DEBUG(printf("================================\n"));
    TABLEAU_DEBUG(printf("=== test_tableau_init_random ===\n"));
    TABLEAU_DEBUG(printf("================================\n"));
    tableau_init_random(T, N, 11, 3, 17, 101);
    tableau_display(T, N, "%4d", "Rand");
    TABLEAU_DEBUG(printf("\n"));
}
/* ------------------------- */
void test_tableau_display(void)
/* ------------------------- */
{
    int i;
    int T[N];
    
    TABLEAU_DEBUG(printf("============================\n"));
    TABLEAU_DEBUG(printf("=== test_tableau_display ===\n"));
    TABLEAU_DEBUG(printf("============================\n"));
    
    for(i=0; i<N; i++) {
        T[i] = 2*i+1;
    }
    tableau_display(T, N, "%4d", NULL); TABLEAU_DEBUG(printf("\n"));
    tableau_display(T, N, "%4d", "T"); TABLEAU_DEBUG(printf("\n"));
}
/* -------------------------------- */
void test_tableau_tri_selection0(void)
/* -------------------------------- */
{
    int T[N];
    
    TABLEAU_DEBUG(printf("===================================\n"));
    TABLEAU_DEBUG(printf("=== test_tableau_tri_selection0 ===\n"));
    TABLEAU_DEBUG(printf("===================================\n"));
    
    tableau_init_param(T, N, 1, 1);
    tableau_display(T, N, "%4d", "T+ avant");
    tableau_tri_selection(T, N);
    tableau_display(T, N, "%4d", "T+ apres");
}
/* -------------------------------- */
void test_tableau_tri_selection1(void)
/* -------------------------------- */
{
    int T[N];
    
    TABLEAU_DEBUG(printf("-----------------------------------\n"));
    TABLEAU_DEBUG(printf("--- test_tableau_tri_selection1 ---\n"));
    TABLEAU_DEBUG(printf("-----------------------------------\n"));
        
    tableau_init_param(T, N, N, -1);
    tableau_display(T, N, "%4d", "T- avant");
    tableau_tri_selection(T, N);
    tableau_display(T, N, "%4d", "T- apres");
}
/* -------------------------------- */
void test_tableau_tri_selection2(void)
/* -------------------------------- */
{
    int T[N];
    
    TABLEAU_DEBUG(printf("-----------------------------------\n"));
    TABLEAU_DEBUG(printf("--- test_tableau_tri_selection2 ---\n"));
    TABLEAU_DEBUG(printf("-----------------------------------\n"));
    
    tableau_init_random(T, N, 11, 3, 17, 101);
    tableau_display(T, N, "%4d", "TR avant");
    tableau_tri_selection(T, N);
    tableau_display(T, N, "%4d", "TR apres");
}
/* ---------------------------------------- */
void test_tableau_tri_selection_reverse0(void)
/* ---------------------------------------- */
{
    int T[N];
    
    TABLEAU_DEBUG(printf("===========================================\n"));
    TABLEAU_DEBUG(printf("=== test_tableau_tri_selection_reverse0 ===\n"));
    TABLEAU_DEBUG(printf("===========================================\n"));
    
    tableau_init_param(T, N, 1, 1);
    tableau_display(T, N, "%4d", "T+ avant");
    tableau_tri_selection_reverse(T, N);
    tableau_display(T, N, "%4d", "T+ apres");
}
/* ---------------------------------------- */
void test_tableau_tri_selection_reverse1(void)
/* ---------------------------------------- */
{
    int T[N];
    
    TABLEAU_DEBUG(printf("-------------------------------------------\n"));
    TABLEAU_DEBUG(printf("--- test_tableau_tri_selection_reverse1 ---\n"));
    TABLEAU_DEBUG(printf("-------------------------------------------\n"));
    
    tableau_init_param(T, N, N, -1);
    tableau_display(T, N, "%4d", "T- avant");
    tableau_tri_selection_reverse(T, N);
    tableau_display(T, N, "%4d", "T- apres");
}
/* ---------------------------------------- */
void test_tableau_tri_selection_reverse2(void)
/* ---------------------------------------- */
{
    int T[N];
    
    TABLEAU_DEBUG(printf("-------------------------------------------\n"));
    TABLEAU_DEBUG(printf("--- test_tableau_tri_selection_reverse2 ---\n"));
    TABLEAU_DEBUG(printf("-------------------------------------------\n"));
    
    tableau_init_random(T, N, 11, 3, 17, 101);
    tableau_display(T, N, "%4d", "TR avant");
    tableau_tri_selection_reverse(T, N);
    tableau_display(T, N, "%4d", "TR apres");
}
/* -------------------------------- */
void test_tableau_tri_insertion0(void)
/* -------------------------------- */
{
    int T[N];
    
    TABLEAU_DEBUG(printf("===================================\n"));
    TABLEAU_DEBUG(printf("=== test_tableau_tri_insertion0 ===\n"));
    TABLEAU_DEBUG(printf("===================================\n"));
    
    tableau_init_param(T, N, 1, 1);
    tableau_display(T, N, "%4d", "T+ avant");
    tableau_tri_insertion(T, N);
    tableau_display(T, N, "%4d", "T+ apres");
}
/* -------------------------------- */
void test_tableau_tri_insertion1(void)
/* -------------------------------- */
{
    int T[N];
    
    TABLEAU_DEBUG(printf("-----------------------------------\n"));
    TABLEAU_DEBUG(printf("--- test_tableau_tri_insertion1 ---\n"));
    TABLEAU_DEBUG(printf("-----------------------------------\n"));
    
    tableau_init_param(T, N, N, -1);
    tableau_display(T, N, "%4d", "T- apres");
    tableau_tri_insertion(T, N);
    tableau_display(T, N, "%4d", "T- apres");
}
/* -------------------------------- */
void test_tableau_tri_insertion2(void)
/* -------------------------------- */
{
    int T[N];
    
    TABLEAU_DEBUG(printf("-----------------------------------\n"));
    TABLEAU_DEBUG(printf("--- test_tableau_tri_insertion2 ---\n"));
    TABLEAU_DEBUG(printf("-----------------------------------\n"));
    
    tableau_init_random(T, N, 11, 3, 17, 101);
    tableau_display(T, N, "%4d", "TR apres");
    tableau_tri_insertion(T, N);
    tableau_display(T, N, "%4d", "TR apres");
}
/* ---------------------------------------- */
void test_tableau_tri_insertion_reverse0(void)
/* ---------------------------------------- */
{
    int T[N];
    
    TABLEAU_DEBUG(printf("===========================================\n"));
    TABLEAU_DEBUG(printf("=== test_tableau_tri_insertion_reverse0 ===\n"));
    TABLEAU_DEBUG(printf("===========================================\n"));
    
    tableau_init_param(T, N, 1, 1);
    tableau_display(T, N, "%4d", "T+ avant");
    tableau_tri_insertion_reverse(T, N);
    tableau_display(T, N, "%4d", "T+ apres");
}
/* ---------------------------------------- */
void test_tableau_tri_insertion_reverse1(void)
/* ---------------------------------------- */
{
    int T[N];
    
    TABLEAU_DEBUG(printf("-------------------------------------------\n"));
    TABLEAU_DEBUG(printf("--- test_tableau_tri_insertion_reverse1 ---\n"));
    TABLEAU_DEBUG(printf("-------------------------------------------\n"));
    
    tableau_init_param(T, N, N, -1);
    tableau_display(T, N, "%4d", "T- avant");
    tableau_tri_insertion_reverse(T, N);
    tableau_display(T, N, "%4d", "T- apres");
}
/* ---------------------------------------- */
void test_tableau_tri_insertion_reverse2(void)
/* ---------------------------------------- */
{
    int T[N];
    
    TABLEAU_DEBUG(printf("-------------------------------------------\n"));
    TABLEAU_DEBUG(printf("--- test_tableau_tri_insertion_reverse2 ---\n"));
    TABLEAU_DEBUG(printf("-------------------------------------------\n"));
    
    tableau_init_random(T, N, 11, 3, 17, 101);
    tableau_display(T, N, "%4d", "TR avant");
    tableau_tri_insertion_reverse(T, N);
    tableau_display(T, N, "%4d", "TR apres");
}

/* --------------------- */
void test_tableau_max(void)
/* --------------------- */
{
    int T[N];
    int m;
    
    TABLEAU_DEBUG(printf("========================\n"));
    TABLEAU_DEBUG(printf("=== test_tableau_max ===\n"));
    TABLEAU_DEBUG(printf("========================\n"));
    
    tableau_init_random(T, N, 3, 2, 7, 17);
    tableau_display(T, N, "%4d", "TR avant");
    m = tableau_max(T, N);
    printf("max = %d\n", m);
}
/* ---------------------- */
void test_tableau_max2(void)
/* ---------------------- */
{
    int T[N];
    int m;
    
    TABLEAU_DEBUG(printf("=========================\n"));
    TABLEAU_DEBUG(printf("=== test_tableau_max2 ===\n"));
    TABLEAU_DEBUG(printf("=========================\n"));
    
    tableau_init_random(T, N, 3, 2, 7, 17);
    tableau_display(T, N, "%4d", "TR avant");
    m = tableau_max2(T, N);
    printf("max2 = %d\n", m);
}
/* ---------------------- */
void main_test_tableau(void)
/* ---------------------- */
{
    // ne rien ecrire en dessous de cette ligne
    
    TABLEAU_DEBUG(printf("=========================\n"));
    TABLEAU_DEBUG(printf("=== main_test_tableau ===\n"));
    TABLEAU_DEBUG(printf("=========================\n"));
    
#ifdef TEST0
    test_tableau_init_param0();
#endif
#ifdef TEST1
    test_tableau_init_param1();
#endif
#ifdef TEST2
    test_tableau_init_random();
#endif
    test_tableau_display();
#ifdef TEST3
    test_tableau_tri_selection0();
#endif
#ifdef TEST4 
    test_tableau_tri_selection1();
#endif
#ifdef TEST5
    test_tableau_tri_selection2();
#endif
#ifdef TEST6
    test_tableau_tri_selection_reverse0();
#endif
#ifdef TEST7
    test_tableau_tri_selection_reverse1();
#endif
#ifdef TEST8
    test_tableau_tri_selection_reverse2();
#endif
#ifdef TEST9
    test_tableau_tri_insertion0();
#endif
#ifdef TEST10
    test_tableau_tri_insertion1();
#endif
#ifdef TEST11
    test_tableau_tri_insertion2();
#endif
#ifdef TEST12
    test_tableau_tri_insertion_reverse0();
#endif
#ifdef TEST13
    test_tableau_tri_insertion_reverse1();
#endif
#ifdef TEST14
    test_tableau_tri_insertion_reverse2();
#endif
#ifdef TEST15
    test_tableau_max();
#endif
#ifdef TEST16
    test_tableau_max2();
#endif    
}