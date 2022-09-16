#include "hallgatoDb.h"

using namespace Neptun; // nagy projekteknel nem javasolt
// mivel baj, ha 2 nevterben is letezik u.az a tipus vagy fv

int main() {
	HallgatoDb hallgatok;
	hallgatok.add("Kocsis Balint", "RBV23Q");
	hallgatok.printDb();
}