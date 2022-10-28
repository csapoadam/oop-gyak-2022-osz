#pragma once
#include<string>
#include<iostream>

class Eszkoz {
	std::string marka;
public:
	Eszkoz(const std::string& maker) :
		marka(maker)
	{}
	void print() {
		std::cout << marka << " eszkoz" << std::endl;
		//std::cout << "En egy eszkoz vagyok" << std::endl;
	}
};

class Laptop : public Eszkoz {
	std::string cpu_arch;
	int mem_meret;
public:
	Laptop(	const std::string& maker,
			const std::string& processor,
			int memsz) :
		Eszkoz(maker),
		cpu_arch(processor),
		mem_meret(memsz)
	{}
};

class Okostelefon : public Eszkoz {
	std::string modell;
public:
	Okostelefon(const std::string& maker,
		const std::string& model) :
		Eszkoz(maker),
		modell(model)
	{}
};

class Okosora : public Eszkoz {
	std::string modell;
public:
	Okosora(const std::string& maker,
		const std::string& model) :
		Eszkoz(maker),
		modell(model)
	{}
};