#include <iostream>
using namespace std;

class complex
{
public:
	complex(float a, float b)
	{

		this->Rez = a;
		this->Imz = b;

	}

	~complex()
	{
		cout << "destructed" << endl;
	}

	complex operator =(complex& a)
	{
		this->Rez = a.Rez;
		this->Imz = a.Imz;
		return *this;
	}

	complex operator()(complex& a)
	{
		this->Rez = a.Rez;
		this->Imz = a.Imz;
		return *this;
	}

	friend const complex operator +(complex& a, complex& b)
	{
		return complex(a.Rez + b.Rez, a.Imz + b.Imz);
	}

	friend const complex operator -(complex& a, complex& b)
	{
		return complex(a.Rez - b.Rez, a.Imz - b.Imz);
	}

	friend bool operator ==(complex& a, complex& b)
	{
		return a.Rez == b.Rez && a.Imz==b.Imz; 
	}

	friend bool operator !=(complex& a, complex& b)
	{
		return a.Rez != b.Rez && a.Imz!=b.Imz;
	}

	complex operator ++()
	{
		Rez += 1;
		Imz += 1;
		return *this;
	}

	complex operator --()
	{
		Rez -= 1;
		Imz -= 1;
		return *this;
	}

	friend ostream& operator <<(ostream& os, const complex& a)
	{
		return os << a.Rez << "+" << a.Imz << "i" << endl;
	}

	friend const bool operator<(const complex& a, const complex& b)
	{
		return a.Rez < b.Rez && a.Imz<b.Imz;
	}

	friend const bool operator>(const complex& a, const complex& b)
	{
		return a.Rez > b.Rez && a.Imz>b.Imz;
	}

	friend const complex operator +=(complex& a, complex& b)
	{
		a.Rez += b.Rez;
		a.Imz += b.Imz;
		return a;
	}

	friend const complex operator -=(complex& a, complex& b)
	{
		a.Rez -= b.Rez;
		a.Imz -= b.Imz;
		return a;
	}

	void Show()
	{
		cout << Rez << "+" << Imz << "i"<<endl;
	}

private:

	float Rez;
	float Imz;
};

int main()
{
	complex Complex(4, 6);
	complex Complex1(7, 8);
	complex Complex2(1.2, 5.3);
	complex Complex4(Complex);

	Complex4.Show();
	cout << "----------------------------" << endl;

	complex c = Complex + Complex2;

	c.Show();
	cout << "----------------------------" << endl;

	complex c1 = Complex1 - Complex;

	c1.Show();
	cout << "----------------------------" << endl;
	if (Complex == Complex1)
	{
		cout << "Equal" << endl;
	}	
	else
		cout << "notEqual"<<endl;

	++Complex;
	Complex.Show();

	cout << "----------------------------" << endl;

	--Complex1;
	Complex1.Show();

	cout << "----------------------------" << endl;

	cout << Complex2;

	cout << "----------------------------" << endl;

	Complex += Complex1;
	Complex.Show();

	cout << "----------------------------" << endl;

	Complex -= Complex1;
	Complex.Show();

	cout << "----------------------------" << endl;

	if (Complex < Complex2)
	{
		cout << "The first num less than second" << endl;
		cout << "----------------------------" << endl;
	}
	if (Complex > Complex2)
		cout << "The first num bigger than second" << endl;
	return 0;
}