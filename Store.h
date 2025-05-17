//#pragma once
///*
//	Eg�sz sz�mok t�rol�s�hoz k�sz�tett�k az al�bbi oszt�lyt (Store), ami dinamikus mem�ri�ban 
//	l�trehozott t�mbben t�rolja az adatokat.
//*/
//
//// store.h
//#include <iostream>
//
//class Store {
//    int* data; // pointer a t�rol�ra
//    int nVal; // aktu�lis darabsz�m
//public:
//    Store() : data(nullptr), nVal(0) {}
//    ~Store() { delete[] data; }
//    Store& operator=(const Store&);
//    void add(int);
//
//    void list(std::ostream& os) const { // ki�rja az adatokat vessz�vel elv�lasztva
//        for (int i = 0; i < nVal; ++i) {
//            os << (i > 0 ? ", " : "") << data[i]; // el�d el�tt nincs vessz�
//        }
//        os << std::endl;
//    }
//
//    virtual ~Store() { delete[] data; }
//};
//
///*
//    Sajnos a store.cpp f�jl elveszett, amiben az oszt�ly inline f�ggv�nyei (copyctor, op=, add) 
//    defini�lt�k. K�sz�tse el a hi�nyz� k�v�li defini�lt tagf�ggv�nyeket �gy, hogy az oszt�ly 
//    haszn�latakor ne l�pjen fel mem�riakezel�si hibat M�k�dj�n helyesen az al�bbi k�dr�szlet:    
//
//    Store s1;
//    s1.add(2);
//    s1.add(3);
//    s1.list(std::cout); // KI�R: 2, 3
//    for (int i = 0; i < 3; ++i) s1.add(i+10);
//    Store s2 = s1;
//    Store s3;
//    s3 = s2 = s1;
//    s3.list(std::cout); // KI�R: 2, 3, 10, 11, 12
//*/
//
////==============================================================================================================
//
//// !!! Raktarrol loptam ezt a megoldast !!!
//
//// store.cpp -> kikommenteltem mert ez itt nem kell
//// #include "store.h" -> kikommenteltem mert ez itt nem kell
//
//// Itt k�sz�tse el a tagf�ggv�nyeket!
//// Ahol sz�ks�ges, hogy mit k�sz�tett el, tegye defini�ltt� a megfelel� makr�t (t�r�lje a //-t):
////#define VAN_ADD // ha k�sz a add tagf�ggv�ny
////#define VAN_COPY // ha k�sz a copy konstruktor
////#define VAN_ASSIGN // ha k�sz az op=
//// <- itt erre nincs szukseg
//
//void Store::add(int szam) {
//    int* uj;
//    uj = new int[nVal + 1];
//    for (size_t i = 0; i < nVal; i++) {
//        uj[i] = data[i];
//    }
//    uj[nVal] = szam;
//    delete[] data;
//    data = uj;
//    nVal++;
//}
//
//Store::Store(const Store& rhs) {
//    nVal = rhs.nVal;
//    data = new int[nVal];
//    for (size_t i = 0; i < nVal; i++) {
//        data[i] = rhs.data[i];
//    }
//}
//
//Store& Store::operator=(const Store& rhs) {
//    if (this != &rhs) {
//        delete[] data;
//        nVal = rhs.nVal;
//        data = new int[nVal];
//        for (size_t i = 0; i < nVal; i++) {
//            data[i] = rhs.data[i];
//        }
//    }
//    return *this;
//}