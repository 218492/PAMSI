#include "lista.hh"
#include "iostream"
using namespace std;

void lista::dodajdroge(int drog){
droga=drog;
}

void lista::zerujdroge(){
droga=0;
}

int lista::zwrocdroge(){
droga = 0;
for(int i=0; i<zwrocrozmiar(); i++){
droga=droga+zwrocwage(i);
}
return(droga);
}

int lista::przeszukajlistewaga(int waga){
wezel *temp;
temp=przod;
int j=0;
for(int i=0;i<(rozmiar_listy); i++){
if(temp->wagaa>=waga){j++;}
temp=temp->nastepny;
}
return(j);
}

int lista::przeszukajliste(int elem){
wezel *temp;
temp=przod;
for(int i=0;i<(rozmiar_listy); i++){
if(temp->element==elem){
return (temp->wagaa);}
temp=temp->nastepny;
}
return(-1);
}

void lista::dodajelementwaga(int elem,int waga){
wezel *temp = new wezel;
temp->wagaa=waga;
temp->element=elem;
int pozycja=0;
pozycja=przeszukajlistewaga(waga);
if(pozycja==0){     /*dodawanie na tyl listy*/
if(rozmiar_listy==0){
temp->nastepny=przod;
przod=temp;
tyl=temp;
}
else{
tyl->nastepny=temp;
temp->nastepny=NULL;
tyl=temp;
}
}
else if(pozycja==rozmiar_listy && rozmiar_listy!=0){/*dodawanie na przod*/
temp->nastepny=przod;
przod=temp;
}
else if(pozycja<rozmiar_listy){
wezel *temp2=new wezel;
wezel *temp3=new wezel;
temp2=przod;
for(int i=0;i<(rozmiar_listy-(pozycja+1));i++){ /*pozycja +1, bo szukamy wezla poprzedzajcego*/
temp2=temp2->nastepny;
}
temp3=temp2->nastepny;
temp2->nastepny=temp;
temp->nastepny=temp3;
}
else{
cout << "Poza zakresem" << endl;
rozmiar_listy--;
}
rozmiar_listy++;
}


void lista::dodajelementwaga(int elem,int pozycja,int waga){
wezel *temp = new wezel;
temp->wagaa=waga;
temp->element=elem;
if(pozycja==0){     /*dodawanie na tyl listy*/
if(rozmiar_listy==0){
temp->nastepny=przod;
przod=temp;
tyl=temp;
}
else{
tyl->nastepny=temp;
temp->nastepny=NULL;
tyl=temp;
}
}
else if(pozycja==rozmiar_listy && rozmiar_listy!=0){/*dodawanie na przod*/
temp->nastepny=przod;
przod=temp;
}
else if(pozycja<rozmiar_listy){
wezel *temp2=new wezel;
wezel *temp3=new wezel;
temp2=przod;
cout << "babelki" << endl;
for(int i=0;i<(rozmiar_listy-(pozycja+1));i++){ /*pozycja +1, bo szukamy wezla poprzedzajcego*/
cout << "3.1" << endl;
temp2=temp2->nastepny;
}
temp3=temp2->nastepny;
temp2->nastepny=temp;
temp->nastepny=temp3;
}
else{
cout << "Poza zakresem" << endl;
rozmiar_listy--;
}
rozmiar_listy++;
}

void lista::dodajelement(int elem, int pozycja){
wezel *temp = new wezel;
temp->element=elem;
if(pozycja==0){     /*dodawanie na tyl listy*/
if(rozmiar_listy==0){
temp->nastepny=przod;
przod=temp;
tyl=temp;
}
else{
tyl->nastepny=temp;
temp->nastepny=NULL;
tyl=temp;
}
}
else if(pozycja==rozmiar_listy && rozmiar_listy!=0){/*dodawanie na przod*/
temp->nastepny=przod;
przod=temp;
}
else if(pozycja<rozmiar_listy){
wezel *temp2=new wezel;
wezel *temp3=new wezel;
temp2=przod;
cout << rozmiar_listy;
for(int i=0;i<(rozmiar_listy-(pozycja+1));i++){ /*pozycja +1, bo szukamy wezla poprzedzajcego*/
cout << "3.1" << endl;
temp2=temp2->nastepny;
}
temp3=temp2->nastepny;
temp2->nastepny=temp;
temp->nastepny=temp3;
}
else{
cout << "Poza zakresem" << endl;
rozmiar_listy--;
}
rozmiar_listy++;
}

int lista::wyczyscliste(){
int x=zwrocrozmiar();
for(int i=0; i<x; i++){
usunelement(zwrocrozmiar()-1);
}
return(1);
}

int lista::usunelement(int pozycja){        /*usuwa element*/
if(pozycja>=rozmiar_listy){
cout << "Element nie istnieje." << endl;
return(1);
}
wezel *temp;
wezel *temp2;
temp=przod;
for(int i=0;i<(rozmiar_listy-(pozycja+2)); i++){
temp=temp->nastepny;
}
if(pozycja==rozmiar_listy-1){
przod=temp->nastepny;
rozmiar_listy--;
return(temp->element);
}
temp2=temp->nastepny;
temp->nastepny=temp2->nastepny;
rozmiar_listy--;
return(temp2->element);
}

lista::lista(){
przod=NULL;
tyl=NULL;
rozmiar_listy=0;
}

void lista::wyswietlrozmiar(){
cout << rozmiar_listy << endl;
}

int lista::zwrocrozmiar(){
return(rozmiar_listy);
}

int lista::zwrocwage(int pozycja){
if(pozycja>=rozmiar_listy){
cout << "Element nie istnieje." << endl;
return(1);
}
wezel *temp;
temp=przod;
for(int i=0;i<(rozmiar_listy-(pozycja+1)); i++){
temp=temp->nastepny;
}
return(temp->wagaa);
}

int lista::zwrocelement(int pozycja){
if(pozycja>=rozmiar_listy){
cout << "Element nie istnieje." << endl;
return(1);
}
wezel *temp;
temp=przod;
for(int i=0;i<(rozmiar_listy-(pozycja+1)); i++){
temp=temp->nastepny;
}
return(temp->element);
}

int lista::wyswietlelement(int pozycja){
if(pozycja>=rozmiar_listy){
cout << "Element nie istnieje." << endl;
return(1);
}
wezel *temp;
temp=przod;
for(int i=0;i<(rozmiar_listy-(pozycja+1)); i++){
temp=temp->nastepny;
}
cout << temp->element << endl;
if(temp->wagaa!=0){
cout << "Waga: " << temp->wagaa << endl;}
return(0);
}

void lista::wyswietl(){
for(int i=0; i<(rozmiar_listy); i++){
wyswietlelement(i);}
}

int lista::wyjmijelement(int pozycja){
if (wyswietlelement(pozycja)!=1){
return(usunelement(pozycja));}
return(0);
}

void lista::wypelnij(int ilosc){
for(int i=0; i<ilosc; i++){
dodajelement(0, 0);
}
}
