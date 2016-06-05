#include "graf.hh"
#include "stoper.h"
#include "iostream"
#include <cstdlib>
using namespace std;
int main(){

/*
graf graficzek;
graficzek.dodajwezel(1);
graficzek.dodajwezel(2);
graficzek.dodajwezel(3);
graficzek.dodajwezel(4);
graficzek.dodajwezel(5);
graficzek.dodajwezel(6);
graficzek.dodajwezel(7);
graficzek.dodajwezel(8);
graficzek.dodajwezel(9);
*/

/* DZIALA
graficzek.dodajkrawedz(1,2,1);
graficzek.dodajkrawedz(2,3,2);
graficzek.dodajkrawedz(2,4,3);
graficzek.dodajkrawedz(3,5,3);
graficzek.dodajkrawedz(4,5,1);
*/

/* DZIALA
graficzek.dodajkrawedz(1,2,1);
graficzek.dodajkrawedz(2,5,2);
graficzek.dodajkrawedz(5,6,29);
graficzek.dodajkrawedz(1,3,2);
graficzek.dodajkrawedz(3,7,5);
graficzek.dodajkrawedz(7,6,7);
graficzek.dodajkrawedz(1,8,10);
graficzek.dodajkrawedz(8,6,5);
//graficzek.dodajkrawedz(5,6,1);
//graficzek.dodajkrawedz(6,7,1);
//graficzek.sasiedzi(1).wyswietl();
*/

graf graficzek;
srand(time(NULL));
int iloscwezlow=10000;
int wezel1=rand()%iloscwezlow+1;
int wezel2=rand()%iloscwezlow+1;
//int wezel1=7;
//int wezel2=5;
stoper stoper;
for(int i=1; i<=iloscwezlow; i++){
graficzek.dodajwezel(i);
}
for(int j=1; j<=(iloscwezlow/2); j++) {
graficzek.dodajkrawedz(j, j*2, rand()%10+1);
graficzek.dodajkrawedz(j, (j*2)-1, rand()%10+1);
graficzek.dodajkrawedz(j+3, (j*2), rand()%10+1);
}
cout << "Wezel1 = " << wezel1 << endl;
cout << "Wezel2 = " << wezel2 << endl;
stoper.start();
graficzek.wykonajbb(wezel1, wezel2);
cout << "BranchNBound: ";
stoper.stop();

}
