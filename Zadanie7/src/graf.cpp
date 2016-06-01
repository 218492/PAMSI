#include "graf.hh"
#include <iostream>
using namespace std;
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
lista *lsasiadow=new lista;
*lsasiadow=tablicalist[wezel];
lista *listasasiadow=new lista;
for(int i=1; i<lsasiadow->zwrocrozmiar(); i++){
listasasiadow->dodajelement(lsasiadow->zwrocelement(i),listasasiadow->zwrocrozmiar());}
return(*listasasiadow);
}
bool graf::czyjestsasiadem(const int wezel1,const int wezel2){
lista *temp=new lista;
*temp=sasiedzi(wezel1);
if(temp->przeszukajliste(wezel2)==1){return(true);}
else return(false);
}
void graf::przygotuj(){odwiedzonewezly.wyczyscliste(); znalezionodroge=false; doodwiedzenia.wyczyscliste();}

int graf::przeszukajwzdl(const int wezel1, const int wezel2){
int wezel;
if(znalezionodroge==true){return(1);}
//cout << "Odwiedzono wezel: " << wezel1 << endl;
odwiedzonewezly.dodajelement(wezel1, odwiedzonewezly.zwrocrozmiar());
if(czyjestsasiadem(wezel1, wezel2)==1){
cout << "Znaleziono droge :)" << endl;
znalezionodroge=true;
return(0);
}/*najpierw sprawdzamy czy dane wierzcholki sa sasiadami*/
else {
lista ls=sasiedzi(wezel1);
for(int i=0; i<ls.zwrocrozmiar(); i++){
for(i=0; i<ls.zwrocrozmiar(); i++){
wezel=ls.zwrocelement(i);
if (odwiedzonewezly.przeszukajliste(wezel)==0){break;}
}
if(odwiedzonewezly.przeszukajliste(wezel)==0&&znalezionodroge==false){
przeszukajwzdl(wezel, wezel2);}
else if(odwiedzonewezly.przeszukajliste(wezel)==0&&znalezionodroge==true){return(1);}
else if(znalezionodroge==false){
//cout << "Nie znaleziono drogi" << endl;
 return(0);}
else {return(0);}
}
};
return(0);
}

int graf::przeszukajwszrz(const int wezel1, const int wezel2){
int wezel;
if(znalezionodroge==true){return(1);}
//cout << "Odwiedzono wezel: " << wezel1 << endl;
odwiedzonewezly.dodajelement(wezel1, odwiedzonewezly.zwrocrozmiar());
if(czyjestsasiadem(wezel1, wezel2)==1){
cout << "Znaleziono droge :)" << endl;
znalezionodroge=true;
return(0);
}/*najpierw sprawdzamy czy dane wierzcholki sa sasiadami*/
else {
lista ls=sasiedzi(wezel1);
for(int i=0; i<ls.zwrocrozmiar(); i++){
    for(int i=0; i<ls.zwrocrozmiar(); i++){
    wezel=ls.zwrocelement(i);
    if (znalezionodroge==true){return(0);}
    if (odwiedzonewezly.przeszukajliste(wezel)==0&&znalezionodroge==false){
 //   cout << "Sprawdzamy sasiadow wezla numer: " << wezel << endl;
    if(czyjestsasiadem(wezel, wezel2)==1){
    cout << "Znaleziono droge :)" << endl;
    znalezionodroge=true;
    return(0);
    }
    else doodwiedzenia.dodajelement(wezel, doodwiedzenia.zwrocrozmiar());
 //   cout << "Dodano wezel nr: " << wezel << " do kolejki odwiedzenia." << endl;
    }
    }
if(odwiedzonewezly.przeszukajliste(doodwiedzenia.zwrocelement(0))==0&&znalezionodroge==false){
int wezell=doodwiedzenia.zwrocelement(0);
doodwiedzenia.usunelement(0);
przeszukajwszrz(wezell, wezel2);}
else if(odwiedzonewezly.przeszukajliste(wezel)==0&&znalezionodroge==true){return(1);}
else if(znalezionodroge==false){cout << "Nie znaleziono drogi" << endl; return(0);}
else {return(0);}
}
};
return(0);
}
int graf::przeszukajwszerz(const int wezel1, const int wezel2){
przygotuj();
return(przeszukajwszrz(wezel1, wezel2));
}

int graf::przeszukajwzdluz(const int wezel1, const int wezel2){
przygotuj();
return(przeszukajwzdl(wezel1, wezel2));
}

