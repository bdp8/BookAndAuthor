#include "book.h"


Book::Book(const char* t, int p, int y, const Author& a, Genre g, double pr) : title(nullptr)
{
	this->setTitle(t);
	this->setPages(p);
	this->setYear(y);
	this->setAuthor(a);
	this->setGenre(g);
	this->setPrice(pr);
}
Book::Book(const Book& other)
{
	this->setTitle(other.getTitle());
	this->setPages(other.getPages());
	this->setYear(other.getYear());
	this->setAuthor(other.getCreator());
	this->setGenre(other.getGenre());
	this->setPrice(other.getPrice());
}

Book& Book::operator=(const Book& other)
{
	if (this != &other)
	{
		this->setTitle(other.getTitle());
		this->setPages(other.getPages());
		this->setYear(other.getYear());
		this->setAuthor(other.getCreator());
		this->setGenre(other.getGenre());
		this->setPrice(other.getPrice());
	}
	return *this;
}

Book::~Book()
{
	delete[] this->title;
}


void Book::setTitle(const char* n)
{
	if (!n) n = "";
	
	size_t num = strlen(n) + 1;
	delete[] this->title;
	this->title = new char[num];
	strcpy_s(this->title, num, n);
}

void Book::setPages(int p)
{
	this->pages = p;
}

void Book::setYear(int y)
{
	this->year = y;
}

void Book::setAuthor(const Author& other)
{
	this->creator = other;
}
void Book::setGenre(Genre g)
{
	this->g = g;
}
void Book::setPrice(double p)
{
	this->price = p;
}

void Book::print() const
{
	std::cout << "Title: " << this->getTitle() << std::endl;
	std::cout << "NumberOfPages: " << this->getPages() << std::endl;
	std::cout << "Genre: " << this->getGenre() << std::endl;
	std::cout << "Author: " << this->getCreator().getName() << std::endl;
	std::cout << "Year: " << this->getYear() << std::endl;
	std::cout << "Price: " << this->getPrice() << std::endl;
}

bool Book::operator<(const Book& p) const
{
	return this->price < p.price;
}

bool Book::operator>(const Book& p) const
{
	return !(*this < p);
}

bool Book::operator<=(const Book& p) const
{
	return this->price <= p.price;
}

bool Book::operator>=(const Book& p) const
{
	return !(*this <= p);
}

bool Book::operator==(const Book& p) const
{
	return this->price == p.price &&
		   this->creator == p.creator &&
		   this->pages == p.pages &&
		   strcmp(this->title, p.title) == 0 &&
		   this->year == p.year &&
		   this->g == p.g;
}

bool Book::operator!=(const Book& p) const
{
	return !(*this == p);
}

Book::operator bool() const{	return this->price > 0 &&
		   this->creator &&
		   this->pages > 0 &&
		   this->title != nullptr;}
bool Book::operator!() const
{
	return !(this->price > 0 &&
		   this->creator &&
		   this->pages > 0 &&
		   this->title != nullptr);
}

std::ostream& operator<<(std::ostream& os, const Book& p)
{
	os << "Title: " << p.getTitle() << std::endl;
	os << "NumberOfPages: " << p.getPages() << std::endl;
	os << "Genre: " << p.getGenre() << std::endl;
	os << "Author: " << p.getCreator().getName() << std::endl;
	os << "Year: " << p.getYear() << std::endl;
	os << "Price: " << p.getPrice() << std::endl;

	return os;
}

std::istream& operator>>(std::istream& i, Book& p) {
	const int MAX = 1000;
	char t[MAX];
	double pr;
	int y;
	int page;
	Genre gen;
	Author a;
	int indicator;

	std::cout << "Title: ";
	i.ignore();
	i.getline(t, MAX);
	p.setTitle(t);

	std::cout << "NumberOfPages: ";
	i >> page;
	p.setPages(page);

	std::cout << "Year: ";
	i >> y;
	p.setYear(y);

	std::cout << "Author: ";
	i >> a;
	p.setAuthor(a);

	std::cout << "Genre: press 1(Poetry), 2(Drama), 3(Prose) : ";
	i >> indicator;
	if (indicator == 1)
		gen = Poetry;
	else if (indicator == 2)
		gen = Drama;
	else gen = Prose;

	p.setGenre(gen);

	std::cout << "Price: ";
	i >> pr;
	p.setPrice(pr);
	return i;
}