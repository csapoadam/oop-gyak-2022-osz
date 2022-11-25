#include <type_traits>
#include <string>
#include <iostream>

// Keszitsen el 3 osztalyt: Device, Computer es Laptop
// Device egy absztrakt ososztaly, melynek print() metodusa
// nincs megvalositva
// Computer es Laptop egyfajta Device (szarmaznak belole) es
// megvalositjak a print() metodust

class Device {
	std::string name;
public:
	Device(const std::string& nm) : name(nm) {}
	virtual void print() = 0;
	std::string getName() { return name; }
};

class Computer : public Device {
public:
	Computer(const std::string& nev) : Device(nev) { }
	void print() override {
		std::cout << getName() << " gep vagyok" << std::endl;
	}
};

class Laptop : public Device {
public:
	Laptop(const std::string& nev) : Device(nev) { }
	void print() override {
		std::cout << getName() << " laptop vagyok" << std::endl;
	}
};

enum class DeviceType {
	Computer,
	Laptop
};

// Keszitsen el egy DeviceFactory nevu osztalyt, melynek egyetlen
// publikus statikus fv-e van:
// Device* NewDevice(const std::string&)
// szignaturval

int main() {
	static_assert(
		std::is_abstract<Device>(),
		"Device ought to be abstract."
	);
	Device* computer =
		DeviceFactory::NewDevice(DeviceType::Computer, "IBM Business");
	Device* laptop =
		DeviceFactory::NewDevice(DeviceType::Laptop, "Asus TUF");

	computer->print(); // IBM Business gep vagyok
	laptop->print(); // Asus TUF laptop vagyok

	delete computer;
	delete laptop;
}