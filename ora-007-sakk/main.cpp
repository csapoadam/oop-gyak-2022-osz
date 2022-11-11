#include "game.h"

int main() {
	ChessGame game;

	while (!game.isFinished()) {
		game.draw();
		game.getMove(); // gondoskodjon getMove() a success / failure-rol!
	}
	game.draw(); // hadd lassuk az utolso allapotot!
	game.printResult();
}
