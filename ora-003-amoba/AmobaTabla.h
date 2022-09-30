#pragma once
#include <vector>
#include <iostream>

class AmobaTabla {
	const int numRows;
	const int numCols;
	// kulso vektor annyi vektort tartalmaz, ahany SOR van
	// belso vektorok annyi char-t tartalmaznak, ahany OSZLOP van
	std::vector< std::vector<char> > table; // lehetne dinamikusan allokalt mem.-mel is

public:
	AmobaTabla(int rows, int cols) :
		numRows(rows), numCols(cols) {
		for (int row = 0; row < numRows; row++) {
			std::vector<char> rowvec;
			for (int col = 0; col < numCols; col++) {
				rowvec.push_back('.');
			}
			table.push_back(rowvec);
		}
	}

	bool isFull() {
		for (int row = 0; row < numRows; row++) {
			for (int col = 0; col < numCols; col++) {
				if (table[row][col] == '.') {
					return false;
				}
			}
		}
		return true;
	}

	bool step(int player, int row, int col) {
		if (table[row][col] == '.') {
			// lepes vegbe mehet!
			table[row][col] = player == 0 ? 'X' : 'O';
			return true;
		}
		else {
			return false;
		}
	}

	int getPlayerAt(int row, int col) {
		if (table[row][col] == 'X') { return 0; }
		if (table[row][col] == 'O') { return 1; }
		return -1;
	}

	void draw() {
		// fejlec
		std::cout << " ";
		for (int i = 0; i < numCols; i++) {
			std::cout << " " << i + 1;
		}
		std::cout << std::endl << " ";

		for (int i = 0; i < 2 * numCols + 1; i++) {
			std::cout << "-";
		}
		std::cout << std::endl;

		for (int row = 0; row < numRows; row++) {
			int rowAscii = row + 65;
			std::cout << (char)rowAscii << "|";
			for (int col = 0; col < numCols; col++) {
				std::cout << table[row][col] << "|";
			}
			std::cout << std::endl;
		}

		//lablec
		std::cout << " ";
		for (int i = 0; i < 2 * numCols + 1; i++) {
			std::cout << "-";
		}
		std::cout << std::endl;
	}
};