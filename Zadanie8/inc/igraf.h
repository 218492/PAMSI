#include "lista.hh"
class igraf{
virtual void dodajwezel(int)=0;
virtual void dodajkrawedz(int, int, int)=0;
virtual int zwazkrawedz(int, int)=0;
virtual lista sasiedzi(const int)=0;
virtual bool czyjestsasiadem(const int,const int)=0;
virtual int przeszukajwszerz(const int,const int)=0;
virtual int przeszukajwszrz(const int, const int)=0;
virtual int przeszukajwzl(const int, const int)=0;
virtual int przeszukajwzdluz(const int,const int)=0;
virtual void przygotuj()=0;
};
