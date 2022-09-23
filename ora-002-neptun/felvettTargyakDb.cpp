#include "felvettTargyDb.h"
#include <iostream>
using namespace Neptun;

bool FelvettTargyDb::doesTargyExist(const std::string& targykod) const {
	return kurzusokToHallgatok.find(targykod) !=
		kurzusokToHallgatok.end();
}

bool FelvettTargyDb::doesHallgatoExist(const std::string& neptunkod) const {
	return hallgatokToKurzusok.find(neptunkod) !=
		hallgatokToKurzusok.end();
}

void FelvettTargyDb::ensureHallgatoExists(const std::string& neptunkod) {
	if (!doesHallgatoExist(neptunkod)) { // ha nincs benne, akkor az end() iteratort kapjuk meg
		std::vector<std::string> kurzusok;
		hallgatokToKurzusok[neptunkod] = kurzusok;
	}
}

void FelvettTargyDb::ensureTargyExists(const std::string& targykod) {
	if (!doesTargyExist(targykod)) { // ha nincs benne, akkor az end() iteratort kapjuk meg
		std::vector<std::string> hallgatok;
		kurzusokToHallgatok[targykod] = hallgatok;
	}
}


void FelvettTargyDb::add(const std::string& neptunkod, const std::string& kurzuskod) {
	ensureHallgatoExists(neptunkod);
	hallgatokToKurzusok[neptunkod].push_back(kurzuskod);

	ensureTargyExists(kurzuskod);
	kurzusokToHallgatok[kurzuskod].push_back(neptunkod);
}

void FelvettTargyDb::printTargyakByHallgato
	(const std::string& neptunkod) const
{
	if (!doesHallgatoExist(neptunkod)) {
		std::cout << "bocsika, ez a hallgato nem letezik" << std::endl;
		return;
	}

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
	if (!doesTargyExist(targykod)) {
		std::cout << "bocsika, ez a targy nem letezik" << std::endl;
		return;
	}

	// todo: majd ellenorizni kell h letezik-e ez a targykod
	// (most ezzel nem foglalkozunk)
	std::cout << targykod << " kodu targy hallgatoi:";
	std::cout << std::endl;
	// index operator felulirasra is szolgal, az .at() olvasast jelent
	for (const std::string& neptunKod : kurzusokToHallgatok.at(targykod)) {
		std::cout << "\tneptun: " << neptunKod << std::endl;
	}
}