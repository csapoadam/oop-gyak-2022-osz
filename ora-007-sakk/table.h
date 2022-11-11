#pragma once
#include <vector>

#include "figures.h"

class ChessTable {
	std::vector < std::vector<ChessFigure*> > table;
	void initializeAsEmpty() {
		for (int row = 0; row < 8; row++) {
			std::vector<ChessFigure*> rowN;
			for (int col = 0; col < 8; col++) {
				rowN.push_back(nullptr);
			}
			table.push_back(rowN);
		}
	}
	void fillWithPawns(Color color, int rowNum) {
		for (int col = 0; col < 8; col++) {
			table[rowNum][col] = new Pawn(color);
		}
	}
	void fillWithOfficers(Color color, int rowNum) {
		table[rowNum][0] = new Rook(color);
		table[rowNum][1] = new Knight(color);
		table[rowNum][2] = new Bishop(color);
		table[rowNum][3] = new Queen(color);
		table[rowNum][4] = new King(color);
		table[rowNum][5] = new Bishop(color);
		table[rowNum][6] = new Knight(color);
		table[rowNum][7] = new Rook(color);
	}
	void setupInitial(Color color) {
		if (color == Color::white) { // elso ket sorrol van szo
			fillWithPawns(Color::white, 1); // 2. sor
			fillWithOfficers(Color::white, 0); // 1. sor
		}
		else { // 7. es 8. sorrol van szo
			fillWithPawns(Color::black, 6); // 7. sor
			fillWithOfficers(Color::black, 7); // 8. sor
		}
	}
public:
	ChessTable() {
		initializeAsEmpty();
		setupInitial(Color::white);
		setupInitial(Color::black);
	}
	~ChessTable() {
		for (int row = 0; row < 8; row++) {
			for (int col = 0; col < 8; col++) {
				// ha nem nullptr akkor delete kell!
				if (table[row][col]) delete table[row][col];
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
			for (int col = 0; col < 8; col++) {
				ChessFigure* figPtr = table[row][col];
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
};