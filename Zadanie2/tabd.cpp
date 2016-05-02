#include "tabd.h"
#include <iostream>
#include <ctime>
using namespace std;

void tabd::zniszcztab2(){     /*metoda pozwalajaca zniszczyc tablice, na ktora wskazuje wskaznik2*/
    delete[] w2;
    w2=NULL;
    }
void tabd::powieksz1(int x){  /*metoda realizujaca powiekszanie tablicy o stala wartosc*/
    w2=w1;              /*wskaźnik w2 wskazuje teraz na stara tablice, a w1 bedzie nowa tablica*/
    int rozmiar2=rozmiar;
    rozmiar=rozmiar+x;  /*powiekszamy rozmiar*/
    w1=new int[rozmiar];/*tworzymy tablice o nowym rozmiarze*/
    for(int i=0; i<(rozmiar2); i++){
    w1[i]=w2[i];
    }
    zniszcztab2();
    }
void tabd::powieksz2(){
    w2=w1;              /*wskaźnik w2 wskazuje teraz na stara tablice, a w1 bedzie nowa tablica*/
    int rozmiar2=rozmiar;
    rozmiar=rozmiar*2;  /*powiekszamy rozmiar*/
    w1=new int[rozmiar];/*tworzymy tablice o nowym rozmiarze*/
    for(int i=0; i<(rozmiar2); i++){
    w1[i]=w2[i];
    }
    zniszcztab2();
    }
tabd::tabd(){             /*konstruktor*/
    rozmiar=10;             /*przyjmujemy rozmiar rowny 10*/
    w1=new int[rozmiar];    /*alokujemy pamiec*/
    }
tabd::~tabd(){      /*destruktor*/
    delete[] w1;
    w1=NULL;
    }
void tabd::wypelnijtab1(int ilosc, int j){     /*metoda pozwalajaca na wypelnienie tablicy numerem indeksu +1, w ktorej zastosowalem taktyka powiekszenia o stala*/
    for(int i=0; i<ilosc; i++){
        if(rozmiar>i) {
        w1[i]=i+1;
        }
        else {
        powieksz1(j);
        w1[i]=i+1;
        }
    }
    }
void tabd::wypelnijtab2(int ilosc){           /*metoda pozwalajaca na wypelnienie tablicy numerem indeksu +1, w ktorej zastosowalem metode podwajania rozmiaru*/
    for(int i=0; i<ilosc; i++){
    if(rozmiar>i) {
    w1[i]=i+1;
    }
    else {
    powieksz2();
    w1[i]=i+1;
    }
    }
    }
void tabd::wypisztab(){       /*metoda, ktora wypisuje wszystkie elementy tablicy*/
    for(int i=0; i<rozmiar; i++){
    cout<<w1[i]<<'\t';
    }
    cout<<endl;
    }
