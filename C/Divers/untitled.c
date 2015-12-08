#include <stdio.h>
#include <stdlib.h>

void afficheTab(int* tab, int taille){
	printf("[");
	int i;
	for(i = 0; i<taille-1; i++)
		printf("%d,",tab[i]);
	printf("%d]\n", tab[taille-1]);
}

void swap(int* a, int* b){
	int temp = a[0];
	a[0] = b[0];
	b[0] = temp;
}

void triBulle(int* tab, int taille){

	int tailleSave = taille;

	while(taille >= 2){
		int i;
		for(i = 0; i <= taille-2; i++){
			if(tab[i] > tab[i+1])
				swap(&tab[i],&tab[i+1]);
		}
		taille = taille - 1;
	}
}
/*
int* fusion(int* tab1, int* tab2, int taille1, int taille2){
	int tabComplet[taille1+taille2];
	if(tab1[taille1-1] <= tab2[0]){
		int i;
		for(i = 0; i < taille1; i++)
			tabComplet[i] = tab1[i];
		for(i = 0; i < taille2; i++)
			tabComplet[taille1+i] = tab2[i];
	}
	return tabComplet;

}
*/
void insertTab(int* tab, int size, int pos, int val){
	for(int i = size; i>pos; i++)
		tab[size] = tab[size-1];
	tab[pos] = val;
}

void fusion(int* tab1, int* tab2, int* tabComplet, int taille1, int taille2){
	int tailleC = 0;
	for(int i = 0; i < taille1; i++){
		tabComplet[i] = tab1[i];
	}
	tailleC = taille1;
	for(int i = 0; i < taille2; i++){
		int insert = 0;
		int j = 0;
		while(insert = 0 && j < tailleC){
			if(tabComplet[j] > tab2[i]){
				insertTab(tabComplet,tailleC,j,tab2[i]);
				insert = 1;
			}
			j = j+1;
		}
		if(insert = 0){
			tabComplet[tailleC] = tab2[i];
		}
		tabComplet = tabComplet+1;
	}
}

int rechercheDicho(int* tab, int taille, int val){
	int debut = 0;
	int fin = taille-1;
	int find = 0;
	do{
		int mid = (debut+fin)/2;
		if(tab[mid] == val){
			return mid;
		}
		else if(val > tab[mid])
			debut = mid+1;
		else fin = mid-1;
	} while(debut <= fin);
	return -1;
}

int main (int argc, const char * argv[]){
	int a = 5;
	int b = 7;
	printf("###### TEST SWAP ######\n");
	printf("Avant le swap : a = %d, b = %d\n",a,b);
	swap(&a,&b);
	printf("Après le swap : a = %d, b = %d\n",a,b);
	printf("###### TEST TRI BULLE ######\n");
	int taille = 12;
	int tab[12]= {10,2,6,3,4,8,6,1,2,7,456,123};
	printf("Avant le tri, tab = ");
	afficheTab(tab,12);
	triBulle(tab,12);
	printf("Après le tri, tab = ");
	afficheTab(tab,12);
	/*
	printf("###### TEST FUSION ######\n");
	int tab1[5] = {1,2,3,4,5};
	int tab2[5] = {6,7,8,9,10};
	int tabComplet[10];
	fusion(tab1,tab2,tabComplet,5,5);
	afficheTab(tabComplet,10);
	*/
	printf("###### TEST RECHERCHE ######\n");
	int tabR[10] = {1,2,3,4,5,6,7,8,9,10};
	int ex = 0;
	while(ex == 0){
		int toFind;
		printf("Quel nombre souhaitez-vous rechercher ?\n");
		scanf("%d",&toFind);
		int pos = rechercheDicho(tabR, 10, toFind);
		if(pos == -1)
			printf("La valeur %d n'est pas présente dans le tableau.\n", toFind);
		else
			printf("La valeur %d est dans la case d'indice %d.\n", toFind, pos);
		printf("Again ? (oui = 0/non = 1)");
		scanf("%d",&ex);
	}
	

}