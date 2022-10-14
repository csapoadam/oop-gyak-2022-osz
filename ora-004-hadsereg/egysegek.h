#pragma once
#include <iostream>

void printIndents(int indent) {
	for (int ind = 0; ind < indent; ind++) {
		std::cout << "\t";
	}
}

class GPSKoordinata {

};

class GyalogosEgyseg {
	int hanyFo;
	GPSKoordinata gps;
public:
	GyalogosEgyseg(int hanyFo, double gpslat, double gpslon):
		hanyFo(hanyFo), gps(gpslat, gpslon) {}
	void print(int indent) {
		printIndents(indent);
		std::cout << hanyFo << " fobol allo csapat" << std::endl;
		printIndents(indent);
		gps.print();
	}
};

class LegiEgyseg {
	int maxMagassag;
	GPSKoordinata gps;
public:
	LegiEgyseg(int maxmagassag, double gpslat, double gpslon):
		maxMagassag(maxmagassag), gps(gpslat, gpslon)
	{}
	void print(int indent) {
		printIndents(indent);
		std::cout << "maximum magassag: " << maxMagassag << std::endl;
		printIndents(indent);
		gps.print();
	}
};