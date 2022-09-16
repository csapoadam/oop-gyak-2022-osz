#include <iostream>
#include "hallgatoDb.h"

using namespace Neptun;

void HallgatoDb::add(std::string nev, std::string neptunkod) {
	for (Hallgato h : hallgatok) {
		if (h.getNeptunKod() == neptunkod) return;
	}
	// vectorba valo beszuras push_back() metodussal
	hallgatok.push_back(Hallgato(nev, neptunkod));
}

void HallgatoDb::printDb() {
	std::cout << "Az egyetem hallgatoi (";
	std::cout << hallgatok.size() << " hallgato):" << std::endl;
	for (Hallgato h : hallgatok) { // igazabol referencia is lehetne, ld. majd kesobb
		h.print(1);
	}
}