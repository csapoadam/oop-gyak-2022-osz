#include "hallgato.h"

Neptun::Hallgato::Hallgato(std::string nv, std::string nkod) {
 nev = nv;
 neptunkod = nkod;
}

void Neptun::Hallgato::print() {
	std::cout << nev << " - " << neptunkod << std::endl;
}