#pragma once
/*
	Egyes programoz�si nyelvekben a t�mb�k indexhat�rai is megadhat�k deklar�ci�jukkor. �gy pl. lehet olyan t�mb�t l�trehozni, ami -3-t�l +5-
ig indexelhet�.
K�sz�tsen adapter sablont (ArrayLB) az std::vector t�rol�hoz, ami lehet�v� teszi, hogy ne csak 0-t�l indexelhet� vektorokat hozzunk l�tre. A
sablon els� param�tere az adatt�pus, a m�sodik pedig egy int (N), ami az als� indexhat�r. Alap�rtelmez�sk�nt N = 0 legyen! A sablon csak
az indexel�s m�velet�t alak�tsa �t! A t�bbi publikus m�veletet (konstruktorokat is) v�ltoztat�s n�lk�l tegye el�rhet�v�!
Az ArrayLB sablonnal l�trehozott T elemeket tartalmaz� objektum legyen kompatibilis az std::vector sablonnal l�trehozott T elemeket
tartalmaz� objektummal! Elegend� az indexel� oper�torokat (operator[]) megval�s�tania, az at() helyes m�k�d�s�t nem vizsg�ljuk! P�lda az
adapter haszn�lat�ra:

ArrayLB<int, -1> vi(3);			// vi 3 elem� int vektor, ami -1..+1 k�z�tt indexelhet�
vi[-1] = 12;
vi.push_back(15);				// std::vector minden tagf�ggv�nye el�rhet�

int t[] = { 1, 2, 3, 4, 5 };
ArrayLB<int, -5> vt(t, t + 5);	// vt 5 elem� int vektor, ami -5..-1 k�z�tt indexelhet�, �s
								// t-b�l inicializ�lt (1,2,3,4,5 elemekkel)

std::vector<int> v = vi;		// kompatibilit�s miatt
ArrayLB<double, 10> dd;			// dd 0 elem� double vektor
dd.insert(dd.begin(), 3.14);	//
std::cout << dd[10];			// KIIR 3.14

	�gyeljen a sorozatt�rol�kra jellemz� konstruktorok megval�s�t�s�ra is!Az std::vector 
	sablon alap�rtelmezett sablonparam�tereit(pl.allocator), hagyja alap�rtelmezettnek!
*/

//==============================================================================================================

