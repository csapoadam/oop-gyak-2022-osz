// main.cpp
#include <string>
#include <iostream>

class Date {
	int _day, _month, _year;
	static std::string monthNames[13];
public:
	Date(int day, int month, int year) {
		if (month < 1 || month > 12) {
			// mukodik de nem olyan jo mert a hivo fel
			// sosem ertesul rola h ez egy rossz datum:
			//_month = 1;	// ilyen honap nincs, ezert default ertek
			
			// masik opcio: kivetel eldobasa, de ez
			// halado tema:
			// throw std::exception("Hibas honap!");
			_month = 0;
		}
		else {
			_month = month;
		}
		_day = day;
		_year = year;
	}
	void print() {
		std::cout <<
			monthNames[_month] << " " <<
			_day << ", " <<
			_year << std::endl;
	}
};

std::string Date::monthNames[] = {
		"BADMONTH",
		"JAN", "FEB", "MAR", "APR",
		"MAY", "JUN", "JUL", "AUG",
		"SEP", "OCT", "NOV", "DEC"
};

int main() {
	Date jan1_1970(1, 1, 1970);
	jan1_1970.print(); // Elvaras: JAN 1, 1970
	Date date_with_typo(1, 13, 2022); // nincs 13. honap
	date_with_typo.print();
}