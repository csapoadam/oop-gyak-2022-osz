#pragma once
#include "targy.h"
#include <vector>

namespace Neptun {
	class TargyDb {
		// std::map talan jobb lenne, de az std::vector alapveto ismeret
		std::vector<Targy> targyak;
	public:
		TargyDb() {} // jelenleg nem szukseges, de sose baj
		void add(std::string nev, std::string azonosito, int kreditszam);
		void printDb();
	};
}