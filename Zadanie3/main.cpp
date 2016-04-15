#include "lista.hh"
#include "iostream"
#include "kolejka.hh"
using namespace std;
int main(){
lista L;
L.wypelnij(10);
L.przeszukajizmierz(0);
L.wypelnij(100);
L.przeszukajizmierz(0);
L.wypelnij(1000);
L.przeszukajizmierz(0);
L.wypelnij(1000000);
L.przeszukajizmierz(0);
cout << endl << endl << endl;
kolejka k;
k.dodajelement(5);
k.dodajelement(1);
k.dodajelement(10);
k.wyjmijelement();
cout << endl << endl << endl;
lista L2;
L2.dodajelement(9,0);
L2.dodajelement(8,0);
L2.dodajelement(7,0);
L2.dodajelement(6,0);
L2.dodajelement(5,0);
L2.dodajelement(4,0);
L2.dodajelement(3,0);
L2.dodajelement(2,0);
L2.dodajelement(1,0);
L2.dodajelement(0,0);
L2.wyswietl();
L2.usunelement(9);
cout << endl;
L2.wyswietl();
}
