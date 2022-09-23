#pragma once

#include <string>

namespace Neptun {

	class Hallgato {
		std::string nev; // adatrejtes elve: adattagok jellemzoen privatak
		const std::string neptunkod;
	public:
		Hallgato(const std::string& nev, const std::string& neptunkod);
		std::string getNeptunKod() const;
		void print(int numTabs) const;
	};

}