#include "hadsereg.h" // ez majd include-olja az egyegek.h-t is
// vagy lehetne azt, hogy include egysegek, majd include hadsereg
// es akkor a hadsereg.h-ban levo egyseg tipusokra valo hivatkozas
// mar ertelmezve lenne

int main() {
	Hadsereg h1;
	GyalogosEgyseg ge1(150, 47.49, 19.04); // 150 fo, GPS lat, GPS lon (Budapest)
	LegiEgyseg le1(1500, 47.68, 17.63); // hany m magasan tud repulni, GPS lat, GPS lon, (Gyor)
	h1.addEgyseg(&ge1);
	h1.addEgyseg(&le1);

	h1.print();
}