#include "AmobaTabla.h"



int main() {

	AmobaJatek jatek(4, 4);
	jatek.play(); // ebben legyen egy majdnem vegtelen ciklus
	// ami addig varja a lepeseket, amig tart a jatek

	//AmobaTabla table(4,4);
	//table.lepes(0, 'A', 3); // 0. jatekos lep A sor 3. oszlopba
	//// ennek az otnek ne legyen hatasa:
	//table.lepes(0, 'B', 2); // 2x nem lephet u.az a jatekos egymas utan!
	//table.lepes(1, 'A', 3); // ez a mezo foglalt!
	//table.lepes(2, 'B', 2); // csak 2 jatekos van: 0 es 1
	//table.lepes(1, 'E', 2); // E sor nincs mert 4x4-es
	//table.lepes(1, 'B', 23); // 23. oszlop nincs

	//table.lepes(1, 'B', 2); // OK

	table.draw();
}