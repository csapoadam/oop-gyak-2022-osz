#pragma once
#include<string>
#include<iostream>

class Eszkoz {
public:
	void print() {
		std::cout << "En egy eszkoz vagyok" << std::endl;
	}
};

class Laptop : public Eszkoz {
	std::string marka;
	std::string cpu_arch;
	int mem_meret;
public:
	Laptop(	const std::string& maker,
			const std::string& processor,
			int memsz) :
		marka(maker),
		cpu_arch(processor),
		mem_meret(memsz)
	{}
};

class Okostelefon : public Eszkoz {
	std::string marka;
	std::string modell;
public:
	Okostelefon(const std::string& maker,
		const std::string& model) :
		marka(maker),
		modell(model)
	{}
};

class Okosora : public Eszkoz {
	std::string marka;
	std::string modell;
public:
	Okosora(const std::string& maker,
		const std::string& model) :
		marka(maker),
		modell(model)
	{}
};