#include "kolejka.hh"
#include "lista.hh"
void kolejka::dodajelement(int element){
l.dodajelement(element, 0);
}
int kolejka::usunelement(){
return(l.usunelement(l.rozmiar_listy-1));
}

int kolejka::wyswietlelement(int pozycja){
l.wyswietlelement(pozycja);
return(0);
}
void kolejka::wyswietlrozmiar(){
l.wyswietlrozmiar();
}
int kolejka::wyjmijelement(){
return(l.wyjmijelement(l.rozmiar_listy-1));
}
void kolejka::wyswietl(){
l.wyswietl();
}
void kolejka::wypelnij(int ilosc){
l.wypelnij(ilosc);
}
