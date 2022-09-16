#include <iostream>
#include "hallgatoDb.h"

using namespace Neptun;

void HallgatoDb::add(std::string nev, std::string neptunkod) {
	// vectorba valo beszuras push_back() metodussal
	hallgatok.push_back(Hallgato(nev, neptunkod));
}

void HallgatoDb::printDb() {
	std::cout << "Az egyetem hallgatoi:" << std::endl;
	/*for (int inx = 0; inx < hallgatok.size(); inx++) {
		hallgatok[inx].print();
	}*/
	for (Hallgato h : hallgatok) { // igazabol referencia is lehetne, ld. majd kesobb
		h.print(1);
	}
}