#ifndef BOOK_H_
#define BOOK_H_
#include "author.h"

enum Genre {
	Poetry,
	Drama,
	Prose
};

class Book
{
private:
	char* title;
	int pages;
	int year;
	Author creator;
	Genre  g;
	double price;

public:
	friend std::istream& operator>>(std::istream& i, Book& p);
	friend std::ostream& operator<<(std::ostream& os, const Book& p);
	Book(const char* t = "Unknown", int p = 0, int y = 0000, const Author& a = Author(), Genre g = Prose, double pr = 0);
	Book(const Book& other);
	Book& operator=(const Book& other);
	~Book();

	const char* getTitle() const { return this->title; }
	int getPages() const { return this->pages; }
	int getYear() const { return this->year; }
	const Author& getCreator() const { return this->creator; }
	Genre getGenre() const { return this->g; }
	double getPrice() const { return this->price; }

	void setTitle(const char*);
	void setPages(int);
	void setYear(int);
	void setAuthor(const Author&);
	void setGenre(Genre);
	void setPrice(double);

	void print() const;

	bool operator<(const Book& p) const;
	bool operator>(const Book& p) const;
	bool operator<=(const Book& p) const;
	bool operator>=(const Book& p) const;
	bool operator!=(const Book& p) const;
	bool operator==(const Book& p) const;

	operator bool() const;	bool operator!() const;
};
std::istream& operator>>(std::istream& is, Book& other);

#endif // !BOOK_H_

#pragma once
