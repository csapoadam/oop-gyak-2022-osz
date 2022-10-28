#include <vector>
#include "eszkozok.h"

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
	}
}