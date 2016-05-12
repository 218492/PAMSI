#include "hasz.h"
#include <string>
#include <iostream>

hasz::hasz(){
}

int hasz::funkcjahaszujaca(string klucz){
int v=0;
unsigned int i=0;
for(i=0;i<klucz.size()-1;i++){
v+=klucz[i];}
int indeks=v%rozmiar;
return(indeks);
}

int hasz::otrzymajelement(string klucz){
int indeks=funkcjahaszujaca(klucz)%rozmiar;
return(tablicalist[indeks].przeszukajliste(klucz));
}

int hasz::usunelement(string klucz){
int indeks=funkcjahaszujaca(klucz)%rozmiar;
return(tablicalist[indeks].usunelement(klucz));
}

int hasz::dodajelement(int wartosc, string klucz){
int indeks=funkcjahaszujaca(klucz)%rozmiar;
tablicalist[indeks].dodajelement(wartosc, 0, klucz);
return(0);
}
