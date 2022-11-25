#include <type_traits>
#include <string>
#include <iostream>

// Keszitsen el egy Helyiseg nevu absztrakt osztalyt, melynek
// setHomerseklet(double) metodusa beallitja a homersekletet
// es printTemperature() metodusa egy sztringet var, de nincs
// megvalositva

// Ebbol szarmazzon a Szoba osztaly, melynek printTemperature(str)
// metodusa str = "hun" eseten magyarul irja ki a homersekletet,
// str = "eng" eseten pedig angolul.

class Helyiseg {
protected:
	double homerseklet;
public:
	void setHomerseklet(double temp) { homerseklet = temp; }
	virtual void printTemperature(std::string language) = 0;
};

class Szoba : public Helyiseg {
	std::string nev;
public:
	Szoba(std::string nev) : nev(nev) {}
	void printTemperature(std::string lang) {
		if (lang == "hun") {
			std::cout << "Homerseklet a " << nev;
			std::cout << " szobaban: " << homerseklet;
			std::cout << std::endl;
		} else if (lang == "eng") {
			std::cout << "Temperature in " << nev;
			std::cout << " : " << homerseklet;
			std::cout << std::endl;
		}
	}
};

int main() {
	static_assert(
		std::is_abstract<Helyiseg>(), "Helyiseg must be abstract"
	);

	Helyiseg* nappali = new Szoba("nappali");
	Helyiseg* haloszoba = new Szoba("haloszoba");

	nappali->setHomerseklet(21.5);
	haloszoba->setHomerseklet(19.0);

	nappali->printTemperature("eng"); // Temperature in nappali: 21.5
	haloszoba->printTemperature("hun"); // Homerseklet a haloszoba szobaban: 19.0
}