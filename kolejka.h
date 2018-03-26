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
void Kolejka<TYP>::dodaj(TYP _wartosc, TYP _klucz){
Wezel<TYP> * nowy = new Wezel<TYP>;         // Tworzymy nowy węzeł i dajemy mu dane wartość i klucz
nowy->setWartosc(_wartosc);
nowy->setKlucz(_klucz);
if (czyPusta()){  //Sprawdzamy czy kolejka jest pusta, jeśli tak, to nasz nowy staje się i ogonem i głową
glowa=nowy;
ogon=nowy;
} else {   // ... jeśli jest juz jakiś element w kolejce, to tworzymy wskaźnik temp na ostatni węzeł (ogon)
Wezel<TYP> * temp = new Wezel<TYP>;
temp=ogon;

if(temp->getNastepny()==nullptr){           // Sprawdzamy czy w kolejce jest tylko jeden element
if (temp->getKlucz() > nowy->getKlucz()){ // Sprawdzamy czy priorytet nowego węzła jest większy od priorytetu już obecnego węzła (temp)
nowy->setNastepny(nullptr);               // Ustawiamy wskaźniki odpowiednio by nowy był w kolejce przed temp.
nowy->setPoprzedni(temp);
temp->setNastepny(nowy);
glowa=nowy;
} else {                                  // Jeśli jednak już obecny węzeł temp miał większy priorytet niż nowy, ustawiamy ich wskaźniki tak, by
nowy->setNastepny(temp);                   // temp był przed nowym w kolejce. Pamietajmy też o przestawieniu temp na nowy ogon kolejki.
temp->setPoprzedni(nowy);
ogon=nowy;
temp=ogon;
};
} else { // Przypadek gdy w kolejce jest więcej już węzłów
int check=0; //Warunek do przerwania pętli
while(check!=2){ //Idziemy ze wskaźnikiem temp od ostatniego węzła do pierwszego w kolejce, sprawdzając, kiedy nowy węzeł nie będzie miał
                // większego priorytetu niż obecnie sprawdzany temp.
if (temp->getKlucz() > nowy->getKlucz() && temp->getNastepny()!=nullptr) temp=temp->getNastepny(); else{
if (temp->getNastepny()!=nullptr){ //Natrafiliśmy na węzeł temp, który ma większy priorytet niż nowy i nie jest pierwszym węzłem w kolejce.
        nowy->setNastepny(temp);
                if (temp->getPoprzedni()!=nullptr){ //Sprawdzamy czy przypadkiem nie jest to ostatni węzeł w kolejce
                nowy->setPoprzedni(temp->getPoprzedni()); //Jeśli nie, to wstawiamy nowy między węzeł temp i węzeł poprzedni do temp.
                temp->setPoprzedni(nowy);
                nowy->getPoprzedni()->setNastepny(nowy);
                } else {                                   //Jeśli tak, to wstawiamy nowy za węzłem temp, a wskaźnik nowego na poprzedni na null.
                        nowy->setPoprzedni(nullptr);
                        temp->setPoprzedni(nowy);
                        ogon=nowy;
                        temp=ogon;
                };
} else { //Jeśli porównując nowy po kolei ze wszystkimi węzłami w kolecje dotarliśmy do pierwszego węzła w kolejce, to porównujemy ich klucze.
        if (temp->getKlucz() > nowy->getKlucz()){ //Jeśli nowy wygrywa, to staje się nową głową
        nowy->setNastepny(nullptr);
        nowy->setPoprzedni(temp);
        temp->setNastepny(nowy);
        glowa=nowy;
        } else {                    // Jeśli jednak ma mniejszy priorytet, to wstawiamy go za pierwszym węzłem w kolejce.
        nowy->setNastepny(temp);
        nowy->setPoprzedni(temp->getPoprzedni());
        nowy->getPoprzedni()->setNastepny(nowy);
        temp->setPoprzedni(nowy);
};
};
check=2; //Przerywamy pętle
};
};
};
};
rozmiar++;
cout<<"Rozmiar kolejki: "<<rozmiar<<endl;
}


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


