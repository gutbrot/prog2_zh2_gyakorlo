#pragma once
/*
	Tételezze fel, hogy az előző feladatban elkészített Store osztály hibátlanul működik, 
	melynek megismételjük a deklarációját:
*/

/// Ki van kommentelve, mert kulonben ujra lenne definialva
 
//#include <iostream>
//
//class Store {
//    int* data; // pointer a tárolóra
//    int nVal; // aktuális darabszám
//public:
//    Store();
//    Store(const Store&);
//    Store& operator=(const Store&);
//    void add(int);
//    void list(std::ostream& os) const; // az új adatot a tömb végére teszi
//
//    virtual ~Store();
//};

/*
    Készítsen inszertert az osztályhoz, ami vesszővel elválasztva (ugyanúgy, ahogy a list() 
    kiírja a megadott std::ostream-re a tároló tartalmát! Működjön helyesen az alábbi kódrészlet:

    Store s1;
    s1.add(2);
    s1.add(3);
    std::cout << s1 << ":" << s1; // KIÍR: 2, 3:2, 3
*/
//==============================================================================================================

// !!! Raktarrol loptam ezt a megoldast !!!
#include "Store.h"

// Itt készítse el a tagfüggvényeket és az inszertert!
std::ostream& operator<<(std::ostream& os, const Store& tag) {
    tag.list(os);
    return os;
}
