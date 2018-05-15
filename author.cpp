#include "author.h"
#include "cstring"

Author::Author(const char* n, int br, const char* from) : name(nullptr), nat(nullptr)
{
	this->setName(n);
	this->setBr(br);
	this->setNat(from);
}

Author::Author(const Author& other)
{
	this->setName(other.getName());
	this->setBr(other.getBr());
	this->setNat(other.getNat());
}

Author& Author::operator=(const Author& other)
{
	if (this != &other)
	{
		this->setName(other.getName());
		this->setBr(other.getBr());
		this->setNat(other.getNat());
	}
	return *this;
}
Author::~Author()
{
	delete[] this->name;
	delete[] this->nat;
}


void Author::setName(const char* n)
{
	if (!n) n = "";
	size_t num = strlen(n) + 1;
	
	delete[] this->name;

	this->name = new char[num];

	strcpy_s(this->name, num, n);

}
void Author::setBr(int n)
{
	this->br = n;
}
void Author::setNat(const char* n)
{
	if (!n) n = "";

	size_t num = strlen(n) + 1;
	delete[] this->nat;
	this->nat = new char[num];
	strcpy_s(this->nat, num, n);
}

void Author::print()
{
	std::cout << this->getName() << " " << this->getBr() << " " << this->getNat() << std::endl;
}

bool Author::operator<(const Author& p) const
{
	return this->br < p.br;
}

std::istream& operator>>(std::istream& i, Author& p)
{

	int Max = 1000;
	char name[1000];
	char nat[1000];
	int br;

	i.ignore();
	std::cout << "NameOfAuthor: ";
	i.getline(name, Max);
	p.setName(name);

	std::cout << "Number of published books: ";
	i >> br;
	p.setBr(br);
	i.ignore();

	std::cout << "Auther's nationality: ";
	i.getline(nat, Max);
	p.setNat(nat);

	return i;

}

bool Author::operator>(const Author& p) const
{
	return !(*this < p);
}

bool Author::operator<=(const Author& p) const
{
	return this->br <= p.br;
}

bool Author::operator>=(const Author& p) const
{
	return !(*this <= p);
}

bool Author::operator==(const Author& p) const
{
	return strcmp(this->name, p.name) == 0 &&
		   strcmp(this->nat, p.nat) == 0   &&
		   this->br == p.br;
 }

bool Author::operator!=(const Author& p) const
{
	return !(*this == p);
}

Author::operator bool() const{	return this->name != nullptr &&
		   this->nat != nullptr;}bool Author::operator!() const{	return !(this->name != nullptr &&
		     this->nat != nullptr);}

std::ostream& operator<<(std::ostream& os, const Author& p)
{
	os << p.getName() << " " << p.getBr() << " " << p.getNat() << std::endl;
	return os;
}