



int main() {
	Hadsereg h1;
	GyalogosEgyseg ge1(150, 47.49, 19.04); // 150 fo, GPS lat, GPS lon (Budapest)
	LegiEgyseg le1(47.68, 17.63); // GPS lat, GPS lon, (Gyor)
	h1.addEgyseg(&ge1);
	h1.addEgyseg(&le1);

	h1.print();
}