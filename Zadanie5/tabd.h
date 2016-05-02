#include "interfejst.h"
#include "stoper.h"
#include "lista.h"
#ifndef TABD
#define TABD
class  tabd: public interfejs{            /*tworzymy klase, w ktorej bedziemy zajmowac sie nasza tablica*/
stoper s;               /*stoper*/
int rozmiar;            /*rozmiar tablicy*/
int* w1;                /*wskaznik1*/
int* w2;                /*wskaznik2*/
lista *wl1;             /*wskaznik na liste*/
void zniszcztab2();    /*metoda pozwalajaca zniszczyc tablice, na ktora wskazuje wskaznik2*/
void powieksz1(int x); /*metoda realizujaca powiekszanie tablicy o stala wartosc*/
void powieksz2();      /*metoda realizujaca powiekszanie tablicy przez podwojenie*/
void wypelnijtab1(int ilosc, int j);     /*metoda pozwalajaca na wypelnienie tablicy numerem indeksu +1, w ktorej zastosowalem taktyka powiekszenia o stala*/
void wypelnijtab2(int ilosc);           /*metoda pozwalajaca na wypelnienie tablicy numerem indeksu +1, w ktorej zastosowalem metode podwajania rozmiaru*/
public:
tabd();             /*konstruktor*/
~tabd();      /*destruktor*/
void tablicalist();
void wypisztab();                       /*metoda, ktora wypisuje wszystkie elementy tablicy*/
virtual void wykonaj(int ilosc);
virtual void wykonaj(int ilosc, int j);
virtual void przygotuj();
};
#endif
