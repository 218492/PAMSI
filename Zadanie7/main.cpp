#include "graf.hh"
#include "iostream"
using namespace std;
int main(){
graf graficzek;
graficzek.dodajwezel(1);
graficzek.dodajwezel(2);
cout << "wezel1" << endl;
graficzek.dodajkrawedz(1,2);
}
