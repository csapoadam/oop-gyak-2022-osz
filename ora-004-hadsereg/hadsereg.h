#pragma once
#include "egysegek.h"
#include <vector>
#include <iostream>

class Hadsereg {
	std::vector<GyalogosEgyseg*> gyalogosok;
	std::vector<LegiEgyseg*> legiegysegek;
public:
	void addEgyseg(GyalogosEgyseg* ge) {
		gyalogosok.push_back(ge);
	}
	void addEgyseg(LegiEgyseg* le) {
		legiegysegek.push_back(le);
	}
	void print() {
		std::cout << "Gyalogos egysegek:" << std::endl;
		for (GyalogosEgyseg* ge : gyalogosok) {
			ge->print(1); // indent legyen 1
		}
		std::cout << "Legi egysegek:" << std::endl;
		// foreach iteralas: auto is hasznalhato, hiszen
		// a fordito ugyis tudja, hogy legiegysegek milyen tipusu
		// dolgokat tarol
		for (auto le : legiegysegek) {
			le->print(1); // indent legyen 1
		}
	}
};