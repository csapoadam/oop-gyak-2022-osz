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