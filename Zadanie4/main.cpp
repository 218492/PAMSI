#include <iostream>
#include <ctime>
#include <cstdlib>

#include "sort2.hpp"
#include "node.hpp"
#include "list.hpp"
#include "stack.hpp"
#include "queue.hpp"
#include "stoper.hpp"

using namespace std;

int main()
{
Queue kolejka;
Stoper stoper;
int j;
kolejka.push(10);
kolejka.push(100);
kolejka.push(1000);
kolejka.push(1000000);
kolejka.push(100000000);
cout << "Rozmiar kolejki = " << kolejka.size() << endl;
int rozmiar=kolejka.size();
for(int i=0;i<rozmiar;i++){
int data=kolejka.get_data();
int *tab = new int[data];
cout << "Ilosc elementow = " << data << endl;
for(int x=0;x<data;x++){
j=data-x;
tab[x]=j;
}
kolejka.pop();
cout << tab[0] << "   " << tab[1] << "   " << tab[2] << "   "<< tab[3] << endl;
stoper.measure_time(1);
mergesort(tab, 0, data-1);
//quicksort2(tab, 0, data-1);
stoper.measure_time(0);
cout<<stoper.measure_time(0)<<endl;
delete [] tab;
}

  // Wypelnienie listy
 // for(int i=1;i<=10;i++)
  //  {
  //    lista.add(rand()%101,i);
  //  }

//void quicksort(int *tablica, int lewy, int prawy);
  // Poczatek pomiaru czasu
 // stoper.measure_time(1);
  // Wyszukanie danego elementu z listy
 // lista.search(100);
  // Koniec pomiaru czasu i wyswietlenie wyniku
 //

  return 0;
}
