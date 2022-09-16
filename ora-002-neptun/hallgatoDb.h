#pragma once
#include "hallgato.h"
#include <vector>

namespace Neptun {
	class HallgatoDb {
		std::vector<Hallgato> hallgatok;
	public:
		void add(std::string nev, std::string neptunkod);
		void printDb();
	};
}