#pragma once
#include <string> // ezt muszaj itt mert van benne hivatkozas std::string-re

class Date {
	int _day, _month, _year;
	static std::string monthNames[13];
	static int _number_of_days_in_month(int month1To12, int year);
	static bool _is_day_admissible(int day, int month, int year);
	static bool _is_month_admissible(int month);
	static int _days_left_in_month(int day, int month, int year);
public:
	Date(int day, int month, int year);
	void add_days(int days);
	void print();
};