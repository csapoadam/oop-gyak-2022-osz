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

	bool getMove() {
		if (isWhiteTurn) {
			std::cout << "Enter White move: ";
			std::string move;
			std::getline(std::cin, move);
			std::cout << "  move is: " << move << std::endl;
			isWhiteTurn = false;
		}
		else {
			std::cout << "Enter Black move: ";
			std::string move;
			std::getline(std::cin, move);
			std::cout << "  move is: " << move << std::endl;
			isWhiteTurn = true;
		}
		return true;
	}

	bool isFinished() {
		return false;
	}
};