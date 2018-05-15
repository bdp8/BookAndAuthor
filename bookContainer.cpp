#include "bookContainer.h"

BookContainer::BookContainer()
{
	this->capacity = 4;
	this->size = 0;
	this->books = new Book[capacity];
}

BookContainer::BookContainer(int initialCapacity)
{
	this->setCapacity(initialCapacity);
	this->size = 0;
	this->books = new Book[capacity];
}

BookContainer::BookContainer(const BookContainer& s)
{
	copy(s);
}

BookContainer& BookContainer::operator=(const BookContainer& s)
{
	if (this != &s)
	{
		destroy();
		copy(s);
	}
	return *this;
}

BookContainer::~BookContainer()
{
	destroy();
}

void BookContainer::setCapacity(int n)
{
	this->capacity = n;
}

void BookContainer::insert(const Book& book)
{
	if (this->size + 1 >= this->capacity)
	{
		resizeUp();
	}

	this->books[size] = book;
	this->size++;
}

bool BookContainer::isEmpty() const
{
	return this->size == 0;
}

void BookContainer::print()
{
	for (int i = this->size - 1; i >= 0; i--)
	{
		std::cout << this->books[i];
	}
	std::cout << std::endl;
}

Book& BookContainer::operator[](unsigned int idx)
{
	return this->books[idx];
}

void BookContainer::destroy()
{
	delete[] this->books;
}

void BookContainer::copy(const BookContainer& s)
{
	this->capacity = s.capacity;
	this->size = s.size;
	this->books = new Book[s.capacity];
	for (int i = 0; i < s.size; i++)
	{
		this->books[i] = s.books[i];
	}
}

void BookContainer::resizeUp()
{
	Book* tmp = this->books;
	this->capacity *= 2;
	this->books = new Book[this->capacity];

	for (int i = 0; i < this->size; i++)
	{
		this->books[i] = tmp[i];
	}

	delete[] tmp;
}