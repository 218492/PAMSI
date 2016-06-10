#include "kik.h"
#include <iostream>
using namespace std;

void kik::przygotujdominmax(){
for(int i=0; i<9; i++){
plansza2[i]=plansza[i];
}
licznik=0;
}

void kik::wyswietl(int plan[9]){
char *planszac = new char[9];
for(int i=0; i<9; i++){
if(i==3||i==6){cout << " |" << endl << endl;}
if(plansza[i]==1){planszac[i]='x';}
else if(plan[i]==-1){planszac[i]='o';}
else {plan[i]=' ';}
cout  << " | " << planszac[i];
if(i==8){cout << " |" << endl;}
}
cout << endl;
}

int kik::minimax(int gracz, int plansz[9]){
int x, znaczek;
if(gracz==1){znaczek=1;}
else if(gracz==2){znaczek=-1;}
//cout << "MINMAXTEST" << endl;
//wyswietl(plansz);
for(int i=0; i<9; i++){
if(plansz[i]!=1&&plansz[i]!=-1){
plansz[i]=znaczek;
x=czywygranaAI(plansz);
/// Sprawdzamy czy wygramy
if(gracz==1){
if(x>0){if(licznik==0){licznik=i;} return(licznik);}//AI sprawdza czy wygra jak wstawi znaczek do i
}
if(gracz==2){//AI sprawdza czy przegra jak wstaiw
if(x<0){if(licznik==0){licznik=i;} return(licznik);}
}
plansz[i]=-znaczek;//AI sprawdza co by się stało, gdyby wstawić znaczek przeciwnika
x=czywygranaAI(plansz);
/// Sprawdzamy czy przeciwnik wygra
if(gracz==1){
if(x<0){if(licznik==0){licznik=i;} return(licznik);}//AI sprawdza przeciwnik czy przeciwnik wygra, wstawiając znaczek przeciwny
}
if(gracz==2){
if(x>0){if(licznik==0){licznik=i;} return(licznik);}
}
plansz[i]=znaczek;
if(x==0){//Jezeli nikt nie wygra, AI wciela sie w role drugiego gracza i testuje dalej
//cout << "ZERO" << endl;
if(gracz==1){minimax(2, plansz);}
else if(gracz==2){minimax(1, plansz);}
}
}
}
if(licznik!=0){
return(licznik);}
else
for(int i=0; i<9; i++){
if(plansz[i]!=1&&plansz[i]!=-1){
return(i);//jeżeli nie ma opcji, zwracamy cokolwiek
}
}
}

int kik::czywygranaAI(int plansz[9]){
int zwyciezca=0;
for(int i=0; i<3; i++){//Wygrana w pionie
if(plansz[i]+plansz[i+3]+plansz[i+6]==3){zwyciezca=1;}
if(plansz[i]+plansz[i+3]+plansz[i+6]==-3){zwyciezca=2;}
}
for(int i=0; i<9; i=i+3){// Wygrana w poziomie
if(plansza[i]+plansz[i+1]+plansz[i+2]==3){zwyciezca=1;}
if(plansza[i]+plansz[i+1]+plansz[i+2]==-3){zwyciezca=2;}
}
if(plansz[0]+plansz[4]+plansz[8]==3){zwyciezca=1;}//Wygrane w ukosie
if(plansz[0]+plansz[4]+plansz[8]==-3){zwyciezca=2;}
if(plansz[2]+plansz[4]+plansz[6]==3){zwyciezca=1;}
if(plansz[2]+plansz[4]+plansz[6]==-3){zwyciezca=2;}
if(zwyciezca==1){return(1);}
else if(zwyciezca==2){return(-1);}
else{return(0);}
}

void kik::zacznijgre(){
for(int i=0; i<9; i++){
plansza[i]=0;}
wybortrybu();
}

bool kik::odnowa(){
int i;
cout << "Czy chcesz zaczac od nowa?" << endl;
cout << "1. Tak" << endl;
cout << "2. Nie" << endl;
cin >> i;
if(i==1){return(true);}
else if(i==2){return(false);}
else{cout << "Blad" << endl; if(odnowa()==true){zacznijgre();}}
return(0);
}

