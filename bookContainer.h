#ifndef BOOKCONTAINER_H_
#define BOOKCONTAINER_H_
#include "book.h"

class BookContainer
{
private:
	Book * books;
	int capacity;
	int size;
public:
	BookContainer();
	BookContainer(int initialCapacity);
	BookContainer(const BookContainer& s);
	BookContainer& operator=(const BookContainer& s);
	~BookContainer();


	int getCapacity() const { return this->capacity; }
	int getSize() const { return this->capacity; }

	void setCapacity(int);

	void insert(const Book& book);
	bool isEmpty() const;
	void print();
	
	Book& operator[](unsigned int idx);
private:
	void destroy();
	void copy(const BookContainer& s);
	void resizeUp();
};
#endif BOOKCONTAINER_H_
#pragma once
