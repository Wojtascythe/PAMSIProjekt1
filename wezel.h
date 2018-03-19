#pragma once

template <typename TYP>
class Wezel{
TYP wartosc;
TYP klucz;
Wezel<TYP> *nastepny, *poprzedni;
public:

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

