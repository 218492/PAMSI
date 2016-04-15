#ifndef kolejka_hh
#define kolejka_hh
#include "interfejsk.h"
#include "lista.hh"
class kolejka: public interfejsk{
lista l;
public:
virtual void dodajelement(int element);
virtual int usunelement();
virtual int wyswietlelement(int pozycja);
virtual void wyswietlrozmiar();
virtual int wyjmijelement();
virtual void wyswietl();
virtual void wypelnij(int ilosc);
};
#endif
