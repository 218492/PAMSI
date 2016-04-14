#ifndef lista_hh
#define lista_hh
#include "interfejs.hh"
class wezel {
friend class lista;
int element;
wezel * nastepny;
};

class lista: public interfejs, private wezel{
int rozmiar_listy;
wezel *przod;
wezel *tyl;
public:
lista();
virtual void dodajelement(int element, int pozycja);
virtual int usunelement(int pozycja);
virtual void wyswietl();
virtual void wyswietlrozmiar();
};
#endif
