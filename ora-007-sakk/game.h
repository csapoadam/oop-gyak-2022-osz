#pragma once
#include <iostream>
#include <string>
#include <vector>

class ChessGame {
	bool isWhiteTurn;
	std::vector < std::vector<ChessFigure*> > tableRows;
public:
	ChessGame() : isWhiteTurn(true) {
		std::vector<ChessFigure*> row1;
		tableRows.push_back(row1);
		for (int i = 0; i < 8; i++) {
			// ide majd mas kell, most legyenek gyalogok
			row1.push_back(new Pawn("white"));
		}

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
		tableRows.push_back(row5);
		for (int i = 0; i < 8; i++) {
			row5.push_back(nullptr);
		}
		std::vector<ChessFigure*> row6;
		tableRows.push_back(row6);
		for (int i = 0; i < 8; i++) {
			row3.push_back(nullptr);
		}
		std::vector<ChessFigure*> row7;
		for (int i = 0; i < 8; i++) {
			row7.push_back(new Pawn("black"));
		}
		tableRows.push_back(row7);

		std::vector<ChessFigure*> row8;
		for (int i = 0; i < 8; i++) {
			// ide majd mas kell, most legyenek gyalogok
			row1.push_back(new Pawn("black"));
		}
		tableRows.push_back(row8);
	}
	void draw() {
		std::cout << "  | A | B | C | D | E | F | G | H |";
		std::cout << std::endl;
		std::cout << "8 |   |   |   |   |   |   |   |   |";
		std::cout << std::endl;
		std::cout << "7 |   |   |   |   |   |   |   |   |";
		std::cout << std::endl;
		std::cout << "6 |   |   |   |   |   |   |   |   |";
		std::cout << std::endl;
		std::cout << "5 |   |   |   |   |   |   |   |   |";
		std::cout << std::endl;
		std::cout << "4 |   |   |   |   |   |   |   |   |";
		std::cout << std::endl;
		std::cout << "3 |   |   |   |   |   |   |   |   |";
		std::cout << std::endl;
		std::cout << "2 |   |   |   |   |   |   |   |   |";
		std::cout << std::endl;
		std::cout << "1 |   |   |   |   |   |   |   |   |";
		std::cout << std::endl;
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