#pragma once
#include "gps.h"
#include "printUtils.h"
#include <iostream>

class Egyseg {
	GyalogosEgyseg* gep;
	LegiEgyseg* lep;
	HajosEgyseg* hep;
	GPSKoordinata gps;
public:
	~Egyseg() {
		if (gep) delete gep;
		if (hep) delete hep;
		if (lep) delete lep;
	}
	// gyalogos es legi:
	Egyseg(int egysegTipus, int hanyFoVagyMagassag, double lat, double lon) :
		gep(nullptr), lep(nullptr), hep(nullptr), gps(lat, lon)
	{
		if (egysegTipus == 0) {
			// gyalogos

			// igy nem jo, mert g torlodik a stackrol, mihelyt visszater a konstruktor!
			//GyalogosEgyseg g(hanyFoVagyMagassag, lat, lon); //...
			//gep = &g;
			// helyette:
			gep = new GyalogosEgyseg(hanyFoVagyMagassag);
		}
		else if (egysegTipus == 1) {
			// legi egyseg
			lep = new LegiEgyseg(hanyFoVagyMagassag);
		}
	}
	// hajos:
	Egyseg(int egysegTipus, int legenyseg, double hatotav, double lat, double lon) :
		gep(nullptr), lep(nullptr), hep(nullptr), gps(lat, lon)
	{
		if (egysegTipus == 2) {
			// hajos egyseg
			hep = new HajosEgyseg(legenyseg, hatotav);
		}
	}

	void print() {
		if (gep != nullptr) {
			std::cout << "Gyalogos egyseg: " << std::endl;
			gep->print(1);
			gps.print(1);
		}
		if (lep != nullptr) {
			std::cout << "Legi egyseg: " << std::endl;
			lep->print(1);
			gps.print(1);
		}
		if (hep != nullptr) {
			std::cout << "Hajos egyseg: " << std::endl;
			hep->print(1);
			gps.print(1);
		}
	}
};

class GyalogosEgyseg : public Egyseg {
	int hanyFo;
public:
	GyalogosEgyseg(int hanyFo, double lat, double lon):
		hanyFo(hanyFo) {}
	void print(int indent) {
		printIndents(indent);
		std::cout << hanyFo << " fobol allo csapat" << std::endl;
	}
};

class LegiEgyseg : public Egyseg {
	int maxMagassag;
public:
	LegiEgyseg(int maxmagassag, double lat, double lon):
		maxMagassag(maxmagassag)
	{}
	void print(int indent) {
		printIndents(indent);
		std::cout << "maximum magassag: " << maxMagassag << std::endl;
	}
};

class HajosEgyseg : public Egyseg {
	int legenyseg;
	double hatotavolsag;
public:
	HajosEgyseg(int legenyseg, double hatotav, double lat, double lon) :
		legenyseg(legenyseg), hatotavolsag(hatotav)
	{}
	void print(int indent) {
		printIndents(indent);
		std::cout << legenyseg << " fobol allo hajo" << std::endl;
		printIndents(indent);
		std::cout << "hatotavolsag: " << hatotavolsag << std::endl;
	}
};