#include <type_traits>
#include <string>
#include <iostream>
#include <vector>

template <typename T>
class Observer {
public:
	virtual void notify(T val, std::string context) = 0;
};

template <typename T>
class Observable {
	std::vector<Observer<T>*> subscribers;
	std::string context;
public:
	Observable(const std::string& ctx) : context(ctx) {}
	void set(T val) {
		for (Observer<T>* obs : subscribers) {
			obs->notify(val, context);
		}
	}
	void subscribe(Observer<T>* obs) {
		subscribers.push_back(obs);
	}
};

class Observer_HumidityHun : public Observer<int> {
public:
	virtual void notify(int val, std::string context) {
		std::cout << "Uj paratartalom a " << context << " helyisegben: " << val << " szazalek";
		std::cout << std::endl;
	}
};

class Observer_HumidityEng : public Observer<int> {
public:
	virtual void notify(int val, std::string context) {
		std::cout << "New humidity in " << context << ": " << val << " percent";
		std::cout << std::endl;
	}
};

class Observer_TemperatureEng : public Observer<double> {
public:
	virtual void notify(double val, std::string context) {
		std::cout << "New temperature in " << context << ": " << val << " degrees";
		std::cout << std::endl;
	}
};

class Helyiseg {
protected:
	Observable<double> obsable_Temp;
	Observable<int> obsable_Humi;
public:
	Helyiseg(const std::string& name) : obsable_Temp(name), obsable_Humi(name) {}
	void setTemperature(double temp) { obsable_Temp.set(temp); }
	void setHumidity(int humi) { obsable_Humi.set(humi); }
	void subscribeToTemperature(Observer<double>* obser) {
		obsable_Temp.subscribe(obser);
	}
	void subscribeToHumidity(Observer<int>* obser) {
		obsable_Humi.subscribe(obser);
	}
	
};

class Szoba : public Helyiseg {
public:
	Szoba(std::string nev) : Helyiseg(nev) {}
};

class Tanterem : public Helyiseg {
	int ferohely;
public:
	Tanterem(std::string nev, int ferohely) : Helyiseg(nev), ferohely(ferohely) {}
};

int main() {
	Helyiseg* nappali = new Szoba("nappali");
	Helyiseg* haloszoba = new Szoba("haloszoba");
	Helyiseg* d104 = new Tanterem("D104", 50); // 50 ferohelyes, D104 nevu tanterem

	Observer_HumidityEng ob_Humi_eng;
	Observer_HumidityHun ob_Humi_hun;
	Observer_TemperatureEng ob_Temp_eng;

	nappali->subscribeToTemperature(&ob_Temp_eng);
	nappali->subscribeToHumidity(&ob_Humi_eng);
	haloszoba->subscribeToTemperature(&ob_Temp_eng);
	haloszoba->subscribeToHumidity(&ob_Humi_hun);
	d104->subscribeToTemperature(&ob_Temp_eng);
	d104->subscribeToHumidity(&ob_Humi_hun);

	nappali->setTemperature(21.5);
	haloszoba->setTemperature(19.0);
	d104->setTemperature(22.1);

	nappali->setHumidity(40);
	haloszoba->setHumidity(55);
	d104->setHumidity(52);

	delete nappali;
	delete haloszoba;
	delete d104;
}