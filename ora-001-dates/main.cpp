// main.cpp
#include <string>
#include <iostream>

class Date {
	int _day, _month, _year;
	static std::string monthNames[12];
public:
	Date(int day, int month, int year) {
		_day = day;
		_month = month;
		_year = year;
	}
	void print() {
		std::cout <<
			monthNames[_month-1] << " " <<
			_day << ", " <<
			_year << std::endl;
	}
};

std::string Date::monthNames[] = {
		"JAN", "FEB", "MAR", "APR",
		"MAY", "JUN", "JUL", "AUG",
		"SEP", "OCT", "NOV", "DEC"
};

int main() {
	Date jan1_1970(1, 1, 1970);
	jan1_1970.print(); // Elvaras: JAN 1, 1970
}