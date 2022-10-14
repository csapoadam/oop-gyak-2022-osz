#pragma once
#include "printUtils.h"
#include <iostream>

class GPSKoordinata {
	double latitude, longitude;
public:
	GPSKoordinata(int lat, int lon) :
		latitude(lat), longitude(lon) {}
	void print(int indent) {
		printIndents(indent);
		std::cout << "GPS koordinatak: " << latitude;
		std::cout << ", " << longitude << std::endl;
	}
};