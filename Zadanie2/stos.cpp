#include <iostream>
#include "stos.h"
using namespace std;
stos::stos(){
rozmiar=10;
w1=new int[rozmiar];
rozmiarstosu=0;
}
void stos::push(int element){
if (rozmiarstosu==(rozmiar-1)) powieksz2();
w1[rozmiarstosu]=element;
rozmiarstosu=rozmiarstosu+1;
}

void stos::pop(){
if (rozmiarstosu==0) {
cout << "Stos jest pusty" << endl;}
else{
cout << w1[rozmiarstosu-1] << endl;
rozmiarstosu=rozmiarstosu-1;
}
}


int stos::rozmiarstsu(){
cout << rozmiarstosu << endl;
return(rozmiarstosu);}
