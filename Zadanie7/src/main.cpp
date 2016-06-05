#include "graf.hh"
#include "stoper.h"
#include "iostream"
#include <cstdlib>
using namespace std;
int main(){
graf graficzek;
srand(time(NULL));
int iloscwezlow=10000;
int wezel1=rand()%iloscwezlow+1;
int wezel2=rand()%iloscwezlow+1;
stoper stoper;
for(int i=1; i<=iloscwezlow; i++){
graficzek.dodajwezel(i);
}
for(int j=1; j<=(iloscwezlow/2); j++) {
graficzek.dodajkrawedz(j, j*2);
graficzek.dodajkrawedz(j, (j*2)-1);
}
cout << "Wezel1 = " << wezel1 << endl;
cout << "Wezel2 = " << wezel2 << endl;

stoper.start();
graficzek.przeszukajwszerz(wezel1,wezel2);
cout << "Przeszukanie wszerz: ";
stoper.stop();
cout << "--------------------------" << endl;
stoper.start();
graficzek.przeszukajwzdluz(wezel1,wezel2);
cout << "Przeszukanie wglab: ";
stoper.stop();

graficzek.sasiedzi(1).wyswietl();
}
