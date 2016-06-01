#include "igraf.h"
class graf{
lista tablicalist[100000];
lista odwiedzonewezly;
lista doodwiedzenia;
bool znalezionodroge=false;
int przeszukajwszrz(const int, const int);
int przeszukajwzdl(const int, const int);
public:
void dodajwezel(int);
void dodajkrawedz(int, int);
lista sasiedzi(const int);
bool czyjestsasiadem(const int,const int);
int przeszukajwszerz(const int,const int);
int przeszukajwzdluz(const int,const int);
void przygotuj();
};
