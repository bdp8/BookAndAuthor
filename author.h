#ifndef AUTHOR_H_
#define AUTHOR_H_

#include <iostream>

class Author
{
private:
	char* name;
	int br;
	char* nat;

public:
	friend std::istream& operator>>(std::istream& i, Author& p);
	friend std::ostream& operator<<(std::ostream& os, const Author& p);
	Author(const char* n = "No name", int br = 0, const char* from = "Unknown");
	Author(const Author& other);
	Author& operator=(const Author& other);
	~Author();

	const char* getName() const { return this->name; }
	int			getBr() const { return this->br; }
	const char* getNat() const { return this->nat; }

	void setName(const char*);
	void setBr(int);
	void setNat(const char*);

	void print();

	bool operator<(const Author& p) const;
	bool operator>(const Author& p) const;
	bool operator<=(const Author& p) const;
	bool operator>=(const Author& p) const;
	bool operator!=(const Author& p) const;
	bool operator==(const Author& p) const;

	operator bool() const;	bool operator!() const;
};
#endif // !AUTHOR_H_
