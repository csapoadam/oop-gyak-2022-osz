#pragma once
#include <string> // ezt muszaj itt mert van benne hivatkozas std::string-re

class Date {
	int _day, _month, _year;
	static std::string monthNames[13];
	static bool _is_day_admissible(int day, int month, int year);
	static bool _is_month_admissible(int month);
public:
	Date(int day, int month, int year);
	void print();
};