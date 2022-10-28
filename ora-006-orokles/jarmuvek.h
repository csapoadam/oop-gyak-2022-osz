#pragma once
#include <iostream>

class Jarmu {
	std::string gyarto;
public:
	Jarmu(const std::string& gy) : gyarto(gy) {}
	virtual void print() { std::cout << "nem csinalok semmit"; }
	const std::string& getGyarto() { return gyarto; }
};

class Auto : public Jarmu {
	std::string loero;
public:
	Auto(const std::string gy, const std::string& le) :
		Jarmu(gy), loero(le) {}
	void print() {
		std::cout << getGyarto() << " " << loero << " motorral";
		std::cout << std::endl;
	}
};

class Repulo : public Jarmu {
	int sebesseg;
public:
	Repulo(const std::string gy, int seb) :
		Jarmu(gy), sebesseg(seb) {}
	void print() {
		std::cout << getGyarto() << " " << sebesseg;
		std::cout << " km/h sebesseggel";
		std::cout << std::endl;
	}
};