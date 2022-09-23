#pragma once
#include "hallgato.h"
#include <vector>

namespace Neptun {
	class HallgatoDb {
		// std::map talan jobb lenne, de az std::vector alapveto ismeret
		std::vector<Hallgato> hallgatok;
	public:
		HallgatoDb() {} // jelenleg nem szukseges, de sose baj
		void add(const std::string& nev, const std::string& neptunkod);
		void printHallgato(const std::string& neptunkod, int numTabs) const;
		void printDb() const;
	};
}