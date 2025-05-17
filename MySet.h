#pragma once
/*
	Implementaljon egy generikus tarolot, ami halamzkent fog mukodni. Az osztalyt **MySet** neven
	implementalja. A halmazban tarolt elemek tipusat es annak meretet (size_t) sablonparameterkent 
	lehet beallitani. Alapertelmezetten a halmaz merete 10. Az elemeket egy statikus tombben a sablonozas 
	segitsegevel kell eltarolni, ezt a tombet **elements**-nek nevezze el. Feltetelezheti, hogy a 
	megadott tipusoknak van alapertelmezett konstruktora, tovabba ervenyes rajtuk az osszehasonlito (==)
	operator. Figyeljen a lathatosagra. Tovabba:

		-	contains metodus: igaz logikai erteket ad vissza, ha a parameterul kap elem benne van a 
		    halmazban mar, kulonben hamis
		-	insert metodus: belerakja a halmazba, a kapott erteket (ha nem volt benne). Ha nem volt 
			benne, viszont a halmaz kapacitasa (sablonparameter) mar nem eleg. akkor const char*
			kivetelt dob. Ha a parameterul kapott ertek mar szerepel a halmazban, nem csinal semmit
		-	size metodus: visszaadja az eddig tarolt elemek szamat
		-	capacity metodus: visszaadja a halmaz kapacitasat (mennyi kulonbozo elemet lehet maximum berakni)

	Figyeljen a konstans parameterekre es konstans metodusokra!

	MySet<char, 5> t;
	std::cout << t.contains('a'); // Ki:: 0 (false)
	t.insert('a');
	std::cout << t.container('a'); // Ki:: 1 (true)

	*/

//==============================================================================================================

#include <vector>
#include <iostream>

// feltetelezem nem vector tipussal kell megoldani, hanem sajttal
template<typename T, size_t M = 10>
class MySet {
	size_t currentSize = 0;
	T elements[M];
public:
	bool contains(const T& n) const {
		for (size_t i = 0; i < M; i++){
			if (elements[i] == n)
				return true;
		}
		return false;
	}
	void insert(const T& n) {
		if (contains(n)) return;
		if (currentSize >= M)
			throw "error";
		elements[currentSize] = n;
		currentSize++;
	}
	size_t size() const{
		return currentSize;
	}
	size_t capacity() const{
		return M;
	}
};
