#pragma once
/// Ez IMSC feladat volt

/*
	Adapter a k�vetkez� sablon, ami k�l�nb�z� �rt�kek (VAL) el�fordul�si sz�m�nak meghat�roz�s�ra alkalmas:
*/

template<typename VAL>
class Counter {
    std::map<VAL, size_t> values;
public:
    virtual void reset() {
        values.clear();
    }

    virtual void count(const VAL& key) {
        values[key]++;
    }

    virtual size_t get(const VAL& key) const {
        return values.at(key); // hiba eset�n std::out_of_range exp-et dob
    }
};

/*

    A sablon felhaszn�l�s�val hozzon l�tre egy MyWC oszt�lyt, amely szavak (std::string) sz�ml�l�s�ra 
    alkalmas. Az oszt�ly konstruktor�ban legyen megadhat� egy bool �rt�k, hogy a kis- �s nagybet�ket 
    azonosnak, vagy k�l�nb�z�nek tekintse-e az oszt�ly. A megold�s sor�n c�lszer� felhaszn�lnia a 
    glob�lis std::string to_lower(std::string) f�ggv�nyt. Az al�bbi p�lda az oszt�ly haszn�lat�t demonstr�lja:

    MyWC wc(true); // az oszt�ly �rz�keny a kis/nagy bet�kre
    wc.count("alma"); // k�l�nb�z� elemeknek min�s�lnek
    wc.count("ALMA");
    wc.count("ALMA");
    std::cout << wc.get("alma") << std::endl; // 1
    std::cout << wc.get("ALMA") << std::endl; // 2

    �s hogyha nem:

    MyWC wc(false); // az oszt�ly NEM �rz�keny a kis/nagy bet�kre
    wc.count("alma"); // azonos elemeknek min�s�lnek
    wc.count("ALMA");
    wc.count("ALMA");
    std::cout << wc.get("alma") << std::endl; // 3
    std::cout << wc.get("ALMA") << std::endl; // 3 (ugyanazok)

    Az oszt�lyt l�ssa el indexel� oper�torral is, amivel lek�rdezhet� hogy az egyes szavakb�l, 
    mennyi van, hasonl�an a get() f�ggv�nyhez, viszont ha egy olyan sz�t kap param�terk�nt, 
    ami m�g nincs, akkor ne dobjon kiv�telt, hanem t�rjen vissza 0-val!
*/

//==============================================================================================================
