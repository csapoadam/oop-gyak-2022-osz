#include "game.h"

int main() {
	ChessGame game;

	game.draw();

	while (true) {
		bool success = false;
		while (!success) {
			success = game.getMove();
		}

		game.draw();

		if (game.isFinished()) {
			break;
		}
	}
}
