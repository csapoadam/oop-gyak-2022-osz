#pragma once
#include <iostream>

void printIndents(int indent) {
	for (int ind = 0; ind < indent; ind++) {
		std::cout << "\t";
	}
}

class GyalogosEgyseg {
	int hanyFo;
	double gpsLatitude, gpsLongitude;
public:
	GyalogosEgyseg(int hanyFo, double gpslat, double gpslon):
		hanyFo(hanyFo), gpsLatitude(gpslat), gpsLongitude(gpslon) {}
	void print(int indent) {
		printIndents(indent);
		std::cout << hanyFo << " fobol allo csapat" << std::endl;
		printIndents(indent);
		std::cout << "GPS koordinatak: " << gpsLatitude << ", ";
		std::cout << gpsLongitude << std::endl;
	}
};

class LegiEgyseg {
	int maxMagassag;
	double gpsLatitude, gpsLongitude;
public:
	LegiEgyseg(int maxmagassag, double gpslat, double gpslon):
		maxMagassag(maxmagassag), gpsLatitude(gpslat), gpsLongitude(gpslon)
	{}
	void print(int indent) {
		printIndents(indent);
		std::cout << "maximum magassag: " << maxMagassag << std::endl;
		printIndents(indent);
		std::cout << "GPS koordinatak: " << gpsLatitude << ", ";
		std::cout << gpsLongitude << std::endl;
	}
};