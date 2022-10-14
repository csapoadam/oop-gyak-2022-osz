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

class HajosEgyseg {
	int legenyseg;
	double hatotavolsag;
	GPSKoordinata gps;
public:
	HajosEgyseg(int legenyseg, double hatotav, double gpslat, double gpslon) :
		legenyseg(legenyseg), hatotavolsag(hatotav), gps(gpslat, gpslon)
	{}
	void print(int indent) {
		printIndents(indent);
		std::cout << legenyseg << " fobol allo hajo" << std::endl;
		printIndents(indent);
		std::cout << "hatotavolsag: " << hatotavolsag << std::endl;
		gps.print(indent);
	}
};

class Egyseg {
	GyalogosEgyseg* gep;
	LegiEgyseg* lep;
	HajosEgyseg* hep;
public:
	~Egyseg() {
		if (gep) delete gep;
		if (hep) delete hep;
		if (lep) delete lep;
	}
	// gyalogos es legi:
	Egyseg(int egysegTipus, int hanyFoVagyMagassag, double lat, double lon) :
		gep(nullptr), lep(nullptr), hep(nullptr)
	{
		if (egysegTipus == 0) {
			// gyalogos

			// igy nem jo, mert g torlodik a stackrol, mihelyt visszater a konstruktor!
			//GyalogosEgyseg g(hanyFoVagyMagassag, lat, lon); //...
			//gep = &g;
			// helyette:
			gep = new GyalogosEgyseg(hanyFoVagyMagassag, lat, lon);
		}
		else if (egysegTipus == 1) {
			// legi egyseg
			lep = new LegiEgyseg(hanyFoVagyMagassag, lat, lon);
		}
	}
	// hajos:
	Egyseg(int egysegTipus, int legenyseg, double hatotav, double lat, double lon) :
		gep(nullptr), lep(nullptr), hep(nullptr)
	{
		if (egysegTipus == 2) {
			// hajos egyseg
			hep = new HajosEgyseg(legenyseg, hatotav, lat, lon);
		}
	}

	void print() {
		if (gep != nullptr) {
			std::cout << "Gyalogos egyseg: " << std::endl;
			gep->print(1);
		}
		if (lep != nullptr) {
			std::cout << "Legi egyseg: " << std::endl;
			lep->print(1);
		}
		if (hep != nullptr) {
			std::cout << "Hajos egyseg: " << std::endl;
			hep->print(1);
		}
	}
};