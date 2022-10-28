#include <vector>
#include "eszkozok.h"
#include "allatok.h"

int main() {
	Laptop l1("Asus", "i7", 16);
	Okostelefon tel1("Samsung", "S22");
	Okosora ora1("Garmin", "Vivoactive 4");

	std::vector<Eszkoz*> eszkozok;
	eszkozok.push_back(&l1);
	eszkozok.push_back(&tel1);
	eszkozok.push_back(&ora1);

	for (Eszkoz* e : eszkozok) {
		e->print();
		// Asus eszkoz
		// Samsung eszkoz
		// Garmin eszkoz
	}

	std::vector<Allat*> allatok;
	std::string foltistr("Folti");

	Kutya k("Bundi", 2018, false); // hazorzo kutya-e
	Kutya k2("Folti", 2013, true); // folti hazorzo
	Macska m("Cirmi", 2016);
	
	allatok.push_back(&k);
	allatok.push_back(&k2);
	allatok.push_back(&m);

	for (Allat* allatp : allatok) {
		allatp->print();
		// Tegyuk fel, hogy a celom:
		// Bundi kutya, szuletett 2018
		// Folti kutya, szuletett 2013, hazorzo
		// Cirmi cica, szuletett 2016
		// vegyuk eszre, Kutya es Macska
		// print() metodusa mas!
	}


}