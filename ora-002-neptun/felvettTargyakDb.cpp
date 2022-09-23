#include "felvettTargyDb.h"
#include <iostream>
using namespace Neptun;

void FelvettTargyDb::add(const std::string& neptunkod, const std::string& kurzuskod) {
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

	if (kurzusokToHallgatok.find(kurzuskod) ==
		kurzusokToHallgatok.end()) { // ha nincs benne, akkor az end() iteratort kapjuk meg

		std::vector<std::string> hallgatok;
		hallgatok.push_back(neptunkod);
		kurzusokToHallgatok[kurzuskod] = hallgatok;
	}
	else {
		// todo: mi tortenik hogy mar felvette azt a kurzust?
		// (most nem foglalkozunk ezzel)
		kurzusokToHallgatok[kurzuskod].push_back(neptunkod);
	}
}

void FelvettTargyDb::printTargyakByHallgato
	(const std::string& neptunkod) const
{
	// todo: majd ellenorizni kell h letezik-e ez a neptun kod
	// (most ezzel nem foglalkozunk)
	std::cout << neptunkod << " neptun kodu hallgato targyai:";
	std::cout << std::endl;
	// index operator felulirasra is szolgal, az .at() olvasast jelent
	//for (const std::string& kurzusAzonosito : hallgatokToKurzusok[neptunkod]) {
	for (const std::string& kurzusAzonosito : hallgatokToKurzusok.at(neptunkod)) {
		std::cout << "\tazonosito: " << kurzusAzonosito << std::endl;
	}
}

void FelvettTargyDb::printHallgatokByTargy
(const std::string& targykod) const
{
	// todo: majd ellenorizni kell h letezik-e ez a targykod
	// (most ezzel nem foglalkozunk)
	std::cout << targykod << " kodu targy hallgatoi:";
	std::cout << std::endl;
	// index operator felulirasra is szolgal, az .at() olvasast jelent
	for (const std::string& neptunKod : kurzusokToHallgatok.at(targykod)) {
		std::cout << "\tneptun: " << neptunKod << std::endl;
	}
}