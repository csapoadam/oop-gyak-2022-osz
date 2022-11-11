#pragma once

class ChessFigure {
	std::string color;
public:
	ChessFigure(std::string color) : color(color) {}
	virtual ~ChessFigure() {}
	std::string getColor() { return color; }
	virtual std::string asString() = 0;
};

class Pawn : public ChessFigure {
public:
	Pawn(const std::string& color) :
		ChessFigure(color) {}
	std::string asString() {
		if (getColor() == "white") {
			return "wP";
		}
		else {
			return "bP";
		}
	}
};