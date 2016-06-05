#include "graf.hh"
#include <iostream>
using namespace std;
void graf::dodajwezel(int wartoscwezla){
lista s;
s.dodajelement(wartoscwezla, 0);
tablicalist[wartoscwezla]=s;
}

void graf::dodajkrawedz(int wezel1, int wezel2, int waga){
tablicalist[wezel1].dodajelementwaga(wezel2,tablicalist[wezel1].zwrocrozmiar(), waga);
tablicalist[wezel2].dodajelementwaga(wezel1,tablicalist[wezel2].zwrocrozmiar(), waga);
}

int graf::zwazkrawedz(int wezel1, int wezel2){
lista s1=sasiedzi(wezel1);
lista s2=sasiedzi(wezel2);
int waga1=s1.przeszukajliste(wezel2);
int waga2=s2.przeszukajliste(wezel1);
if(waga1!=-1){
if(waga1==waga2){
return(waga1);}
else{cout << "To nie powinno sie nigdy wydrukowac" << endl; return(0);}
}
else{cout << "Nie ma takiej krawedzi" << endl; return(0);}
}

lista graf::sasiedzi(const int wezel){
lista *lsasiadow=new lista;
*lsasiadow=tablicalist[wezel];
lista *listasasiadow=new lista;
for(int i=1; i<lsasiadow->zwrocrozmiar(); i++){
listasasiadow->dodajelementwaga(lsasiadow->zwrocelement(i), lsasiadow->zwrocwage(i));}
return(*listasasiadow);
}

bool graf::czyjestsasiadem(const int wezel1,const int wezel2){
lista *temp=new lista;
*temp=sasiedzi(wezel1);
if(temp->przeszukajliste(wezel2)!=-1){return(true);}
else return(false);
}
void graf::przygotuj(){odwiedzonewezly.wyczyscliste(); znalezionodroge=false; doodwiedzenia.wyczyscliste(); najkrotszadroga=1000000;}

int graf::bb(const int wezel1, const int wezel2){
int droga;
int waga;
int wezel;
int k;
odwiedzonewezly.dodajelement(wezel1, odwiedzonewezly.zwrocrozmiar());
if(wezel1==wezel2&&doodwiedzenia.zwrocrozmiar()==0){return(0);}
//cout << "Odwiedzono wezel: " << wezel1 << endl;
if(czyjestsasiadem(wezel1, wezel2)==1){
waga=zwazkrawedz(wezel1, wezel2);
tablicatras[wezel2].dodajdroge(tablicatras[wezel1].zwrocdroge()+waga);
for(int i=0; i<tablicatras[wezel1].zwrocrozmiar();i++){
tablicatras[wezel2].dodajelementwaga(tablicatras[wezel1].zwrocelement(i), tablicatras[wezel2].zwrocrozmiar(), tablicatras[wezel1].zwrocwage(i));
}
if(tablicatras[wezel2].przeszukajliste(wezel1)==-1){tablicatras[wezel2].dodajelementwaga(wezel1, tablicatras[wezel2].zwrocrozmiar(), waga);}
cout << "Znaleziono droge :) " << endl;
droga=tablicatras[wezel2].zwrocdroge();
cout << "Dlugosc drogi: " << droga << endl;
if(droga<najkrotszadroga){
najkrotszadroga=droga;
}
cout << "Wezly, ktore trzeba pokonac, zeby osiagnac cel: " << endl;
tablicatras[wezel2].wyswietl();
tablicatras[wezel2].wyczyscliste();
cout << "Obecnie najkrotsza droga to: " << najkrotszadroga << endl;
cout << endl;
//cout << "Rozwidlenia: " << endl;
//rozwidlenia.wyswietl();
bb(rozwidlenia.zwrocelement(rozwidlenia.zwrocrozmiar()-1), wezel2); /// Powinno dodac sie wezel, w ktorym nastapilo rozwidlenie
if(rozwidlenia.zwrocrozmiar()!=0){rozwidlenia.usunelement(rozwidlenia.zwrocrozmiar()-1);}
}
lista ls=sasiedzi(wezel1);
k=0;
for(int i=0; i<ls.zwrocrozmiar(); i++){
waga=ls.zwrocwage(i);
wezel=ls.zwrocelement(i);
if(doodwiedzenia.przeszukajliste(wezel)==-1&&odwiedzonewezly.przeszukajliste(wezel)==-1&&wezel!=wezel2){/// Nieodwiedzone wezly sa tylko dodawane poki co, do edycji
doodwiedzenia.dodajelementwaga(wezel, waga); // Badamy sasiadow, wrzucamy ich do kolejki przeszukania w kolejnosci od najmniejszej wagi do najwiekszej
if(k>0){rozwidlenia.dodajelementwaga(wezel1, 0, waga);}
k++;
}
}

if(doodwiedzenia.zwrocrozmiar()==0){return(0);}
waga=doodwiedzenia.zwrocwage(doodwiedzenia.zwrocrozmiar()-1);
//cout << "Waga: " << waga << endl;
wezel=doodwiedzenia.usunelement(doodwiedzenia.zwrocrozmiar()-1); // Bierzemy element do zwiedzenia
//cout << "Wezel: " << wezel << endl;
droga=tablicatras[wezel1].zwrocdroge()+waga;  // Wyznaczamy droge do elementu, ktory chcemy zwiedzic
//cout << "Droga: " << droga << endl;
tablicatras[wezel].dodajdroge(droga);     // Dodajemy droge potrzebna do dotarcia do wezla
//cout << tablicatras[wezel].zwrocdroge();
if(czyjestsasiadem(wezel1, wezel)){
for(int i=0; i<tablicatras[wezel1].zwrocrozmiar();i++){
tablicatras[wezel].dodajelementwaga(tablicatras[wezel1].zwrocelement(i), tablicatras[wezel].zwrocrozmiar(), tablicatras[wezel1].zwrocwage(i));
}
if(tablicatras[wezel].przeszukajliste(wezel1)==-1){tablicatras[wezel].dodajelementwaga(wezel1, tablicatras[wezel].zwrocrozmiar(), waga);}  // Dodajemy liste poprzedniego elementu
}
//cout << "Wyswietlamy:" << endl;
//tablicatras[wezel].wyswietl();

bb(wezel, wezel2);
}

int graf::wykonajbb(const int wezel1, const int wezel2){
przygotuj();
wezelstartowy=wezel1;
bb(wezel1, wezel2);
return(0);
}


