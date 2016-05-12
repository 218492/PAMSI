#include "lista.h"
#include "hasz.h"
#include <iostream>
int main(){
hasz h;
string k,j;
int wartosc;
cout << "Podaj klucz dodania elementu" << endl;
cin >> k;
cout << "Podaj wartosc dodania elementu" << endl;
cin >> wartosc;
h.dodajelement(wartosc, k);
cout << "Podaj hasz odczytu elementu" << endl;
cin >> j;
cout << "Otrzymujemy element: " << h.otrzymajelement(j) << endl;
h.usunelement(j);
cout << "Usuwamy element" << endl;
cout << "Probujemy otrzymac usuniety element: " << h.otrzymajelement(j) << endl;
}
