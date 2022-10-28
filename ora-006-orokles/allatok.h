#pragma once
#include <string>
#include <iostream>

class Allat {
	std::string nev;
	int szuletesi_ev;
public:
	Allat(	const std::string& name,
			int birth_year
			) :
		nev(name),
		szuletesi_ev(birth_year)
	{}
	void print() {
		std::cout << nev << ", szuletett: ";
		std::cout << szuletesi_ev;
		std::cout << std::endl;
	}
};

// const std::string& magyarazat
// lehetne std::string - de egy nagy stringet
// koltseges lenne lemasolni mindig...

// "sima" bal oldali referencia: string&
//	-> csak bal oldali ertekeket tud tarolni
// pl. std::string x = "Folti";
// Kutya(x);
// de: Kutya("Folti") nem ok... "Folti" jobb oldali ertek

// jobb oldali referencia: string&&
// ez meg csak a "Folti"-val mukodne...

// const referencia: const string&
// mind2 megadasi mod jo

class Kutya : public Allat {
	bool is_hazorzo;
public:
	Kutya(	const std::string& name,
			int birth_year,
			bool hazorzo
			) :
		Allat(name, birth_year),
		is_hazorzo(hazorzo) 
	{}
};

class Macska : public Allat {
public:
	Macska(	const std::string& name,
			int birth_year
			) :
		Allat(name, birth_year)
	{}
};