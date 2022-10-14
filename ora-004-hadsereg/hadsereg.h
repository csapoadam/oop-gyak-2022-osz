#pragma once
#include "egysegek.h"
#include <vector>
#include <iostream>

class Hadsereg {
	std::vector<GyalogosEgyseg*> gyalogosok;
	std::vector<LegiEgyseg*> legiegysegek;
	std::vector<HajosEgyseg*> hajosegysegek;
public:
	void addEgyseg(GyalogosEgyseg* ge) {
		gyalogosok.push_back(ge);
	}
	void addEgyseg(LegiEgyseg* le) {
		legiegysegek.push_back(le);
	}
	void addEgyseg(HajosEgyseg* he) {
		hajosegysegek.push_back(he);
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
		std::cout << "Hajos egysegek:" << std::endl;
		for (auto he : hajosegysegek) {
			he->print(1); // indent legyen 1
		}
	}
};