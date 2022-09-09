#include <iostream> // iostream-et eleg itt include-olni a headerben nem kell!
#include "date.h"

Date::Date(int day, int month, int year) {
	_month = _is_month_admissible(month) ? month : 0;
	_day = _is_day_admissible(day, month, year) ? day : 0;
	_year = year;
}

void Date::print() {
	std::cout <<
		monthNames[_month] << " " <<
		_day << ", " <<
		_year << std::endl;
}

std::string Date::monthNames[] = {
		"BADMONTH",
		"JAN", "FEB", "MAR", "APR",
		"MAY", "JUN", "JUL", "AUG",
		"SEP", "OCT", "NOV", "DEC"
};

int Date::_number_of_days_in_month(int month, int year) {
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}
	if (month == 1 || month == 3 || month == 5 || month == 7
		|| month == 8 || month == 10 || month == 12) {
		return 31;
	}
	if (month == 2) {
		return year % 4 == 0 ? 29 : 28;
	}
	return 0;
}

bool Date::_is_day_admissible(int day, int month, int year) {
	// akkor is false, ha month nem admissible, mert _number_of...() 0-at ad vissza
	return (day > 0 && day < 1 + _number_of_days_in_month(month, year));
}

bool Date::_is_month_admissible(int month) {
	return (month < 13 && month > 0);
}