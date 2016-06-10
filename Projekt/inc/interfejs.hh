#ifndef interfejs_hh
#define interfejs_hh
class interfejs {
public:
virtual int usunelement(int)=0;
virtual int wyjmijelement(int)=0;
virtual void wyswietlrozmiar()=0;
virtual int zwrocrozmiar()=0;
virtual int zwrocelement(int)=0;
virtual void wyswietl()=0;
virtual void wypelnij(int)=0;
virtual int przeszukajliste(int)=0;
virtual int wyswietlelement(int pozycja)=0;
virtual int wyczyscliste()=0;
};
#endif
