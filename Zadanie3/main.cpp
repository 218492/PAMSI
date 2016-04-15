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
k.wyswietl();
k.usunelement();
k.wyswietl();
cout << endl << endl << endl;
}
