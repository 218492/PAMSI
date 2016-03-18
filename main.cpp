#include <iostream>
#include <ctime>
#include "stoper.h"
using namespace std;
class  tabd{            /*tworzymy klase, w ktorej bedziemy zajmowac sie nasza tablica*/
int rozmiar;            /*rozmiar tablicy*/
int* w1;                /*wskaznik1*/
int* w2;                /*wskaznik2*/
void zniszcztab2(){     /*metoda pozwalajaca zniszczyc tablice, na ktora wskazuje wskaznik2*/
    delete[] w2;
    w2=NULL;
    }
void powieksz1(int x){  /*metoda realizujaca powiekszanie tablicy o stala wartosc*/
    w2=w1;              /*wskaźnik w2 wskazuje teraz na stara tablice, a w1 bedzie nowa tablica*/
    int rozmiar2=rozmiar;
    rozmiar=rozmiar+x;  /*powiekszamy rozmiar*/
    w1=new int[rozmiar];/*tworzymy tablice o nowym rozmiarze*/
    for(int i=0; i<(rozmiar2); i++){
    w1[i]=w2[i];
    }
    zniszcztab2();
    }
void powieksz2(){
    w2=w1;              /*wskaźnik w2 wskazuje teraz na stara tablice, a w1 bedzie nowa tablica*/
    int rozmiar2=rozmiar;
    rozmiar=rozmiar*2;  /*powiekszamy rozmiar*/
    w1=new int[rozmiar];/*tworzymy tablice o nowym rozmiarze*/
    for(int i=0; i<(rozmiar2); i++){
    w1[i]=w2[i];
    }
    zniszcztab2();
    }
public:
tabd(){             /*konstruktor*/
    rozmiar=10;             /*przyjmujemy rozmiar rowny 10*/
    w1=new int[rozmiar];    /*alokujemy pamiec*/
    }
~tabd(){      /*destruktor*/
    delete[] w1;
    w1=NULL;
    }
void wypelnijtab1(int ilosc, int j){     /*metoda pozwalajaca na wypelnienie tablicy numerem indeksu +1, w ktorej zastosowalem taktyka powiekszenia o stala*/
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
void wypelnijtab2(int ilosc){           /*metoda pozwalajaca na wypelnienie tablicy numerem indeksu +1, w ktorej zastosowalem metode podwajania rozmiaru*/
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
void wypisztab(){       /*metoda, ktora wypisuje wszystkie elementy tablicy*/
    for(int i=0; i<rozmiar; i++){
    cout<<w1[i]<<'\t';
    }
    cout<<endl;
    }
};

class interfejs{
public:
void przygotuj(tabd tab, stoper s) = 0;
void wykonaj() = 0;
};

int main(){
int x=10;
stoper s;
cout << "Tablica nr 1" << endl;
tabd tab1;
s.start();
tab1.wypelnijtab1(x, 1);   /*wypelnianie tablicy 100-ma elementami z zastosowaniem powiekszania o 1*/
s.stop();
cout << "Tablica nr 2" << endl;
tabd tab2;
s.start();
tab2.wypelnijtab1(x, 500); /*wypelnianie tablicy 100-ma elementami z zastosowaniem powiekszania o 500*/
s.stop();
cout << "Tablica nr 3" << endl;
tabd tab3;
s.start();
tab3.wypelnijtab2(x);     /*wypelnianie tablicy 100-ma elementami z zastosowaniem podwajania*/
s.stop();
}
