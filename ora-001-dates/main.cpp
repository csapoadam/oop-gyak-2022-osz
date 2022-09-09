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
	date_with_typo.print(); // Vegul: BADMONTH 1, 2022
	Date feb_29_2023(29, 2, 2023); // 2024 a szokoev! (4-el valo maradekos osztas 0-e?)
	Date feb_29_2024(29, 2, 2024); // ez OK!
	Date mar_31_2022(31, 3, 2022); // ez is OK!
	Date apr_31_2022(31, 4, 2022); // ajjaj, APR csak 30 napos!
	feb_29_2023.print();
	feb_29_2024.print();
	mar_31_2022.print();
	apr_31_2022.print();
}