#include "lista.h"
#include "hasz.h"
#include "stoper.h"
#include <iostream>
#include <cstdlib>
#include <sstream>
using namespace std;
int main(){
hasz h;
string k,j;
int v2;
int wartosc;
int const ilosc=1000000;
int tab[ilosc];
stoper s;
srand(time(NULL));
s.start();
for(int i=0;i<ilosc;i++){
v2 = rand()%1000000+1;
tab[i]=v2;
ostringstream ss;
ss << v2;
j = ss.str();
wartosc=i;
h.dodajelement(wartosc, j);
}
s.stop();
s.start();
for(int i=0;i<ilosc;i++){
ostringstream ss;
ss << tab[i];
k = ss.str();
}
s.stop();
}


