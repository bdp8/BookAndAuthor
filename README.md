# BookAndAuthor
Task 1:
For classes Author and Book:
a) write the following functions:
  bool operator<(const T& p) const;
  bool operator>(const T& p) const;
  bool operator<=(const T& p) const;
  bool operator>=(const T& p) const;
  bool operator!=(const T& p) const;
  bool operator==(const T& p) const;
  friend istream& operator>>(istream& is, T& p);
  friend ostream& operator<<(ostream& os, const T& p);
  operator bool() const;
  bool operator!() const;

Task 2:
Make class BookContainer with the following data:
  array of books (Book*)
  capacity of the array (int capacity)
  number of books in the array (int size)

Implement get functions for capacity and size. The memory for the array is dynamic so you have to implement the big four.

Implement void insert(const Book& book) for BookContainer, which adds a new book at the end of the array.
Implement a private function void resizeUp(), which makes the capacity of the array twice bigger.
Implement bool isEmpty() const, which returns true if the container is empty and false if it is not.
Predefinate the following operator:
  Book& operator[](unsigned int idx)
