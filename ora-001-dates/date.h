#pragma once
#include <string> // ezt muszaj itt mert van benne hivatkozas std::string-re

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
	Date(int day, int month, int year);
	void print();
};