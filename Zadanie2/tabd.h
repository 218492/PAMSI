#include "stoper.h"
#ifndef TABD
#define TABD
class  tabd{            /*tworzymy klase, w ktorej bedziemy zajmowac sie nasza tablica*/
friend class stos;
stoper s;               /*stoper*/
int rozmiar;            /*rozmiar tablicy*/
int* w1;                /*wskaznik1*/
int* w2;                /*wskaznik2*/
void zniszcztab2();    /*metoda pozwalajaca zniszczyc tablice, na ktora wskazuje wskaznik2*/
void powieksz1(int x); /*metoda realizujaca powiekszanie tablicy o stala wartosc*/
void powieksz2();      /*metoda realizujaca powiekszanie tablicy przez podwojenie*/
void wypelnijtab1(int ilosc, int j);     /*metoda pozwalajaca na wypelnienie tablicy numerem indeksu +1, w ktorej zastosowalem taktyka powiekszenia o stala*/
void wypelnijtab2(int ilosc);           /*metoda pozwalajaca na wypelnienie tablicy numerem indeksu +1, w ktorej zastosowalem metode podwajania rozmiaru*/
public:
tabd();             /*konstruktor*/
~tabd();      /*destruktor*/
void wypisztab();                       /*metoda, ktora wypisuje wszystkie elementy tablicy*/
};
#endif
