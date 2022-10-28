#include <vector>
#include "eszkozok.h"
#include "allatok.h"
#include "jarmuvek.h"

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

	k.print();
	k2.print();
	m.print();
	std::cout << "---" << std::endl;

	for (Allat* allatp : allatok) {
		allatp->print();
		// Tegyuk fel, hogy a celom:
		// Bundi kutya, szuletett 2018
		// Folti kutya, szuletett 2013, hazorzo
		// Cirmi cica, szuletett 2016
		// vegyuk eszre, Kutya es Macska
		// print() metodusa mas!
	}

	std::cout << "vege..." << std::endl;

	// virtual magyarazata:
	Allat* ap = new Kutya("Bloki", 2021, false);
	// Ha print() virtualis, a Kutya print() metodusa hivodik meg
	// ellenkezo esetben az Allat print() metodusa hivodik meg
	// mert a fordito szerint ap egy Allat* tipusu pointer
	ap->print();
	delete ap;

	Kutya* kp = new Kutya("Bloki2", 2021, false);
	kp->print(); // itt mindenkeppen Kutya print()-je hivodik meg
	// mert kp a fordito szamara is Kutya* tipusu pointer
	delete kp;

	std::vector<Jarmu*> jarmuvek;
	jarmuvek.push_back(new Auto("Suzuki", "120LE"));
	jarmuvek.push_back(new Repulo("Boeing", 980)); // 980km / ora

	for (Jarmu* jp : jarmuvek) {
		jp->print(); // virtualis kell, hogy legyen! mivel elter a konkret jarmu tipus szerint
		// Suzuki 120LE motorral
		// Boeing 980 km/h sebesseggel
	}
	// ezt se felejtsuk el, mivel jarmuvek vektorban NEM
	// stack valtozok hanem a heap-en allokalt valtozok
	// cimei vannak:
	for (Jarmu* jp : jarmuvek) delete jp;
}