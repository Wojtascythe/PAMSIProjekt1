#pragma once
#include "wezel.h"
using namespace std;
//KLASA KOLEJKI
template <typename TYP>
class Kolejka{
private:
Wezel<TYP> *glowa;
Wezel<TYP> *ogon;

public:
Kolejka(){
glowa=nullptr;
ogon=nullptr;
rozmiar=0;
}
void dodaj(TYP _wartosc, TYP _klucz);
void usun();
void przod();
unsigned int getRozmiar() const;
unsigned int getKlucz() const;
bool czyPusta();
void wypisz();
void usunWszystkie();
};



template<typename TYP>
void Kolejka<TYP>::usunWszystkie(){
Wezel<TYP> *tmp1=glowa;
Wezel<TYP> *tmp2;
if(!czyPusta()){
while(tmp1!=NULL){
tmp2=tmp1->getNastepny();
delete tmp1;
tmp1=tmp2;
};
glowa=tmp1;
cout<<"Usunięto wszystkie dane z kolejki!\n";
} else cerr<<"Nie można usunąć - kolejka już jest pusta!\n";
}


