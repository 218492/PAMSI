#ifndef lista_hh
#define lista_hh
#include "interfejsl.h"
#include <string>
using namespace std;
class wezel {
friend class lista;
int element;
string klucz;
wezel * nastepny;
};

class lista: public interfejsl, private wezel{
int rozmiar_listy;
wezel *przod;
wezel *tyl;
public:
lista();
virtual void dodajelement(int element, int pozycja);
virtual void dodajelement(int element, int pozycja, string klucz);
virtual int usunelement(int pozycja);
virtual int wyswietlelement(int pozycja);
virtual void wyswietlrozmiar();
virtual int wyjmijelement(int pozycja);
virtual void wyswietl();
virtual void wypelnij(int ilosc);
virtual void przeszukajizmierz(int pozycja);
virtual int zwrocrozmiar();
virtual int przeszukajliste(string klucz);
virtual int usunelement(string klucz);
};
#endif
