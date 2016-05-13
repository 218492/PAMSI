#include "lista.hh"
class igraf{
virtual void dodajwezel(int)=0;
virtual void dodajkrawedz(int, int)=0;
virtual lista sasiedzi(const int)=0;
virtual bool czyjestsasiadem(const int,const int)=0;
};
