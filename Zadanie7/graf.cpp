#include "graf.hh"
void graf::dodajwezel(int wartoscwezla){
lista s;
s.dodajelement(wartoscwezla, 0);
tablicalist[wartoscwezla]=s;
}
void graf::dodajkrawedz(int wezel1, int wezel2){
tablicalist[wezel1].dodajelement(wezel2, 1);
tablicalist[wezel1].wyswietl();
tablicalist[wezel2].dodajelement(wezel1, 1);
}
lista graf::sasiedzi(const int wezel){
return(tablicalist[wezel]);
}
bool graf::czyjestsasiadem(const int,const int){return(true);}


