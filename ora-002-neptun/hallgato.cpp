#include "hallgato.h"
#include <iostream>

// lehetne using namespace Neptun; is, es akkor nem kene
// mindenhova odairni

Neptun::Hallgato::Hallgato(
	const std::string& nv, const std::string& nkod
) : neptunkod(nkod) {
 nev = nv;
}

std::string Neptun::Hallgato::getNeptunKod() const {
	return neptunkod;
}

void Neptun::Hallgato::print(int numTabs) const {
	for (int tabcnt = 0; tabcnt < numTabs; tabcnt++) {
		std::cout << "\t";
	}
	std::cout << nev << " - " << neptunkod << std::endl;
}