#include <stdio.h>
#include <stdlib.h>

/* -------------- */
int somme_for(int n){
    int i;
    int s;
    s = 0;
    for(i=1; i<=n; i++) {
        s += i;
    }    
    return s;
}

int somme_do(int n){
    int i =1;
    int s = 0;
    do{
        s += i;
        i++;
    }while(i<=n);
    return s;
}

int somme_while(int n){
    int i =1;
    int s = 0;
    while(i<=n){
        s += i;
        i++;
    }
    return s;
}

int somme_math(int n){
    return (n*(n+1))/2;
}

void test_boucles(void){
    int n = 10;
    int s_for = 0;
    int s_do = 0;
    int s_while = 0;
    int s_math = 0;
    
    puts("=== test boucles ===");
    
    s_for = somme_for(n);
    s_do = somme_do(n);
    s_while = somme_while(n);
    s_math = somme_math(n);
    
    printf("n          = %d\n", n);
    printf("s_for      = %d\n", s_for);
    printf("s_do_while = %d\n", s_do);
    printf("s_while    = %d\n", s_while);
    printf("s_math     = %d\n", s_math);

    if(s_for==s_do && s_while==s_do && s_math==s_do) printf("calculs corrects\n\n");
    else printf("calculs incorrects\n\n");
}

int is_prime(int n){
    int prime = 0;
    for(int i=2;i<n;i++){
        if(n%i==0) prime = 1;
    }
    return prime;
}

int is_prime_fast(int n){
    int i=2;
    if(n%i==0)
        return 1;
    i++;
    while(i*i<=n){
        if(n%i==0)
            return 1;
        i = i+2;
    }
    return 0;
}

int next_prime(int n){
    int next;
    if(n%2==0) next = n+1;
    else next = n+2;

    if(next%2==0 && next != 2) next++;
    while(is_prime_fast(next) == 1){
        next +=2;
    }
    return next;
}

void display_primes(int n){
    int nbligne = 0;
    if(n<2) printf("Erreur : n < 2");
    else {
        for(int i = 2; i<n; i=next_prime(i)){
            printf("%5d\t", i);
            nbligne++;
            if(nbligne==10){
                printf("\n");
                nbligne=0;
            } 
        }

    }
    printf("\n");
}

void test_prime(void){
    int n;
    scanf("%d",&n);
    while(n!=-1){
        if(is_prime(n)==0)
            printf("%d est premier[NO FAST]\n", n);
        else
            printf("%d n'est pas premier[NO FAST]\n", n);

        if(is_prime_fast(n)==0)
            printf("%d est premier[FAST]\n", n);
        else
            printf("%d n'est pas premier[FAST]\n", n);
        printf("Le prochain premier est %d\n", next_prime(n));
        scanf("%d",&n);
    }
    printf("Liste des premiers de 1 a 102 : \n");
    display_primes(102);

}

int fact_rec(int n){
    if (n==0) return 0;
    if(n==1)
        return 1;
    else 
        return (fact_rec(n-1))*n;
}

int fact(int n){
    if(n==0) return 0;
    int fact = 1;
    for (int i=1; i<=n;i++)
        fact = fact*i;
    return fact;
}

void test_factorielle(void){
    puts("version recursive");
    // test des cas particuliers
    printf("%d! = %d\n", 0, fact_rec(0));
    printf("%d! = %d\n", 1, fact_rec(1));
    
    // cas general
    printf("%d! = %d\n", 5, fact_rec(5));
    
    puts("version non recursive");
    // test des cas particuliers
    printf("%d! = %d\n", 0, fact(0));
    printf("%d! = %d\n", 1, fact(1));
    
    // cas general
    printf("%d! = %d\n", 5, fact_rec(5));
}

int cnp(int n, int p){
    if(p==0 || n==p) return 1;
    return fact(n)/(fact(p)*fact(n-p));
}

int cnp_fast(int n, int p){
    if(p==0 || n==p) return 1;
    int pdt = p+1;
    for (int i=p+2; i<=n;i++){
        pdt = pdt * i;
    }
    int cnp = pdt/fact(n-p);
    return cnp;
}

int cnp_smart(int n, int p){
    if(p<n/2)
        return cnp(n,n-p);
    return cnp(n,p);
}

void test_cnp(void){
    int n, p;
    
    n = 3; p = 1; printf("cnp(%d, %d) = %d\n", n, p, cnp(n,p));

    puts("");
    n = 5; p = 0; printf("cnp(%d, %d) = %d\n", n, p, cnp(n,p));
    n = 5; p = 1; printf("cnp(%d, %d) = %d\n", n, p, cnp(n,p));
    n = 5; p = 2; printf("cnp(%d, %d) = %d\n", n, p, cnp(n,p));
    n = 5; p = 3; printf("cnp(%d, %d) = %d\n", n, p, cnp(n,p));
    n = 5; p = 4; printf("cnp(%d, %d) = %d\n", n, p, cnp(n,p));
    n = 5; p = 5; printf("cnp(%d, %d) = %d\n", n, p, cnp(n,p));
    
    puts("");
    n = 5; p = 0; printf("cnp(%d, %d) = %d\n", n, p, cnp_fast(n,p));
    n = 5; p = 1; printf("cnp(%d, %d) = %d\n", n, p, cnp_fast(n,p));
    n = 5; p = 2; printf("cnp(%d, %d) = %d\n", n, p, cnp_fast(n,p));
    n = 5; p = 3; printf("cnp(%d, %d) = %d\n", n, p, cnp_fast(n,p));
    n = 5; p = 4; printf("cnp(%d, %d) = %d\n", n, p, cnp_fast(n,p));
    n = 5; p = 5; printf("cnp(%d, %d) = %d\n", n, p, cnp_fast(n,p));
    
    puts("");
    n = 6; p = 0; printf("cnp(%d, %d) = %d\n", n, p, cnp_fast(n,p));
    n = 6; p = 1; printf("cnp(%d, %d) = %d\n", n, p, cnp_fast(n,p));
    n = 6; p = 2; printf("cnp(%d, %d) = %d\n", n, p, cnp_fast(n,p));
    n = 6; p = 3; printf("cnp(%d, %d) = %d\n", n, p, cnp_fast(n,p));
    n = 6; p = 4; printf("cnp(%d, %d) = %d\n", n, p, cnp_fast(n,p));
    n = 6; p = 5; printf("cnp(%d, %d) = %d\n", n, p, cnp_fast(n,p));
    n = 6; p = 6; printf("cnp(%d, %d) = %d\n", n, p, cnp_fast(n,p));
}

void display_pascal(int n){
    for(int i=0;i<=n;i++){
        printf("%5d",cnp(n,i));
    }
    printf("\n\n");
}

void display_pascal_fast(int n){
    for(int i=0;i<=n;i++){
        printf("%5d",cnp_fast(n,i));
    }
    printf("\n\n");
}

void display_pascal_smart(int n){
    for(int i=0;i<=n;i++){
        printf("%5d",cnp_smart(n,i));
    }
    printf("\n\n");
}

void test_pascal(void){
    int i, n;
    n=13;
    
    puts("=== test_pascal ===");
    printf("n=%d\n", n);
    
    for(i=1; i<=n; i++) {
        display_pascal(i);
    }
    printf("\n\n");
    for(i=1; i<=n; i++) {
        display_pascal_fast(i);
    }
    for(i=1; i<=n; i++) {
        display_pascal_smart(i);
    }  
}

int main (int argc, const char * argv[]){
    puts("Hello, World!\n");
    
    test_boucles();
    test_prime();
    test_factorielle();
    test_cnp();
    test_pascal();
    return 0;
}
