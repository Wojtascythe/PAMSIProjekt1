#pragma once
// KLASA WĘZŁA- ELEMENTU KOLEJKI
template <typename TYP>
class Wezel{
TYP wartosc;
TYP klucz;
Wezel<TYP> *nastepny, *poprzedni; //Wskaźniki węzła na węzeł przed nim i na węzeł po nim.
public:
//Metody poniżej są set'ami i get'ami dla powyższych prywatnych zmiennych i wksaźników
Wezel();
Wezel<TYP> * getNastepny() const; //wyciagnij z private'a
Wezel<TYP> * getPoprzedni() const; 
void setNastepny(Wezel<TYP> *_nastepny);
void setPoprzedni(Wezel<TYP> *_poprzedni);
TYP getWartosc() const;
TYP getKlucz() const;
void setWartosc(TYP _wartosc);
void setKlucz(TYP _klucz);
};

template <typename TYP>
Wezel<TYP>::Wezel(){
nastepny=nullptr;
}

template <typename TYP>
Wezel<TYP> * Wezel<TYP>::getNastepny() const{
return nastepny;
}

template <typename TYP>
Wezel<TYP> * Wezel<TYP>::getPoprzedni() const{
return poprzedni;
}

template <typename TYP>
void Wezel<TYP>::setNastepny(Wezel<TYP> *_nastepny){
nastepny=_nastepny;
}

template <typename TYP> //tutaj podejrzane
void Wezel<TYP>::setPoprzedni(Wezel<TYP> *_poprzedni){
poprzedni=_poprzedni;
}

template <typename TYP>
TYP Wezel<TYP>::getWartosc() const {
return wartosc;
}

template <typename TYP>
TYP Wezel<TYP>::getKlucz() const {
return klucz;
}

template <typename TYP>
void Wezel<TYP>::setWartosc(TYP _wartosc){
wartosc=_wartosc;
}

template <typename TYP>
void Wezel<TYP>::setKlucz(TYP _klucz){
klucz=_klucz;
}
