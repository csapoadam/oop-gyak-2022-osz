// main.cpp
#include <string>
#include <iostream>

class Date {
	int _day, _month, _year;
public:
	Date(int day, int month, int year) {
		_day = day;
		_month = month;
		_year = year;
	}
	void print() {
		std::string monthNames[] = {
			"JAN", "FEB", "MAR", "APR",
			"MAY", "JUN", "JUL", "AUG",
			"SEP", "OCT", "NOV", "DEC"
		};
		// pelda:
		std::cout << monthNames[_month-1] << std::endl;
	}
};

int main() {
	Date jan1_1970(1, 1, 1970);
	jan1_1970.print(); // Elvaras: JAN 1, 1970
}