#include <iostream>

class kik{
int tryb=0;
int licznik=0;
int *plansza=new int[9];
int *plansza2=new int[9];
void przygotujdominmax();
void ruch(int gracz);
int czywygrana();
int czywygranaAI(int plansz[9]);
void ruchkomputera();
void wybortrybu();
void wyswietl();
void wyswietl(int plan[9]);
void graczvgracz();
int poziomtrudnosci();
void graczvkomputer(const int poziom);
bool odnowa();
int minimax(int gracz, int plansz[9]);
public:
void zacznijgre();
};

/* 0 1 2
   3 4 5
   6 7 8
*/
