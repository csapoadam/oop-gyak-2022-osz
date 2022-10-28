#pragma once
#include "printUtils.h"
#include <iostream>

class GPSKoordinata {
	double latitude, longitude;
public:
	GPSKoordinata(double lat, double lon) :
		latitude(lat), longitude(lon) {}
	void print(int indent) {
		printIndents(indent);
		std::cout << "GPS koordinatak: " << latitude;
		std::cout << ", " << longitude << std::endl;
	}
};