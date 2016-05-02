#include <iostream>
#include <ctime>
#include "stoper.h"
#include "tabd.h"
#include "interfejs.h"
using namespace std;

int main(){
int x=5000;
cout << "Tablica nr 1" << endl;
tabd tab1,tab2,tab3;
tab1.przygotuj();
tab1.wykonaj(x, 1);   /*wypelnianie tablicy x-ma elementami z zastosowaniem powiekszania o 1*/
cout << "Tablica nr 2" << endl;
tab2.przygotuj();
tab2.wykonaj(x, 500); /*wypelnianie tablicy x-ma elementami z zastosowaniem powiekszania o 500*/
cout << "Tablica nr 3" << endl;
tab3.przygotuj();
tab3.wykonaj(x);        /*wypelnianie tablicy x-ma elementami z zastosowaniem podwajania*/
}
