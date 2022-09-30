#pragma once
#include "AmobaTabla.h"

class AmobaJatek {
	const int numRows;
	const int numCols;
	const int numToWin;
	AmobaTabla table;

	int getNforPlayerInDirection(int player_0or1, int rowInit, int colInit, int addToRow, int addToCol) {
		int returnVal = 0;
		int rowNum = rowInit;
		int colNum = colInit;

		while (true) {
			rowNum = rowNum + addToRow;
			colNum = colNum + addToCol;
			if (rowNum < numRows && colNum < numCols &&
				rowNum > -1 && colNum > -1 &&
				table.getPlayerAt(rowNum, colNum) == player_0or1)
			{
				returnVal += 1;
			} else {
				return returnVal;
			}
		}

		return returnVal; // ez igazabol felesleges...

	}

	bool testForWin(int player_0or1, int row_1toN, int col_1toN) {
		//vizszintes esetben csak a col modosul:
		int numLeftRight = 1;

		numLeftRight += getNforPlayerInDirection(player_0or1, row_1toN - 1, col_1toN - 1, 0, 1);
		numLeftRight += getNforPlayerInDirection(player_0or1, row_1toN - 1, col_1toN - 1, 0, -1);

		if (numLeftRight >= numToWin) {
			return true;
		}

		int numTopToBottom = 1;
		
		numTopToBottom += getNforPlayerInDirection(player_0or1, row_1toN - 1, col_1toN - 1, 1, 0);
		numTopToBottom += getNforPlayerInDirection(player_0or1, row_1toN - 1, col_1toN - 1, -1, 0);

		if (numTopToBottom >= numToWin) {
			return true;
		}

		int numNwToSe = 1;
		
		numNwToSe += getNforPlayerInDirection(player_0or1, row_1toN - 1, col_1toN - 1, -1, -1);
		numNwToSe += getNforPlayerInDirection(player_0or1, row_1toN - 1, col_1toN - 1, 1, 1);

		if (numNwToSe >= numToWin) {
			return true;
		}

		int numNeToSw = 1;

		numNeToSw += getNforPlayerInDirection(player_0or1, row_1toN - 1, col_1toN - 1, 1, -1);
		numNeToSw += getNforPlayerInDirection(player_0or1, row_1toN - 1, col_1toN - 1, -1, 1);

		if (numNeToSw >= numToWin) {
			return true;
		}

		return false;
	}

public:
	AmobaJatek(int nRows, int nCols, int nToWin) :
		numRows(nRows), numCols(nCols), table(nRows, nCols), numToWin(nToWin) {}

	int play() {
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
					// ket lehetoseg:
					// ha a Tabla osztaly feladata megmondani, hogy nyert-e a lepes,
					// ez stimmelhet mert o tudja egyedul, hogy hol van kor meg x stb.
					// (hogy milyen szimbolumokat hasznal a tablan)

					// viszont, ha a jatek szabalyai valtoznak, es tores is megengedett pl.
					// ezt csak a Jatek osztaly tudja megmondani (hogy mik a szabalyok)
					// -> ilyenkor azt kell tudnia lekerdezni, hogy adott mezon milyen jatekos korongja van
					
					// most a 2. opciot valasztjuk.. mindket index 1-tol indul
					bool hasWon = this->testForWin(nextPlayer, nextRow + 1, nextCol);
					if (hasWon) {
						table.draw();
						return nextPlayer + 1; // 1 vagy 2
					}

					if (table.isFull()) {
						table.draw();
						std::cout << "A tabla betelt!" << std::endl;
						return 0;
					}

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