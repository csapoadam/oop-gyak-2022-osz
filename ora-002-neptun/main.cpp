#include "hallgato.h"

//#include <string>
//#include <iostream>
//
//class Hallgato {
//	std::string nev; // adatrejtes elve: adattagok jellemzoen privatak
//	std::string neptunkod;
//public:
//	Hallgato(std::string neve, std::string neptunkodja) {
//		nev = neve;
//		neptunkod = neptunkodja;
//	}
//	void print() {
//		std::cout << nev << " - " << neptunkod << std::endl;
//	}
//};

int main() {
	Hallgato kocsisb("Kocsis Balint", "RBV23Q");
	kocsisb.print(); // Kocsis Balint - RBV23Q
}