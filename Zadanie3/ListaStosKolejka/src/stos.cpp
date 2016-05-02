#include "stos.h"
#include "lista.hh"
void stos::dodajelement(int element){
l.dodajelement(element, 0);
}
int stos::usunelement(){
return(l.usunelement(0));
}

int stos::wyswietlelement(int pozycja){
l.wyswietlelement(pozycja);
return(0);
}
void stos::wyswietlrozmiar(){
l.wyswietlrozmiar();
}
int stos::wyjmijelement(){
return(l.wyjmijelement(0));
}
void stos::wyswietl(){
l.wyswietl();
}
void stos::wypelnij(int ilosc){
l.wypelnij(ilosc);
}
