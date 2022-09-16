#pragma once

#include <string>

namespace Neptun {

	class Hallgato {
		std::string nev; // adatrejtes elve: adattagok jellemzoen privatak
		std::string neptunkod;
	public:
		Hallgato(std::string nev, std::string neptunkod);
		void print(const int numTabs);
	};

}