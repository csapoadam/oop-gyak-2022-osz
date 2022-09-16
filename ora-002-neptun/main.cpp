#include "hallgatoDb.h"

using namespace Neptun; // nagy projekteknel nem javasolt
// mivel baj, ha 2 nevterben is letezik u.az a tipus vagy fv

int main() {
	HallgatoDb hallgatok;
	hallgatok.add("Kocsis Balint", "RBV23Q");
	hallgatok.add("Szabo Tibor", "QKX7R1");
	hallgatok.add("Nemeth Iren", "AABIK5");
	hallgatok.printDb();
}