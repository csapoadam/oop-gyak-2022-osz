#pragma once

#include <string>

namespace Neptun {

	class Targy {
		std::string nev; // adatrejtes elve: adattagok jellemzoen privatak
		const std::string azonosito;
		int kreditszam;
	public:
		Targy(const std::string& nev, const std::string& azonosito, int kreditsz);
		std::string getAzonosito() const;
		void print(int numTabs) const;
	};

}