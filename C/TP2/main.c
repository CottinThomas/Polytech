/* -------------- */
/* --- main.c --- */
/* -------------- */

#include "param_perl.h" // tests unitaires

#include "tableau_test.h"
#include "fraction_test.h"

/* ---------------------------------- */
int main (int argc, const char * argv[])
/* ---------------------------------- */
{
    main_test_tableau();
    main_test_fraction();
    return 0;
}
