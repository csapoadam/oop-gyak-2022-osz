

int main() {
	ChessGame game;

	while (true) {
		game.draw();

		bool success = false;
		while (!success) {
			success = game.getMove();
		}
		if (game.isFinished()) {
			break;
		}
}
