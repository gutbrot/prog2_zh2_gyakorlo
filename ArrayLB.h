#pragma once
/*
	Egyes programozási nyelvekben a tömbök indexhatárai is megadhatók deklarációjukkor. Így pl. lehet olyan tömböt létrehozni, ami -3-tól +5-
ig indexelhető.
Készítsen adapter sablont (ArrayLB) az std::vector tárolóhoz, ami lehetővé teszi, hogy ne csak 0-tól indexelhető vektorokat hozzunk létre. A
sablon első paramétere az adattípus, a második pedig egy int (N), ami az alsó indexhatár. Alapértelmezésként N = 0 legyen! A sablon csak
az indexelés műveletét alakítsa át! A többi publikus műveletet (konstruktorokat is) változtatás nélkül tegye elérhetővé!
Az ArrayLB sablonnal létrehozott T elemeket tartalmazó objektum legyen kompatibilis az std::vector sablonnal létrehozott T elemeket
tartalmazó objektummal! Elegendő az indexelő operátorokat (operator[]) megvalósítania, az at() helyes működését nem vizsgáljuk! Példa az
adapter használatára:

ArrayLB<int, -1> vi(3);			// vi 3 elemű int vektor, ami -1..+1 között indexelhető
vi[-1] = 12;
vi.push_back(15);				// std::vector minden tagfüggvénye elérhető

int t[] = { 1, 2, 3, 4, 5 };
ArrayLB<int, -5> vt(t, t + 5);	// vt 5 elemű int vektor, ami -5..-1 között indexelhető, és
								// t-ből inicializált (1,2,3,4,5 elemekkel)

std::vector<int> v = vi;		// kompatibilitás miatt
ArrayLB<double, 10> dd;			// dd 0 elemű double vektor
dd.insert(dd.begin(), 3.14);	//
std::cout << dd[10];			// KIIR 3.14

	Ügyeljen a sorozattárolókra jellemző konstruktorok megvalósítására is!Az std::vector 
	sablon alapértelmezett sablonparamétereit(pl.allocator), hagyja alapértelmezettnek!
*/

//==============================================================================================================

#pragma once

#include <iostream>
#include <vector>

template<typename T, int N = 0>
class ArrayLB : public std::vector<T> {
public:
    // Örökölt konstruktorok használata
    using std::vector<T>::vector;

    // Indexelés módosítása: alsó határtól induljon
    T& operator[](int index) {
        return std::vector<T>::operator[](index - N);
    }

    const T& operator[](int index) const {
        return std::vector<T>::operator[](index - N);
    }
};
