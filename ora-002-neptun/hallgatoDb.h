#pragma once
#include "hallgato.h"
#include <vector>

namespace Neptun {
	class HallgatoDb {
		// std::map talan jobb lenne, de az std::vector alapveto ismeret
		std::vector<Hallgato> hallgatok;
	public:
		HallgatoDb() {} // jelenleg nem szukseges, de sose baj
		void add(std::string nev, std::string neptunkod);
		void printDb();
	};
}