#include "graf.hh"
#include "iostream"
using namespace std;
int main(){
graf graficzek;
graficzek.dodajwezel(1);
graficzek.dodajwezel(2);
graficzek.dodajwezel(28);
graficzek.dodajwezel(5);
graficzek.dodajkrawedz(1,2);
graficzek.dodajkrawedz(28,2);
graficzek.dodajkrawedz(5,1);
graficzek.dodajkrawedz(28,5);
graficzek.czyjestsasiadem(5,1);
}
