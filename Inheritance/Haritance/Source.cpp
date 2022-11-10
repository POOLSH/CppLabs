#include<iostream>
#include<string>
using namespace std;

class Book
{
public:
	Book(string name,int cost,string author)
	{
		this->name = name;
		if (cost >= 0)
			this->cost = cost;
		else
			this->cost = cost * -1;
		this->author = author;
	};
	~Book()
	{
		cout << "We destroyed this Book" << endl;
	};
	friend ostream& operator <<(ostream& os, Book& book)
	{
		return os << "Name of Book: " << book.name << endl << "Cost of Book: " << book.cost<< " $" << endl << "The author: " << book.author << endl;
	}
protected:
	string name;
	int cost;
	string author;
};
class Shelf:Book
{
public:
	Shelf(string name,int cost,string author,string genre):Book(name,  cost, author)
	{
		this->genre = genre;
	};
	~Shelf()
	{
		cout << "We destroyed this Shelf" << endl;
	};
	friend ostream& operator <<(ostream& os, Shelf& shelf)
	{
		Book b = Book(shelf);
		return os << b <<"The genre: "<<shelf.genre << endl;
	}
protected:
	string genre;
};
class Bookcase:Shelf
{
public:
	Bookcase(string name, int cost, string author,string genre,string firstLetter):Shelf(name,cost,author,genre)
	{
		this->firstLetter = firstLetter;
	};
	~Bookcase()
	{
		cout << "We destroyed this Bookcase" << endl;
	};
	friend ostream& operator <<(ostream& os, Bookcase& bookcase)
	{
		Shelf shelf = Shelf(bookcase);
		return os << shelf << "The first Letter: "<<bookcase.firstLetter << endl;
	}
protected:
	string firstLetter;
};

class Reader :Book
{
public:
	Reader(string name, int cost, string author, string readername) :Book(name, cost, author)
	{
		this->readername = readername;
	};
	~Reader()
	{
		cout << "We destroyed this Reader" << endl;
	};
	friend ostream& operator <<(ostream& os, Reader& reader)
	{
		Book b = Reader(reader);
		return os << b << "The Reader name: " << reader.readername<< endl;
	}
protected:
	string readername;
};

class ReturnDate: Reader
{
public:
	ReturnDate(string name, int cost, string author, string readername,string date) :Reader(name, cost, author,readername)
	{
		this->date = date;
	};
	
	~ReturnDate()
	{
		cout << "We destroyed this ReturnDate" << endl;
	};

	string getReader()
	{
		return this->readername;
	}

	friend ostream& operator <<(ostream& os, ReturnDate& date)
	{
		Reader reader = Reader(date);
		return os << reader << "The return date: " << date.date << endl;
	}
protected:
	string date;
};

class Librarian:ReturnDate,Bookcase
{
public:
	Librarian(string name, int cost, string author,string genre,
		string firstLetter, string readername,string date,int penalty)
		:Bookcase(name, cost, author, genre, firstLetter),ReturnDate(name, cost, author,readername,date)
	{
		if(penalty>=0)
			this->penalty = penalty;
		else
			this->penalty = penalty*-1;
	};
	~Librarian()
	{
		cout << "We destroyed this Librarian" << endl;
	};
	friend ostream& operator <<(ostream& os, Librarian& Lib)
	{
		Bookcase bookcase = Bookcase(Lib);
		return os  << bookcase <<"The Return date: " << Lib.date << endl << "The Reader name: " << Lib.getReader() << endl << "The penalty: " << Lib.penalty << " $" << endl;
	}
protected:
	int penalty;
};

int main()
{
	Librarian Kirill("The Subtle Art of indifference",100,"Mark Manson","Psycology","T","Roman","10.09.2022",50);
	cout << Kirill;
}