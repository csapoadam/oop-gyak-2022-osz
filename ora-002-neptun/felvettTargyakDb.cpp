#include "felvettTargyDb.h"
#include <iostream>
using namespace Neptun;

void FelvettTargyDb::add(std::string neptunkod, std::string kurzuskod) {
	if (hallgatokToKurzusok.find(neptunkod) ==
		hallgatokToKurzusok.end()) { // ha nincs benne, akkor az end() iteratort kapjuk meg
		
		std::vector<std::string> kurzusok;
		kurzusok.push_back(kurzuskod);
		hallgatokToKurzusok[neptunkod] = kurzusok;
	}
	else {
		// todo: mi tortenik hogy mar felvette azt a kurzust?
		// (most nem foglalkozunk ezzel)
		hallgatokToKurzusok[neptunkod].push_back(kurzuskod);
	}
}

void FelvettTargyDb::printTargyakByHallgato(std::string neptunkod) {
	// todo: majd ellenorizni kell h letezik-e ez a neptun kod
	// (most ezzel nem foglalkozunk)
	std::cout << neptunkod << " neptun kodu hallgato targyai:";
	std::cout << std::endl;
	for (std::string kurzusAzonosito : hallgatokToKurzusok[neptunkod]) {
		std::cout << "\tazonosito: " << kurzusAzonosito << std::endl;
	}
}