#include <iostream>
#include "targyDb.h"

using namespace Neptun;

void TargyDb::add(std::string nev, std::string azonosito, int kreditszam) {
	for (Targy t : targyak) {
		if (t.getAzonosito() == azonosito) return;
	}
	// vectorba valo beszuras push_back() metodussal
	targyak.push_back(Targy(nev, azonosito, kreditszam));
}

void TargyDb::printDb() {
	std::cout << "Az egyetem targyai (";
	std::cout << targyak.size() << " targy):" << std::endl;
	for (Targy t : targyak) { // igazabol referencia is lehetne, ld. majd kesobb
		t.print(1);
	}
}