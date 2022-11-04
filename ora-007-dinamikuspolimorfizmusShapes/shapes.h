#pragma once
#include <math.h>
#include <string>

class Shape {
	std::string type;
public:
	Shape (const std::string& type) : type(type) {}
	virtual double area() = 0;
	std::string printType() { return type; }
	bool isLargerThan(Shape* other) {
		return area() > other->area();
	}
};

class Point2D {
	int x, y;
public:
	Point2D(int xc, int yc) : x(xc), y(yc) {}
	double distance(const Point2D& other) {
		return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
	}
};

class Rectangle : public Shape {
	Point2D balf, bala, jobbf, jobba;
public:
	Rectangle(Point2D bf, Point2D ba, Point2D ja, Point2D jf) :
		Shape("Teglalap"), balf(bf), bala(ba), jobbf(jf), jobba(ja)
	{}
	Rectangle(Rectangle& other) = delete;
	Rectangle& operator=(Rectangle& other) = delete;
	double area() override {
		return balf.distance(bala) * bala.distance(jobba);
	}
};

class Circle : public Shape {
	Point2D kozepe;
	int sugar;
public:
	Circle(Point2D center, int rad) :
		Shape("Kor"), kozepe(center), sugar(rad)
	{}
	Circle(Circle& other) = delete;
	Circle& operator=(Circle& other) = delete;
	double area() override {
		return sugar * sugar * 3.14;
	}
};