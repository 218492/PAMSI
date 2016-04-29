#include "igraf.h"
class graf{
lista tablicalist[100];
public:
void dodajwezel(int);
void dodajkrawedz(int, int);
lista sasiedzi(const int);
bool czyjestsasiadem(const int,const int);
};
