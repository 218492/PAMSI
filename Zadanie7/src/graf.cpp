#include "graf.hh"
void graf::dodajwezel(int wartoscwezla){
lista s;
s.dodajelement(wartoscwezla, 0);
tablicalist[wartoscwezla]=s;
}
void graf::dodajkrawedz(int wezel1, int wezel2){
tablicalist[wezel1].dodajelement(wezel2, tablicalist[wezel1].zwrocrozmiar());
tablicalist[wezel2].dodajelement(wezel1, tablicalist[wezel2].zwrocrozmiar());
}
lista graf::sasiedzi(const int wezel){
lista lsasiadow;
lsasiadow=tablicalist[wezel];
lsasiadow.usunelement(0);
lsasiadow.wyswietl();
return(lsasiadow);
}
bool graf::czyjestsasiadem(const int wezel1,const int wezel2){
lista temp;
temp=sasiedzi(wezel1);
if(temp.przeszukajliste(wezel2)==1){return(true);}
else return(false);
}


