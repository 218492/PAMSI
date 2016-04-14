#ifndef interfejs_hh
#define interfejs_hh
class interfejs {
public:
virtual void dodajelement(int, int)=0;
virtual int usunelement(int)=0;
virtual void otrzymajelement(int)=0;
virtual void wyswietlrozmiar()=0;
virtual void wyswietl()=0;
};
#endif
