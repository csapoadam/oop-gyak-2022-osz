#pragma once

#include <string>

namespace Neptun {

	class Hallgato {
		std::string nev; // adatrejtes elve: adattagok jellemzoen privatak
		const std::string neptunkod;
		int megszerzettKreditszam;
	public:
		Hallgato(const std::string& nev, const std::string& neptunkod);
		std::string getNeptunKod() const;
		void addCredits(int krszam);
		void print(int numTabs) const;
	};

}