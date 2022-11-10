#include<iostream>

using namespace std;

class Detail
{
	friend class Control;
	friend void OutData(Detail* det);

private:

	int id;
	string name;
	int mass;

public:

	Detail(int indx, string detname, int detmass)
	{
		this->id = indx;
		this->name = detname;
		this->mass = detmass;
	}

	~Detail()
	{
		cout << "detail was destructed" << endl;
	}

};

static void OutData(Detail*det)
{
	cout<<"detail number: " << det->id <<endl << "Name of detail: " <<det->name <<endl << "Mass of detail: " <<det->mass<< endl;
}

class Control
{
public:
	static void SetMassOfDet(Detail*det,int detmass)
	{
		if (detmass > 0)
		{
			det->mass = detmass;
		}
	};
};

int main()
{

	Detail* masofdet[3];

	string tname;
	int indx, tmass;

	for (int i = 0;i < 3;i++)
	{
		cout << "enter " <<i + 1<< " ID" << endl;
		cin >> indx;
		cout << "enter " <<i + 1<< " name" << endl;
		cin >> tname;
		cout << "enter " << i + 1 << " mass" << endl;
		cin >> tmass;
		masofdet[i] = new Detail(indx,tname,tmass);
	}

	system("cls");

	for (int i = 0;i < 3;i++)
	{
		OutData(masofdet[i]);
	}

	for (int i = 0;i < 3;i++)
	{
		cout << "Enter new "<<i + 1<< " mass" << endl;
		cin >> tmass;
		Control::SetMassOfDet(masofdet[i], tmass);
	}

	for (int i = 0;i < 3;i++)
	{
		OutData(masofdet[i]);
	}
	
	for (int i = 0;i < 3;i++)
	{
		delete masofdet[i];
	}
	return 0;
};