// main.cpp

class Date {
	int _day, _month, _year;
	Date(int day, int month, int year) {
		_day = day;
		_month = month;
		_year = year;
	}
	void print() {}
};

int main() {
	Date jan1_1970(1, 1, 1970);
	jan1_1970.print();
}