#include<iostream>
#include<string>
using namespace std;

class Book
{
public:
	Book(string name, int cost, string author)
	{
		this->name = name;
		if (cost >= 0)
			this->cost = cost;
		else
			this->cost = cost * -1;
		this->author = author;
	};
	virtual ~Book()
	{
		cout << "We destroyed this Book" << endl;
	};

	virtual int overcost()
	{
		return cost;
	}

	virtual void show()
	{
		cout << "Name: " << name << endl << "Cost: " << cost << endl << "The Author: " << author << endl;
	}
	
protected:
	string name;
	int cost;
	string author;
};
class Shelf :Book
{
public:
	Shelf(string name, int cost, string author, string genre) :Book(name, cost, author)
	{
		this->genre = genre;
	};
	virtual ~Shelf()
	{
		cout << "We destroyed this Shelf" << endl;
	};

	int overcost() override
	{
		return cost * 2;
	}

	void show() override
	{
		Book::show();
		cout << "Genre: " << genre << endl;
	}

protected:
	string genre;
};
class Bookcase :Shelf
{
public:
	Bookcase(string name, int cost, string author, string genre, string firstLetter) :Shelf(name, cost, author, genre)
	{
		this->firstLetter = firstLetter;
	};
	~Bookcase()
	{
		cout << "We destroyed this Bookcase" << endl;
	};

	int overcost() override
	{
		return Shelf::overcost() * Shelf::overcost();
	}
	
	void show() override
	{
		Shelf::show();
		cout << "First Letter: " << firstLetter << endl;
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
	virtual ~Reader()
	{
		cout << "We destroyed this Reader" << endl;
	};
	
	int overcost() override
	{
		return cost;
	}
	void show() override
	{
		Book::show();
		cout << "Reader: " << readername << endl;
	}
protected:
	string readername;
};

class ReturnDate : Reader
{
public:
	ReturnDate(string name, int cost, string author, string readername, string date) :Reader(name, cost, author, readername)
	{
		this->date = date;
	};

	~ReturnDate()
	{
		cout << "We destroyed this ReturnDate" << endl;
	};

	int overcost() override
	{
		return Reader::overcost() * 8;
	}

	void show() override
	{
		Reader::show();
		cout << "Return date: " << date << endl;
	}

protected:
	string date;
};


int main()
{
	Book** obj = new Book * [5];
	obj[0] = new Book("Solo Leveling", 100, "Jang Sunnak");
	obj[1] = (Book*) (new Shelf("Solo Leveling", 100, "Jang Sunnak","Fantasy"));
	obj[2] = (Book*)(new Bookcase("Solo Leveling", 100, "Jang Sunnak", "Fantasy","S"));
	obj[3] = (Book*)(new Reader("Solo Leveling", 100, "Jang Sunnak", "Me"));
	obj[4] = (Book*)(new ReturnDate("Solo Leveling", 100, "Jang Sunnak", "Me","01.11.22"));

	for (int i = 0; i < 5; i++)
	{
		obj[i]->show();
		cout <<"Overcost: " << obj[i]->overcost() << " $" << endl << endl;
	}

	return 0;
}




