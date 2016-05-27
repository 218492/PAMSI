#include "lista.h"
#include <string>
using namespace std;

class hasz{
lista tablicalist[1000];
public:
int const rozmiar=1000;
hasz();
int funkcjahaszujaca(string klucz);
int otrzymajelement(string klucz);
int usunelement(string klucz);
int dodajelement(int wartosc, string klucz);
};
