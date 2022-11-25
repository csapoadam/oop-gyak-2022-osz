#include <type_traits>
#include <string>
#include <iostream>

// Keszitsen el 3 osztalyt: Device, Computer es Laptop
// Device egy absztrakt ososztaly, melynek print() metodusa
// nincs megvalositva
// Computer es Laptop egyfajta Device (szarmaznak belole) es
// megvalositjak a print() metodust

int main() {
	static_assert(
		std::is_abstract<Device>(),
		"Device ought to be abstract."
	);
	Device* computer = new Computer("IBM Business");
	Device* laptop = new Laptop("Asus TUF");
	computer->print(); // IBM Business gep vagyok
	laptop->print(); // Asus TUF laptop vagyok
}