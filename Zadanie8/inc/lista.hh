#ifndef lista_hh
#define lista_hh
#include "interfejs.hh"
class wezel {
friend class lista;
int element;
int wagaa;
wezel * nastepny;
};

class lista: public interfejs, private wezel{
friend class kolejka;
friend class stos;
int rozmiar_listy;
int droga;
wezel *przod;
wezel *tyl;
public:
lista();
void dodajdroge(int drog);
void zerujdroge();
virtual void dodajelement(int element, int pozycja);
virtual void dodajelementwaga(int wezelek,int pozycja, int waga);
virtual void dodajelementwaga(int wezelek,int waga);
virtual int usunelement(int pozycja);
virtual int zwrocelement(int pozycja);
virtual int wyswietlelement(int pozycja);
virtual void wyswietlrozmiar();
virtual int wyjmijelement(int pozycja);
virtual void wyswietl();
virtual void wypelnij(int ilosc);
virtual int zwrocrozmiar();
virtual int zwrocwage(int pozycja);
virtual int przeszukajliste(int elem);
virtual int przeszukajlistewaga(int waga);
virtual int wyczyscliste();
int zwrocdroge();
};
#endif
