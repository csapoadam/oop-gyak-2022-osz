#pragma once
#include <string>
#include <vector>

class BlogEntry {
protected:
	std::string title;
	int year;
	int month;
	int day;
public:
	BlogEntry(const std::string& title, int yr, int mo, int dy) :
		title(title), year(yr), month(mo), day(dy) {}
	virtual void print() = 0;
	virtual ~BlogEntry() {}
};

class Blog {
	std::string title;
	std::vector<BlogEntry*> entries;
public:
	Blog(const std::string& t) : title(t) {}
	void addEntry(BlogEntry* ent) { entries.push_back(ent); }
	void print() {
		std::cout << "Blog: " << title << std::endl;
		std::cout << "---" << std::endl;
		for (BlogEntry* bep : entries) {
			bep->print();
		}
	}
};

class BlogTextEntry : public BlogEntry {
public:
	BlogTextEntry(const std::string& title, int yr, int mo, int dy) :
		BlogEntry(title, yr, mo, dy) {}
	void print() override {
		std::cout << year << "/" << month << "/" << day;
		std::cout << " - " << title << std::endl;
	}
};

class BlogVideoEntry : public BlogEntry {
public:
	BlogVideoEntry(const std::string& title, int yr, int mo, int dy) :
		BlogEntry(title, yr, mo, dy) {}
	void print() override {
		std::cout << year << "/" << month << "/" << day;
		std::cout << " - " << title;
		std::cout << " - Play - Download" << std::endl;
	}
};