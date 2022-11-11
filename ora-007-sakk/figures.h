#pragma once

enum class Color {
	black,
	white
};

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
	Pawn(const std::string& color) : ChessFigure(color) {}
	std::string asString() {
		if (getColor() == "white") return "wP";
		return "bP";
	}
};

class Rook : public ChessFigure {
public:
	Rook(const std::string& color) : ChessFigure(color) {}
	std::string asString() {
		if (getColor() == "white") return "wR";
		return "bR";
	}
};

class Knight : public ChessFigure {
public:
	Knight(const std::string& color) : ChessFigure(color) {}
	std::string asString() {
		if (getColor() == "white") return "wN";
		return "bN";
	}
};

class Bishop : public ChessFigure {
public:
	Bishop(const std::string& color) : ChessFigure(color) {}
	std::string asString() {
		if (getColor() == "white") return "wB";
		return "bB";
	}
};

class Queen : public ChessFigure {
public:
	Queen(const std::string& color) : ChessFigure(color) {}
	std::string asString() {
		if (getColor() == "white") return "wQ";
		return "bQ";
	}
};

class King : public ChessFigure {
public:
	King(const std::string& color) : ChessFigure(color) {}
	std::string asString() {
		if (getColor() == "white") return "wK";
		return "bK";
	}
};