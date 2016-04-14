#include "lista.hh"
#include "iostream"
using namespace std;
void lista::dodajelement(int elem, int pozycja){
wezel *temp = new wezel;
temp->element=elem;
if(pozycja==0){     /*dodawanie na tyl listy*/
if(rozmiar_listy==0){
temp->nastepny=przod;
przod=temp;
tyl=temp;
}
else{
tyl->nastepny=temp;
temp->nastepny=NULL;
tyl=temp;
}
}
if(pozycja==rozmiar_listy && rozmiar_listy!=0){/*dodawanie na przod*/
temp->nastepny=przod;
przod=temp;
}
else if(pozycja<rozmiar_listy){
wezel *temp2=new wezel;
temp2=przod;
for(int i=0;i<(rozmiar_listy-(pozycja+1));i++){
temp2=temp2->nastepny;
}
temp->nastepny=temp2->nastepny;
delete temp2;
}
else{
cout << "Poza zakresem" << endl;
rozmiar_listy--;
}
rozmiar_listy++;
delete temp;
}

int lista::usunelement(int pozycja){
if(pozycja>=rozmiar_listy){
cout << "Element nie istnieje." << endl;
return(0);
}
wezel *temp;
wezel *temp2;
temp=przod;
for(int i=0;i<(rozmiar_listy-(pozycja+1)); i++){
temp=temp->nastepny;
if (i==(rozmiar_listy-(pozycja+2))){temp2=temp;}
}
temp2->nastepny=temp->nastepny;
rozmiar_listy--;
delete temp;
delete temp2;
return(0);
}

lista::lista(){
przod=NULL;
tyl=NULL;
rozmiar_listy=0;
}

void lista::wyswietlrozmiar(){
cout << rozmiar_listy << endl;
};

void lista::wyswietl(){

};
