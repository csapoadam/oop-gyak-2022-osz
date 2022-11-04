#pragma once
#include <math.h>

class Shape {
public:
	virtual double area() = 0;
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
		balf(bf), bala(ba), jobbf(jf), jobba(ja)
	{}
	double area() override {
		return balf.distance(bala) * bala.distance(jobba);
	}
};

class Circle : public Shape {
	Point2D kozepe;
	int sugar;
public:
	Circle(Point2D center, int rad) :
		kozepe(center), sugar(rad)
	{}
	double area() override {
		return sugar * sugar * 3.14;
	}
};