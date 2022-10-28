#include "hadsereg.h" // ez majd include-olja az egyegek.h-t is
// vagy lehetne azt, hogy include egysegek, majd include hadsereg
// es akkor a hadsereg.h-ban levo egyseg tipusokra valo hivatkozas
// mar ertelmezve lenne

int main() {
	Hadsereg h1;
	// Egyseg tipusa:
	// 0 - gyalogos
	// 1 - legi
	// 2 - hajos
	// ez csunya megoldas de mukodhet ameddig az oroklesrol nem tanultunk!
	// Feladat: Irjuk at a korabbi megoldast, ugy, hogy ne kelljen
	// ilyen csunya tipusmezoket hasznalni!
	
	GyalogosEgyseg ge1(150, 47.49, 19.04); // 150 fo, GPS lat, GPS lon (Budapest)
	LegiEgyseg le1(1500, 47.68, 17.63); // hany m magasan tud repulni, GPS lat, GPS lon, (Gyor)
	// legenyseg szama: 300, hatotavolsag: 15.5 km, koordinatak (Sevastopol)
	HajosEgyseg he1(300, 15.5, 44.62, 33.52);
	h1.addEgyseg(&ge1);
	h1.addEgyseg(&le1);
	h1.addEgyseg(&he1);

	h1.print();
}