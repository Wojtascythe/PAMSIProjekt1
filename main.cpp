//#include "stdafx.h"
#pragma once
#include <iostream>
#include "kolejka.h"
#define TYP int
using namespace std;

void QueueMenu(){                               //Menu czynności którymi się chcemy zająć
cout	<< "1.Dodaj element Z KLUCZEM do kolejki\n"
	<< "2.Usuń PIERWSZY element z kolejki\n"
	<< "3.Wyświetlanie zawartości kolejki\n"
	<< "4.Usuwanie WSZYSTKICH elementów z kolejki\n"
	<< "0.Wyjście z programu\n"
	<< "Wybierz opcję:\n";
}


int main(){
Kolejka<TYP> Kolej;             //tworzymy kolejkę
int wybor;
system("clear");

do{
QueueMenu();
cin>>wybor;
switch(wybor){
        case 1:                 //Dodajemy nowy element wpisując jego numer i klucz priorytetu
		{
		TYP wartosc, priorytet;
		cout<<"Podaj wartość: ";
		cin>>wartosc;
		cout<<"Podaj klucz (priorytet): ";
		cin>>priorytet;
		Kolej.dodaj(wartosc, priorytet);
		break;
		}
        case 2:                 //Usuwamy pierwszy element
		Kolej.usun();
		break;
        case 3:                 //Wypisujemy wszystkie elementy kolejki
		Kolej.wypisz();
		break;
        case 4:                 //Usuwamy wszystkie elementy kolejki
		if (!Kolej.czyPusta()){
		Kolej.usunWszystkie();
		} else {cerr<<"Nie można usunąć - kolejka już jest pusta!\n";}
		break;
	case 0:
		return 0;
};
} while (wybor!=0);
}

