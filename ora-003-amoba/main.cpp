#include "AmobaJatek.h"

int main() {
	AmobaJatek jatek(4, 4, 3); // utolso parameter: nyeres-hossz
	int winner = jatek.play(); // ebben legyen egy majdnem vegtelen ciklus
	// ami addig varja a lepeseket, amig tart a jatek

	// winner 0, 1 vagy 2 legyen (dontelen, 1. nyert, 2. nyert)
	if (winner == 0) {
		std::cout << "Dontetlen!" << std::endl;
	}
	else {
		std::cout << "Jatekos " << winner << " nyert!" << std::endl;
	}
}