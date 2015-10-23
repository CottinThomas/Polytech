/* ----------------- */
/* --- tableau.h --- */
/* ----------------- */

#include <stdio.h>
#include "tableau.h"

/* -------------------------- */
void tableau_zero(int *T, int n)
/* -------------------------- */
{
	int cpt;
	for(cpt = 0; cpt<n; cpt++){
		T[cpt] = 0;
	}
}
/* --------------------------------------------------- */
void tableau_init_param(int *T, int n, int x0, int xstep)
/* --------------------------------------------------- */
{
	int cpt;
	for(cpt = 0; cpt<n; cpt++){
		T[cpt] = x0 + cpt*xstep;
	}
}
/* -------------------------------------------------------------- */
void tableau_init_random(int *T, int n, int a, int x0, int b, int m)
/* -------------------------------------------------------------- */
{
	int cpt;
	T[0]=x0;
	for(cpt = 1; cpt<n; cpt++){
		T[cpt] = (a*T[cpt-1]+b)%m;
	}
}
/* ------------------------------------------------------ */
void tableau_display(int *T, int n, char *format, char *nom)
/* ------------------------------------------------------ */
{
    int i;
    
    if(format == NULL) format == " %d ";
    if(nom) printf("%s\n", nom);
    
    for(i=0; i<n; i++) {
        printf(format, T[i]);
    }
    printf("\n");
}
/* ----------------------------------- */
void tableau_tri_selection(int *T, int n)
/* ----------------------------------- */
{
	int i;
	for(i = 0; i < n-1; i++){
		int indicePlusPetit = i;
		int j;
		for(j = i+1;j<n;j++){
			if(T[j]<T[indicePlusPetit])
				indicePlusPetit = j;
		}
		if(indicePlusPetit != i){
			int t = T[indicePlusPetit];
			T[indicePlusPetit] = T[i];
			T[i] = t;
		}
	}
}
/* ------------------------------------------- */
void tableau_tri_selection_reverse(int *T, int n)
/* ------------------------------------------- */
{
	int i;
	for(i = n-1; i >= 0; i--){
		int indicePlusGrand = i;
		int j;
		for(j = i-1;j>=0;j--){
			if(T[j]>T[indicePlusGrand])
				indicePlusGrand = j;
		}
		if(indicePlusGrand != i){
			int t = T[indicePlusGrand];
			T[indicePlusGrand] = T[i];
			T[i] = t;
		}
	}
}
/* ----------------------------------- */
void tableau_tri_insertion(int *T, int n)
/* ----------------------------------- */
{
	int i;
	for(i=0;i<n;i++){
		int val = T[i];
		int j=i;
		while(j>0 && T[j-1]>val){
			T[j]=T[j-1];
			j--;
		}
		T[j]=val;
	}
}
/* ------------------------------------------- */
void tableau_tri_insertion_reverse(int *T, int n)
/* ------------------------------------------- */
{
	int i;
	for(i=n-1;i>=0;i--){
		int val = T[i];
		int j=i;
		while(j<n-1  && T[j+1]<val){
			T[j]=T[j+1];
			j++;
		}
		T[j]=val;
	}
}
 
/* ------------------------ */
int tableau_max(int *T, int n)
/* ------------------------ */
{
	int maxI=T[0];
	int i;
	for(i=0;i<n;i++){
		if(T[i]>T[maxI])
			maxI = i;
	}
    return T[maxI];
}
/* ------------------------- */
int tableau_max2(int *T, int n)
/* ------------------------- */
{
	/* // MOINS EFFICACE [2 parcours]
	int maxTab = tableau_max(T,n);
	int max2=T[0];
	int i;
	for(i=0;i<n;i++){
		if(T[i]>max2 && T[i] != maxTab)
			max2 = T[i];
	}
    return max2;
    */

    int max1=T[0];
    int max2=T[2];
	int i;
	for(i=0;i<n;i++){
		if(T[i]>max1){
			max2 = max1;
			max1 = T[i];
		}
		else if(T[i]>max2){
			max2 = T[i];
		}
	}
    return max2;
}
