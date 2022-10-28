#pragma once
#include "gps.h"
#include "printUtils.h"
#include <iostream>

class Egyseg {
	GPSKoordinata gps;
public:
	// gyalogos es legi:
	Egyseg(double lat, double lon) :
		gps(lat, lon)
	{}
	
	// virtualis, mert nem tudjuk, milyen konkret egyseg tipus
	// print-jet akarjuk majd meghivni
	virtual void print(int indents) {}
};

class GyalogosEgyseg : public Egyseg {
	int hanyFo;
public:
	GyalogosEgyseg(int hanyFo, double lat, double lon):
		Egyseg(lat, lon), hanyFo(hanyFo) {}
	void print(int indent) {
		printIndents(indent);
		std::cout << hanyFo << " fobol allo gyalogos csapat" << std::endl;
		printIndents(indent);
		std::cout << "***" << std::endl;
	}
};

class LegiEgyseg : public Egyseg {
	int maxMagassag;
public:
	LegiEgyseg(int maxmagassag, double lat, double lon):
		Egyseg(lat, lon), maxMagassag(maxmagassag)
	{}
	void print(int indent) {
		printIndents(indent);
		std::cout << "Legi csapat, maximum magassag: " << maxMagassag << std::endl;
		printIndents(indent);
		std::cout << "***" << std::endl;
	}
};

class HajosEgyseg : public Egyseg {
	int legenyseg;
	double hatotavolsag;
public:
	HajosEgyseg(int legenyseg, double hatotav, double lat, double lon) :
		Egyseg(lat, lon), legenyseg(legenyseg), hatotavolsag(hatotav)
	{}
	void print(int indent) {
		printIndents(indent);
		std::cout << legenyseg << " fobol allo hajos egyseg" << std::endl;
		printIndents(indent);
		std::cout << hatotavolsag << " hatotavolsaggal" << std::endl;
		printIndents(indent);
		std::cout << "***" << std::endl;
	}
};