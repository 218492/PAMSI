#ifndef stos_hh
#define stos_hh
#include "interfejss.h"
#include "lista.hh"
class stos: public interfejss{
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
