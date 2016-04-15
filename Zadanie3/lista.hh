#ifndef lista_hh
#define lista_hh
#include "interfejs.hh"
class wezel {
friend class lista;
int element;
wezel * nastepny;
};

class lista: public interfejs, private wezel{
friend class kolejka;
int rozmiar_listy;
wezel *przod;
wezel *tyl;
public:
lista();
virtual void dodajelement(int element, int pozycja);
virtual int usunelement(int pozycja);
virtual int wyswietlelement(int pozycja);
virtual void wyswietlrozmiar();
virtual void wyjmijelement(int pozycja);
virtual void wyswietl();
virtual void wypelnij(int ilosc);
virtual void przeszukajizmierz(int pozycja);
};
#endif
