#include "hallgatoDb.h"
#include "targyDb.h"
#include "felvettTargyDb.h"

using namespace Neptun; // nagy projekteknel nem javasolt
// mivel baj, ha 2 nevterben is letezik u.az a tipus vagy fv

int main() {
	//Hallgato h("Valami Nev", "N3PK0D"); ahhoz h ez mukodjon
	// const string& kell,  nem eleg string& mert az csak bal oldali
	// ertek lehet!

	HallgatoDb hallgatok;
	hallgatok.add("Kocsis Balint", "RBV23Q");
	hallgatok.add("Szabo Tibor", "QKX7R1");
	hallgatok.add("Nemeth Iren", "AABIK5");
	hallgatok.add("Szabo Tibor", "AX873U"); // hiaba azonos nev, de egyedi neptun kod!
	// feladat: mivel a neptun kod mar letezik, ne adjuk hozza:
	hallgatok.add("Hollan Eva", "AABIK5"); // u.az a neptun kod mint kettovel feljebb!
	hallgatok.printDb();

	TargyDb targyak;
	targyak.add("OO Programozas", "NGB1", 6);
	targyak.add("Szoftverteszteles", "NGB5", 5);
	// ne engedjuk azonos koddal
	targyak.add("Adatbazisok", "NGB5", 2);
	targyak.printDb();

	// Melyik Hallgato mely Targyakat vette fel?
	// ez a kerdes sem a HallgatoDb-hez, sem a TargyDb-hez
	// nem kapcsolodik kizarolagosan. Ezert legyen egy
	// ezt a kapcsolatot menedzselo osztaly:
	
	// mivel a db-k bovulhetnek, de maga a valtozo ugyanaz, ezert
	// celszeru lenne a referenciakat mindjart a konstruktornak atadni
	// ... igy nem kene minden egyes printXYZByABC() hivasnal atadni
	FelvettTargyDb felvettTargyak(targyak, hallgatok);
	felvettTargyak.add("AX873U", "NGB1"); // hallgato, targy
	felvettTargyak.add("AX873U", "NGB5"); // hallgato, targy
	felvettTargyak.add("RBV23Q", "NGB1"); // hallgato, targy
	felvettTargyak.add("AABIK5", "NGB5"); // hallgato, targy
	felvettTargyak.printTargyakByHallgato("AX873U"); // feladat: a targyak nevei es neptun kodjai is szerepeljenek
	felvettTargyak.printHallgatokByTargy("NGB1");
	felvettTargyak.printTargyakByHallgato("XXX000"); // nem letezo Neptun kod!
	felvettTargyak.printHallgatokByTargy("00000"); // nem letezo targykod

}