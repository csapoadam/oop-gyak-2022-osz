#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "figures.h"

class ChessGame {
	// Tobb teendo is van:
	// 1.) Chess Figure es Pawn osztalyok vaza legyen meg, hogy forduljon
	// 2.) Erdemes lenne a Tablahoz tartozo funkciokat egy
	// ChessTable osztalyba kiszervezni. A ChessGame csak a jatszmaval foglalkozzon!
	// 3.) Tomorebb kodot eredmenyez, ha a ChessTable osztalyban lenne ilyen hivas, hogy
	// fillRow(), vagy defaultRow(szin), ...
	bool isWhiteTurn;
	std::vector < std::vector<ChessFigure*> > tableRows;
public:
	ChessGame() : isWhiteTurn(true) {
		std::vector<ChessFigure*> row1;
		for (int i = 0; i < 8; i++) {
			// ide majd mas kell, most legyenek gyalogok
			row1.push_back(new Pawn("white"));
		}
		tableRows.push_back(row1);

		std::vector<ChessFigure*> row2;
		for (int i = 0; i < 8; i++) {
			row2.push_back(new Pawn("white"));
		}
		tableRows.push_back(row2);

		std::vector<ChessFigure*> row3;
		for (int i = 0; i < 8; i++) {
			row3.push_back(nullptr);
		}
		tableRows.push_back(row3);

		std::vector<ChessFigure*> row4;
		for (int i = 0; i < 8; i++) {
			row4.push_back(nullptr);
		}
		tableRows.push_back(row4);

		std::vector<ChessFigure*> row5;
		for (int i = 0; i < 8; i++) {
			row5.push_back(nullptr);
		}
		tableRows.push_back(row5);

		std::vector<ChessFigure*> row6;
		for (int i = 0; i < 8; i++) {
			row6.push_back(nullptr);
		}
		tableRows.push_back(row6);

		std::vector<ChessFigure*> row7;
		for (int i = 0; i < 8; i++) {
			row7.push_back(new Pawn("black"));
		}
		tableRows.push_back(row7);

		std::vector<ChessFigure*> row8;
		for (int i = 0; i < 8; i++) {
			// ide majd mas kell, most legyenek gyalogok
			row8.push_back(new Pawn("black"));
		}
		tableRows.push_back(row8); // push_back egy masolatot keszit
		// ezert csak akkor hivjuk meg, ha mar tele van a sor!
		// ennek mar nincs hatasa tableRows szempontjabol:
		// row8.push_back("akarmi")

	}
	~ChessGame() {
		for (int row = 0; row < 8; row++) {
			for (int col = 0; col < 8; col++) {
				if (tableRows[row][col] != nullptr) {
					// ezen a mezon egy ChessFigure* van
					// de ez lehet Pawn, ... (tobbfele figura)
					// ezert kell a ChessFigure osztalyban virtualis destruktor
					// hogy mindig a megfelelo destruktor hivodjon meg
					delete tableRows[row][col];
				}
			}
		}
	}
	void draw() {
		std::cout << "  | A  | B  | C  | D  | E  | F  | G  | H  |";
		std::cout << std::endl;
		std::cout << "  -----------------------------------------";
		std::cout << std::endl;

		for (int row = 7; row > -1; row--) {
			std::cout << (row + 1) << " |";
			for (int field = 0; field < 8; field++) {
				ChessFigure* figPtr = tableRows[row][field];
				if (!figPtr) { // ha tehat nullptr
					std::cout << "    |";
				}
				else {
					std::cout << " " << figPtr->asString() << " |";
				}
			}
			std::cout << std::endl;
		}
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