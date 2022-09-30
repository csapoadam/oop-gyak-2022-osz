#pragma once
#include "AmobaTabla.h"

class AmobaJatek {
	const int numRows;
	const int numCols;
	const int numToWin;
	AmobaTabla table;
public:
	AmobaJatek(int nRows, int nCols, int nToWin) :
		numRows(nRows), numCols(nCols), table(nRows, nCols) {}

	void play() {
		int nextPlayer = 0;
		char nextRowAsChar;
		int nextRow;
		int nextCol;

		table.draw();

		while (true) {
			std::cout << "Gepelje be " << nextPlayer + 1 << ". jatekos lepeset! (kilepeshez: 'q')";
			char maxRowAsChar = (char)(64 + numRows);
			std::cout << std::endl << "sor (A-" << maxRowAsChar << "): ";
			std::cin >> nextRowAsChar;
			nextRow = (int)nextRowAsChar;
			if (nextRow == 113) { break; }

			nextRow = nextRow - 65;
			std::cout << "oszlop (1-" << numCols << ") ";
			std::cin >> nextCol;

			if (nextRow > -1 && nextCol > 0 && nextRow < numRows && nextCol < numCols + 1) {
				bool success = table.step(nextPlayer, nextRow, nextCol-1);
				// TODO: csak akkor leptetjuk, ha step sikeres volt!
				if (success) {
					nextPlayer = 1 - nextPlayer;
				}
				else {
					std::cout << "Ide mar nem lehet lepni!" << std::endl;
				}
			}
			else {
				std::cout << "Nincs ilyen sor vagy oszlop!" << std::endl;
			}
			
			table.draw();
		}
	}

};