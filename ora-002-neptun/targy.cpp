#include "targy.h"
#include <iostream>

// lehetne using namespace Neptun; is, es akkor nem kene
// mindenhova odairni

Neptun::Targy::Targy(
	const std::string& nv,
	const std::string& az,
	int krszam
) : azonosito(az) {
	nev = nv;
	kreditszam = krszam;
}

std::string Neptun::Targy::getAzonosito() const {
	return azonosito;
}

void Neptun::Targy::print(int numTabs) const {
	for (int tabcnt = 0; tabcnt < numTabs; tabcnt++) {
		std::cout << "\t";
	}
	std::cout << azonosito << " (";
	std::cout << kreditszam << " kredit) - ";
	std::cout << nev << std::endl;
}