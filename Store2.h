#pragma once
/*
	T�telezze fel, hogy az el�z� feladatban elk�sz�tett Store oszt�ly hib�tlanul m�k�dik, 
	melynek megism�telj�k a deklar�ci�j�t:
*/

// store.h
#ifndef STORE_H_INCLUDED
#define STORE_H_INCLUDED
#include <iostream>

class Store {
    int* data; // pointer a t�rol�ra
    int nVal; // aktu�lis darabsz�m
public:
    Store();
    Store(const Store&);
    Store& operator=(const Store&);
    void add(int);
    void list(std::ostream& os) const; // az �j adatot a t�mb v�g�re teszi

    virtual ~Store();
};

#endif // STORE_H_INCLUDED

/*
    K�sz�tsen inszertert az oszt�lyhoz, ami vessz�vel elv�lasztva (ugyan�gy, ahogy a list() 
    ki�rja a megadott std::ostream-re a t�rol� tartalm�t! M�k�dj�n helyesen az al�bbi k�dr�szlet:

    Store s1;
    s1.add(2);
    s1.add(3);
    std::cout << s1 << ":" << s1; // KI�R: 2, 3:2, 3
*/

//==============================================================================================================

// !!! Raktarrol loptam ezt a megoldast !!!


// store.cpp
#include "store.h"

// Itt k�sz�tse el a tagf�ggv�nyeket �s az inszertert!

std::ostream& operator<<(std::ostream& os, const Store& tag) {
    tag.list(os);
    return os;
}