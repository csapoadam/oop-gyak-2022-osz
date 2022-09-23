#include <iostream>
#include "hallgatoDb.h"

using namespace Neptun;

void HallgatoDb::add(const std::string& nev, const std::string& neptunkod) {
	for (Hallgato h : hallgatok) {
		if (h.getNeptunKod() == neptunkod) return;
	}
	// vectorba valo beszuras push_back() metodussal
	hallgatok.push_back(Hallgato(nev, neptunkod));
}

void HallgatoDb::printHallgato(const std::string& neptunkod, int numTabs) const {
	for (Hallgato h : hallgatok) { // igazabol referencia is lehetne, ld. majd kesobb
		if (h.getNeptunKod() == neptunkod) {
			h.print(numTabs);
		}
	}
}

void HallgatoDb::printDb() const {
	std::cout << "Az egyetem hallgatoi (";
	std::cout << hallgatok.size() << " hallgato):" << std::endl;
	for (Hallgato h : hallgatok) { // igazabol referencia is lehetne, ld. majd kesobb
		h.print(1);
	}
}