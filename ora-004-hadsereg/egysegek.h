#pragma once
#include "gps.h"
#include "printUtils.h"
#include <iostream>



class GyalogosEgyseg {
	int hanyFo;
	GPSKoordinata gps;
public:
	GyalogosEgyseg(int hanyFo, double gpslat, double gpslon):
		hanyFo(hanyFo), gps(gpslat, gpslon) {}
	void print(int indent) {
		printIndents(indent);
		std::cout << hanyFo << " fobol allo csapat" << std::endl;
		gps.print(indent);
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
		gps.print(indent);
	}
};