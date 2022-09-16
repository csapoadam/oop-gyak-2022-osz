#pragma once

#include <string>

namespace Neptun {

	class Targy {
		std::string nev; // adatrejtes elve: adattagok jellemzoen privatak
		std::string azonosito;
		int kreditszam;
	public:
		Targy(std::string nev, std::string azonosito, int kreditsz);
		std::string getAzonosito();
		void print(int numTabs);
	};

}