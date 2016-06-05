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
int droga=0;
int waga;
int wezel, wezelx;
odwiedzonewezly.dodajelement(wezel1, odwiedzonewezly.zwrocrozmiar());
if(wezel1==wezel2&&doodwiedzenia.zwrocrozmiar()==0){cout << "Najkrotszadroga wynosi: " << najkrotszadroga << endl; return(0);}
//cout << "Startujemy z wezelka: " << wezel1 << endl;
if(czyjestsasiadem(wezel1, wezel2)==1){
droga=0;
waga=zwazkrawedz(wezel1, wezel2);
//cout << "Wazymy ostatnia krawedz: " << waga  << endl;
tablicatras[wezel2].dodajelementwaga(wezel1, tablicatras[wezel2].zwrocrozmiar(), waga);
for(int i=0; i<tablicatras[wezel1].zwrocrozmiar();i++){
tablicatras[wezel2].dodajelementwaga(tablicatras[wezel1].zwrocelement(i),tablicatras[wezel2].zwrocrozmiar(), tablicatras[wezel1].zwrocwage(i));
}
for(int i=0; i<tablicatras[wezel2].zwrocrozmiar();i++){
droga=droga+tablicatras[wezel2].zwrocwage(i);
}

droga=droga+waga;
cout << "Znaleziono droge :) " << endl;
cout << "Dlugosc drogi: " << droga << endl;
if(droga<najkrotszadroga){
najkrotszadroga=droga;
}
//cout << "TRASA: " << endl;
//tablicatras[wezel2].wyswietl();
//tablicatras[wezel2].wyczyscliste();
}
lista ls=sasiedzi(wezel1);
for(int i=0; i<ls.zwrocrozmiar(); i++){
waga=ls.zwrocwage(i);
wezel=ls.zwrocelement(i);
if(doodwiedzenia.przeszukajliste(wezel)==-1&&wezel!=wezel2&&odwiedzonewezly.przeszukajliste(wezel)==-1){/// Nieodwiedzone wezly sa tylko dodawane poki co, do edycji
doodwiedzenia.dodajelementwaga(wezel, waga); // Badamy sasiadow, wrzucamy ich do kolejki przeszukania w kolejnosci od najmniejszej wagi do najwiekszej
}
}
//cout << "Tablica tras2: " << endl;
//tablicatras[wezel1].wyswietl();
if(doodwiedzenia.zwrocrozmiar()==0){cout << "Najkrotsza droga wynosi: " << najkrotszadroga << endl; return(0);}
waga=doodwiedzenia.zwrocwage(doodwiedzenia.zwrocrozmiar()-1);
//cout << "Waga: " << waga << endl;
wezel=doodwiedzenia.usunelement(doodwiedzenia.zwrocrozmiar()-1); // Bierzemy element do zwiedzenia
//cout << "Odwiedzamy wezel: " << wezel << endl;
if(czyjestsasiadem(wezel1, wezel)){
//cout << "sprawdzenie1" << endl;
tablicatras[wezel].dodajelementwaga(wezel1, tablicatras[wezel].zwrocrozmiar(), zwazkrawedz(wezel, wezel1));
for(int i=0; i<tablicatras[wezel1].zwrocrozmiar();i++){
tablicatras[wezel].dodajelementwaga(tablicatras[wezel1].zwrocelement(i),tablicatras[wezel].zwrocrozmiar(), tablicatras[wezel1].zwrocwage(i));
}
}
else{
//cout << "sprawdzenie2" << endl;
lista s=sasiedzi(wezel);
for(int i=0; i<s.zwrocrozmiar(); i++){
wezelx=s.zwrocelement(i);
if(czyjestsasiadem(wezel, wezelx)==1&&odwiedzonewezly.przeszukajliste(wezelx)!=-1){break;}
}
//cout << "wezel do przekopiowania trasy: " << wezelx << endl;
tablicatras[wezel].dodajelementwaga(wezelx, tablicatras[wezel].zwrocrozmiar(), zwazkrawedz(wezel, wezelx));
for(int i=0; i<tablicatras[wezelx].zwrocrozmiar();i++){
tablicatras[wezel].dodajelementwaga(tablicatras[wezelx].zwrocelement(i),tablicatras[wezel].zwrocrozmiar(), tablicatras[wezelx].zwrocwage(i));
}
}
bb(wezel, wezel2);
}

int graf::wykonajbb(const int wezel1, const int wezel2){
przygotuj();
if(czyjestsasiadem(wezel1, wezel2)){cout << "Najkrotsza droga wynosi: " << zwazkrawedz(wezel1, wezel2); return(0);}
bb(wezel1, wezel2);
return(0);
}


