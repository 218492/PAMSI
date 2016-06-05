#include "igraf.h"
class graf{
public:
lista *tablicalist = new lista[100000];
lista *tablicatras = new lista[100000];
lista odwiedzonewezly;
lista doodwiedzenia;
lista rozwidlenia;
int wezelstartowy;
int najkrotszadroga=1000000;
bool znalezionodroge=false;
int bb(const int, const int);
public:
int branchbound(const int, const int);
int zwazkrawedz(const int, const int);
void dodajwezel(int);
void dodajkrawedz(int, int, int);
lista sasiedzi(const int);
bool czyjestsasiadem(const int,const int);
int wykonajbb(const int wezel1, const int wezel2);
void przygotuj();
};
