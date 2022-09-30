#pragma once
#include <vector>

class AmobaTabla {
	const int numRows;
	const int numCols;
	// kulso vektor annyi vektort tartalmaz, ahany SOR van
	// belso vektorok annyi char-t tartalmaznak, ahany OSZLOP van
	std::vector< std::vector<char> > table; // lehetne dinamikusan allokalt mem.-mel is
	int previousPlayer;

	int charToRowNumber(char ch) {
		return (int)ch - 65;
	}
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
		previousPlayer = -1;
	}

	void lepes(int player, char row, int col) {
		if (
			player == previousPlayer ||
			player < 0 ||
			player > 1
		) {
			// az elobb is ugyano lepett vagy nem definialt player
			return;
		}
		int rowAsInt = charToRowNumber(row);
		if (rowAsInt > 0 && rowAsInt < numRows) {
			if (col > 0 && col < numCols) {
				if (table[rowAsInt][col] == '.') {
					// lepes vegbe mehet!
					table[rowAsInt][col] =
						player == 0 ? 'X' : 'O';
					
					previousPlayer = player;
				}
			}
		}
	}
};