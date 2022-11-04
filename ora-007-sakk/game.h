#pragma once
#include <iostream>
#include <string>

class ChessGame {
	bool isWhiteTurn;
public:
	ChessGame() : isWhiteTurn(true) {}
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