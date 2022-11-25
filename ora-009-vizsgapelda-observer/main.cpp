#include <type_traits>
#include <string>
#include <iostream>

// Keszitsen el egy Helyiseg nevu absztrakt osztalyt, melynek
// setHomerseklet(double) metodusa beallitja a homersekletet
// es printTemperature() metodusa egy sztringet var, de nincs
// megvalositva

// Ebbol szarmazzon a Szoba osztaly, melynek printTemperature(str)
// metodusa str = "hun" eseten magyarul irja ki a homersekletet,
// str = "eng" eseten pedig angolul.

// Keszitse el a Tanterem osztalyt is, ami szinten egyfajta Helyiseg.
// A Helyiseg osztalynak legyen egy setPara() metodusa is, ami a
// paratartalmat beallitja.
// printHumidity(std::string lang) pedig kiirja adott nyelven

class Helyiseg {
protected:
	double homerseklet;
	int para;
public:
	void setHomerseklet(double temp) { homerseklet = temp; }
	void setPara(int paratartalom) { para = paratartalom; }
	virtual void printTemperature(std::string language) = 0;
	virtual void printHumidity(std::string language) = 0;
};

class Szoba : public Helyiseg {
	std::string nev;
public:
	Szoba(std::string nev) : nev(nev) {}
	void printTemperature(std::string lang) {
		if (lang == "hun") {
			std::cout << "Homerseklet a " << nev;
			std::cout << " szobaban: " << homerseklet;
			std::cout << std::endl;
		} else if (lang == "eng") {
			std::cout << "Temperature in " << nev;
			std::cout << " : " << homerseklet;
			std::cout << std::endl;
		}
	}
	void printHumidity(std::string lang) {
		if (lang == "hun") {
			std::cout << "Paratartalom a " << nev;
			std::cout << " szobaban: " << para;
			std::cout << std::endl;
		}
		else if (lang == "eng") {
			std::cout << "Humidity in " << nev;
			std::cout << " : " << para;
			std::cout << std::endl;
		}
	}
};

class Tanterem : public Helyiseg {
	std::string nev;
	int ferohely;
public:
	Tanterem(std::string nev, int ferohely) : nev(nev), ferohely(ferohely) {}
	void printTemperature(std::string lang) {
		if (lang == "hun") {
			std::cout << "Homerseklet a " << nev;
			std::cout << " tanteremben: " << homerseklet;
			std::cout << std::endl;
		}
		else if (lang == "eng") {
			std::cout << "Temperature in " << nev;
			std::cout << " : " << homerseklet;
			std::cout << std::endl;
		}
	}
	void printHumidity(std::string lang) {
		if (lang == "hun") {
			std::cout << "Paratartalom a " << nev;
			std::cout << " tanteremben: " << para;
			std::cout << std::endl;
		}
		else if (lang == "eng") {
			std::cout << "Humidity in " << nev;
			std::cout << " : " << para;
			std::cout << std::endl;
		}
	}
};

#include <vector>

class Observer {
public:
	virtual void notify(double val) = 0;
};

class Observable {
	double value;
	std::vector<Observer*> subscribers;
public:
	void set(double val) {
		value = val;
		for (Observer* obs : subscribers) {
			obs->notify(val);
		}
	}
	void subscribe(Observer* obs) {
		subscribers.push_back(obs);
	}

};

class ObserverHumidityHun : public Observer {
public:
	virtual void notify(double val) {
		std::cout << "Uj paratartalom: " << val << " szazalek";
		std::cout << std::endl;
	}
};

class ObserverHumidityEng : public Observer {
public:
	virtual void notify(double val) {
		std::cout << "New humidity: " << val << " percent";
		std::cout << std::endl;
	}
};

class ObserverTemperatureEng : public Observer {
public:
	virtual void notify(double val) {
		std::cout << "Uj homerseklet: " << val << " fok";
		std::cout << std::endl;
	}
};

int main() {

	// Observer minta:
	// vannak Observable-ok... ilyen a homerseklet, paratartalom
	// (de mondjuk lehet a Szoba, meg Tanterem is)

	// vannak az Observerek, amik pedig ezek valtozasaira
	// figyelnek...

	// Kell egy ObservableTemperature, es ObservableHumidity osztaly
	// minden Helyiseg egyben egy ObserverableTemperature es
	// ObservableHumidity is egyben!

	// Kell egy ObserverTemperature, es ObserverHumidity is
	// amik ertesitest kapnak az uj ertekekrol. Ezek konkret tipusa
	// lehet a HelyisegObserverEng, meg HelyisegObserverHun
	// amik egyfajta ObserverTemperature es ObserverHumidity is
	// egyben!

	// Feladat:
	// Keszitsen egy Observable osztalyt,
	// void set(double) es void subscribe(Observer*)

	// Keszitsen egy Observer osztalyt, melynek altipusai
	// a ObserverTemperatureEng, ObserverHumidityEng es
	// ObserverHumidityHun
	// Observer osztalynak kell legyen egy notify() metodusa
	// melyet meghiv az Observable.set()

	Observable nappaliHomerseklet;
	Observable nappaliParatartalom;

	Observable haloszobaHomerseklet;
	Observable haloszobaParatartalom;

	static_assert(
		std::is_abstract<Observer>(), "Observer must be abstract"
		);

	ObserverHumidityHun obsHumHun;
	ObserverHumidityEng obsHumEng;
	ObserverTemperatureEng obsTempEng;

	nappaliHomerseklet.subscribe(&obsTempEng);
	haloszobaParatartalom.subscribe(&obsHumHun);
	haloszobaParatartalom.subscribe(&obsHumEng);

	std::cout << "miutan mindent beallitottunk: " << std::endl;

	nappaliHomerseklet.set(21.5);
	nappaliParatartalom.set(40);
	haloszobaHomerseklet.set(19.0);
	haloszobaParatartalom.set(55);





	//Helyiseg* nappali = new Szoba("nappali");
	//Helyiseg* haloszoba = new Szoba("haloszoba");

	//Helyiseg* d104 = new Tanterem("D104", 50); // 50 ferohelyes, D104 nevu tanterem

	//nappali->setHomerseklet(21.5);
	//haloszoba->setHomerseklet(19.0);

	//nappali->setPara(40);
	//haloszoba->setPara(55);

	//nappali->printTemperature("eng"); // Temperature in nappali: 21.5
	//haloszoba->printTemperature("hun"); // Homerseklet a haloszoba szobaban: 19.0

	//nappali->printHumidity("eng"); // Humidity in nappali: 40 percent
	//haloszoba->printHumidity("hun"); // Paraszint a haloszoba szobaban: 55 szazalek

	//delete nappali;
	//delete haloszoba;
	//delete d104;
}