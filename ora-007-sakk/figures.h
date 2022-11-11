#pragma once

class ChessFigure {
	std::string color;
public:
	ChessFigure(std::string color) : color(color) {}
};

class Pawn : public ChessFigure {
public:
	Pawn(const std::string& color) :
		ChessFigure(color) {}
};