void kik::graczvkomputer(const int poziom){
while(0<1){
wyswietl();
ruch(1);
if(czywygrana()==1){break;}
wyswietl();
ruchkomputera();
if(czywygrana()==1){break;}
}
}

int kik::poziomtrudnosci(){
int temp;
cout << "Wybierz poziom trudności: " << endl;
cout << "1. Łatwy" << endl;
cin >> temp;
if(temp==1){return(1);}
else{cout << "Blad" << endl; poziomtrudnosci(); return(0);}
}

void kik::ruchkomputera(){
przygotujdominmax();
plansza[minimax(2, plansza2)]=-1;
}

void kik::wybortrybu(){
int temp;
cout << "Wybierz tryb: " << endl;
cout << "1. gracz vs komputer" << endl;
cout << "2. gracz vs gracz" << endl;
cin >> temp;
tryb=temp;
if(tryb==1){
temp=poziomtrudnosci();
graczvkomputer(temp);
}
else if(tryb==2){
graczvgracz();
}
else{cout << "Blad." << endl;
wybortrybu();
}
}

void kik::ruch(const int gracz){
int pole;
cout << "Ruch gracza nr: " << gracz << endl << "Wybierz numer pola(1-9): ";
cin >> pole;
pole=pole-1;
if(pole>=0&&pole<=8){
if(plansza[pole]!=1&&plansza[pole]!=-1){
if(gracz==1){plansza[pole]=1;}
if(gracz==2){plansza[pole]=-1;}
}
else{
cout << "Wybrane pole jest zajete" << endl;
ruch(gracz);
}
}
else{
cout << "Wybrane pole nie istnieje" << endl;
ruch(gracz);
}
}

void kik::wyswietl(){
char *planszac = new char[9];
for(int i=0; i<9; i++){
if(i==3||i==6){cout << " |" << endl << endl;}
if(plansza[i]==1){planszac[i]='x';}
else if(plansza[i]==-1){planszac[i]='o';}
else {planszac[i]=' ';}
cout  << " | " << planszac[i];
if(i==8){cout << " |" << endl;}
}
cout << endl;
}

int kik::czywygrana(){
int zwyciezca=0;
for(int i=0; i<3; i++){//Wygrana w pionie
if(plansza[i]+plansza[i+3]+plansza[i+6]==3){zwyciezca=1;}
if(plansza[i]+plansza[i+3]+plansza[i+6]==-3){zwyciezca=2;}
}
for(int i=0; i<9; i=i+3){// Wygrana w poziomie
if(plansza[i]+plansza[i+1]+plansza[i+2]==3){zwyciezca=1;}
if(plansza[i]+plansza[i+1]+plansza[i+2]==-3){zwyciezca=2;}
}
if(plansza[0]+plansza[4]+plansza[8]==3){zwyciezca=1;}//Wygrane w ukosie
if(plansza[0]+plansza[4]+plansza[8]==-3){zwyciezca=2;}
if(plansza[2]+plansza[4]+plansza[6]==3){zwyciezca=1;}
if(plansza[2]+plansza[4]+plansza[6]==-3){zwyciezca=2;}

if(zwyciezca!=1||zwyciezca!=2){
int j=0;
for(int i=0; i<9; i++){
if(plansza[i]!=0){j++;}
if(j==9){zwyciezca=3;}
}
}

if(zwyciezca==1||zwyciezca==2){
wyswietl();
cout << "Zwycieza gracz nr: " << zwyciezca << endl;
if(odnowa()==true){zacznijgre();};
return(1);
}
if(zwyciezca==3){
wyswietl();
cout << "Remis!" << endl;
if(odnowa()==true){zacznijgre();};
return(1);
}
else return(0);
}


void kik::graczvgracz(){
int i=1;
while(0<1){
wyswietl();
ruch(i);
if(czywygrana()==1){break;}
if(i==1){i=2;}
else if(i==2){i=1;}
}
}
