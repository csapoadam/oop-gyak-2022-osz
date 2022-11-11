#pragma once
#include <iostream>
#include <string>

#include "table.h"

class ChessGame {
	// Tobb teendo is van:
	// 1.) Chess Figure es Pawn osztalyok vaza legyen meg, hogy forduljon
	// 2.) Erdemes lenne a Tablahoz tartozo funkciokat egy
	// ChessTable osztalyba kiszervezni. A ChessGame csak a jatszmaval foglalkozzon!
	// 3.) Tomorebb kodot eredmenyez, ha a ChessTable osztalyban lenne ilyen hivas, hogy
	// fillRow(), vagy defaultRow(szin), ...
	// 4.) a szin az ne string legyen, mint "white" vagy "black", mert
	// ezt konnyu elirni! Helyette csinaljunk enum class-t
	bool isWhiteTurn;
	ChessTable table;
	//std::vector < std::vector<ChessFigure*> > tableRows;
public:
	ChessGame() : isWhiteTurn(true) {
		// table::initialize() nem is kell, hiszen a konstruktor is
		// meg tudja csinalni, amit kell
	}
	void draw() {
		table.draw();
	}

	void getMove() {
		bool successfulMove = false;
		while (!successfulMove) {
			if (isWhiteTurn) {
				std::cout << "Enter White move: ";
				std::string move;
				std::getline(std::cin, move);
				// move lehet pl. PD4, vagy NF3...
				std::cout << "  move is: " << move << std::endl;
				if (table.isMoveAllowed(move)) {
					table.performMove(move); // ez a metodus pontositast is kerhet
					// ha ket figura is lephet ugyanoda...
					successfulMove = true;
					isWhiteTurn = false;
				}
			}
			else {
				std::cout << "Enter Black move: ";
				std::string move;
				std::getline(std::cin, move);
				std::cout << "  move is: " << move << std::endl;
				if (table.isMoveAllowed(move)) {
					table.performMove(move);
					successfulMove = true;
					isWhiteTurn = true;
				}
			}
		}
	}

	bool isFinished() {
		return false;
	}

	void printResult() {}
};