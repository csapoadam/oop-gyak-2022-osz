#include "targy.h"
#include <iostream>

// lehetne using namespace Neptun; is, es akkor nem kene
// mindenhova odairni

Neptun::Targy::Targy(std::string nv, std::string az, int krszam) {
	nev = nv;
	azonosito = az;
	kreditszam = krszam;
}

std::string Neptun::Targy::getAzonosito() {
	return azonosito;
}

void Neptun::Targy::print(int numTabs) {
	for (int tabcnt = 0; tabcnt < numTabs; tabcnt++) {
		std::cout << "\t";
	}
	std::cout << azonosito << " (";
	std::cout << kreditszam << " kredit) - ";
	std::cout << nev << std::endl;
}