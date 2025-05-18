#ifndef ARRAYLB_HPP
#define ARRAYLB_HPP

#include "gtest_lite.h"
#include <iostream>
#include "ArrayLB.h"
#include <sstream>

class ArrayLBTest {
public:
	static void runTest() {
		TEST(ArrayLBTest, Teszt1) {
			ArrayLB<int, -1> vi(3);			// vi 3 elemű int vektor, ami -1..+1 között indexelhető
			vi[-1] = 12;
			EXPECT_NO_THROW(vi.push_back(15));
							// std::vector minden tagfüggvénye elérhető
			for (int i = -1; i < 2; i++){
				std::cout << vi[i] << " ";
			}
		} END

		TEST(ArrayLBTest, Teszt2) {
			int t[] = { 1, 2, 3, 4, 5 };
			ArrayLB<int, -5> vt(t, t + 5);	// vt 5 elemű int vektor, ami -5..-1 között indexelhető, és
			// t-ből inicializált (1,2,3,4,5 elemekkel)
			for (int i = -5; i < 0; i++) {
				std::cout << vt[i] << " ";
			}

		} END
		TEST(ArrayLBTest, Teszt3) {
			ArrayLB<int, -1> vi(3);
			std::vector<int> v = vi;		// kompatibilitás miatt
			ArrayLB<double, 10> dd;			// dd 0 elemű double vektor
			dd.insert(dd.begin(), 3.14);	//
			std::cout << dd[10];			// KIIR 3.14

		} END
	}
};

#endif 
