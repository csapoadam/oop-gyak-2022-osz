#pragma once
#include "targy.h"
#include <vector>

namespace Neptun {
	class TargyDb {
		// std::map talan jobb lenne, de az std::vector alapveto ismeret
		std::vector<Targy> targyak;
	public:
		TargyDb() {} // jelenleg nem szukseges, de sose baj
		void add(const std::string& nev, const std::string& azonosito, int kreditszam);
		void printTargy(const std::string& azonosito, int numTabs); // TODO!
		void printDb() const;
	};
}