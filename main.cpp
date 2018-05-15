#include "bookContainer.h"


void sortBooks(Book* books, int br, bool(*f)(double, double))
{
	for (int i = 0; i < br - 1; i++)
	{
		for (int j = 1 + i; j < br; j++)
		{
			if (f(books[j].getPrice(), books[i].getPrice()))
			{
				double temp = books[j].getPrice();
				books[j].setPrice(books[i].getPrice());
				books[i].setPrice(temp);
			}
		}
	}
}

bool func(double a, double b)
{
	return a < b;
}

Book* booksByAuthor(Book* books, int br, const char* author, int& newbr)
{
	newbr = 0;
	Book *arr = new Book[br];
	for (int i = 0; i < br; i++)
	{
		if (strcmp(books[i].getCreator().getName(), author) == 0)
		{
			arr[newbr] = books[i];
			newbr++;
		}
	}

	if (newbr == br)
		return arr;

	Book *finally = new Book[newbr];
	for (int i = 0; i < newbr; i++)
		finally[i] = arr[i];

	delete[] arr;

	return finally;
}


int main()
{
	
	Book* books = new Book[5];
	Author jkr("J. K. Rowling", 204, "British");
	books[0] = Book("The Philosopher's Stone", 400, 1997, jkr, Prose, 15);
	books[1] = Book("The Chamber of Secrets ", 400, 1998, jkr, Prose, 17);
	books[2] = Book("The Prisoner of Azkaban", 400, 1999, jkr, Prose, 15);
	books[3] = Book("The Goblet of Fire", 400, 2000, jkr, Prose, 15);
	books[4] = Book("The Order of the Phoenix", 400, 2003, jkr, Prose, 20);

	BookContainer harry(5);
	harry.insert(books[0]);
	harry.insert(books[1]);
	harry.insert(books[2]);
	harry.insert(books[3]);
	harry.insert(books[4]);

	harry.print();

	delete[] books;

	system("pause");
	return 0;
}