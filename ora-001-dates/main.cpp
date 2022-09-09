// main.cpp
#include <string>
#include <iostream>

class Date {
	int _day, _month, _year;
	static std::string monthNames[13];
	static bool _is_day_admissible(int day, int month, int year) {
		if (_is_month_admissible(month)) {
			// 30-napos honapok
			if (month == 4 || month == 6 || month == 9 || month == 11) {
				//if (day > 0 && day < 31) return true;
				return (day > 0 && day < 31);
			}
			else if (month == 2) {
				int finalDay = year % 4 == 0 ? 29 : 28;
				return (day > 0 && day < finalDay + 1);
			}
			// ellenkezo esetben 31-napos a honap
			return (day > 0 && day < 32);
		}
		return false;
	}
	static bool _is_month_admissible(int month) {
		return (month < 13 && month > 0);
	}
public:
	Date(int day, int month, int year) {
		_month = _is_month_admissible(month) ? month : 0;
		_day = _is_day_admissible(day, month, year) ? day : 0;
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