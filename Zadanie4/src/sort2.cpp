#include "sort2.hpp"

void quicksort2(int *tab,int lewy, int prawy){
int pivot=tab[(lewy+prawy)/2];              /*wyznaczamy pivota*/
int i=lewy,j=prawy,n;
do{                                   /*przeszukujemy tablice w poszukiwaniu elementu mniejszego od pivota z prawej strony*/
while(tab[j]>pivot)
j--;
while(tab[i]<pivot)                         /*przeszukujemy tablice w poszukiwaniu elementu wiekszego od pivota z lewej strony*/
i++;
if(i<=j){                                    /*zamieniamy miejscami i z j*/
n=tab[i];
tab[i]=tab[j];
tab[j]=n;
i++;
j--;
}}while(i<=j);
if( lewy < j ) quicksort2( tab, lewy, j );
if( prawy > i ) quicksort2( tab, i, prawy );
}


void merge(int tab[], const int dol, const int srodek, const int gora)
{
int *temp = new int[gora-dol+1];
int lewy = dol;
int prawy = srodek+1;
int obecny = 0;
while(lewy <= srodek && prawy <= gora) {
if(tab[lewy] <= tab[prawy]) {
temp[obecny] = tab[lewy];
lewy++;
}
else {
temp[obecny] = tab[prawy];
prawy++;
}
obecny++;
}
if(lewy > srodek) {
for(int i=prawy; i <= gora;i++) {
temp[obecny] = tab[i];
obecny++;
}
}
else {
for(int i=lewy; i <= srodek; i++) {
temp[obecny] = tab[i];
obecny++;
}
}
for(int i=0; i<=gora-dol;i++) {
tab[i+dol] = temp[i];
}
delete[] temp;
}

void mergesort(int tab[], const int dol, const int gora)
{
if(dol >= gora) {
return;}
int srodek = (dol+gora)/2;
mergesort(tab, dol, srodek);
mergesort(tab, srodek+1, gora);
merge(tab, dol, srodek, gora);
}


