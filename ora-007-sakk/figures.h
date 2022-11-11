#pragma once

enum class Color {
	black,
	white
};

class ChessFigure {
	Color color;
public:
	ChessFigure(Color color) : color(color) {}
	virtual ~ChessFigure() {}
	Color getColor() { return color; }
	virtual std::string asString() = 0;
};

class Pawn : public ChessFigure {
public:
	Pawn(Color color) : ChessFigure(color) {}
	std::string asString() {
		if (getColor() == Color::white) return "wP";
		return "bP";
	}
};

class Rook : public ChessFigure {
public:
	Rook(Color color) : ChessFigure(color) {}
	std::string asString() {
		if (getColor() == Color::white) return "wR";
		return "bR";
	}
};

class Knight : public ChessFigure {
public:
	Knight(Color color) : ChessFigure(color) {}
	std::string asString() {
		if (getColor() == Color::white) return "wN";
		return "bN";
	}
};

class Bishop : public ChessFigure {
public:
	Bishop(Color color) : ChessFigure(color) {}
	std::string asString() {
		if (getColor() == Color::white) return "wB";
		return "bB";
	}
};

class Queen : public ChessFigure {
public:
	Queen(Color color) : ChessFigure(color) {}
	std::string asString() {
		if (getColor() == Color::white) return "wQ";
		return "bQ";
	}
};

class King : public ChessFigure {
public:
	King(Color color) : ChessFigure(color) {}
	std::string asString() {
		if (getColor() == Color::white) return "wK";
		return "bK";
	}
};