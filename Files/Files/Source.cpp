#include <iostream>
#include <fstream>
#include<vector>
using namespace std;

class Organization
{
public:
	Organization(string name,int count,string owner)
	{
		this->Name = name;
		this->AmountOfMembers = count;
		this->OwnerName = owner;
	}
	~Organization()
	{

	}

	string getNameofOrg() { return Name; }
	void setNameofOrg(string name) { this->Name = name; }
	
	int getAmount() { return AmountOfMembers; }
	void setBuildings(int count) { this->AmountOfMembers = count; }
	
	string getOwnerName() { return OwnerName; }
	void setPostcode(string owner) { this->OwnerName = owner; }

	void Show()
	{
		cout << "The Name of organization: " << Name << endl
			<< "The amount of members: " << AmountOfMembers << endl 
			<< "The Name of Owner: " << OwnerName << endl;
	}

	friend ostream& operator<<(ostream& os, Organization& Org)//перегрузка оператора вывода
	{
		os << Org.Name << " " << Org.AmountOfMembers << " " <<Org.OwnerName;
		return os;
	}
		
	friend istream& operator>>(istream& is, Organization& Org)//перегрузка оператора ввода
	{
		is >> Org.Name >> Org.AmountOfMembers >> Org.OwnerName;
		return is;
	}
	void saveInFileT(fstream& file, string location) 
	{
		file.open(location, ios_base::out | ios_base::app);//если файла не существует, он будет создан
		try
		{
		//запись полей в файл с помощью перегруженного оператора <<
		file << "The Name of organization: " << this->Name << endl
		    << "Amount of members: " << this->AmountOfMembers << endl
		    << "The Owner name: " << this->OwnerName << endl;
		file.close();
		}
		catch (const exception& ex)
		{
		std::cout << ex.what();
		}
		
		
	}

	void saveInFileB(fstream& file, string location) {
		file.open(location, ios_base::binary | ios_base::out | ios_base::app);//если файла не существует, он будет создан
		
		try
		{
		    //приведение полей к char* и запись их по размеру, согласному sizeof
		    file.write(this->Name.c_str(), sizeof(this->Name));
		    file.write((char*)&this->AmountOfMembers, sizeof(int));
		    file.write(this->OwnerName.c_str(), sizeof(this->OwnerName));
		
		    file.close();
		}
		catch (const exception& ex)
		{
		    cout << ex.what() << endl;
		}
		
	}
	void readFromFileT(fstream& file, string location, int order = 0) {
		file.open(location, ios_base::in);
		Organization tmp(this->Name, this->AmountOfMembers, this->OwnerName);
		if (order > 0)
		    for (size_t i = 0; i < (order - 1) * 3; i++)
		    {
		        //простой способ перехода на новую строку
		        file.ignore(100, '\n');
		    }
		
		try
		{
		    file.seekp(26, ios::cur);//пропуск Name:
		    file >> this->Name;
		    file.seekp(20, ios::cur);//пропуск Buildings:
		    file >> this->AmountOfMembers;
		    file.seekp(17, ios::cur);//пропуск Postcode:
		    file >> this->OwnerName;
		    file.close();
		}
		catch (const exception& ex)
		{
		    cout << ex.what();
		}
		
	}

	void readFromFileB(fstream& file, string location, int order = 0) {
		file.open(location, ios_base::binary | ios_base::in);//файл будет создан, если не сущ
		if (order > 0)
			for (size_t i = 0; i < order - 1; i++)
			{
				//пропуск одного объекта класса Town
				file.seekp(sizeof(Organization), ios::cur);
			}

		try
		{
			//приведение значений полей к char* и запись согласно sizeof этого поля
			file.read((char*)this->Name.c_str(), sizeof(this->Name));
			file.read((char*)&this->AmountOfMembers, sizeof(int));
			file.read((char*)this->OwnerName.c_str(), sizeof(this->OwnerName));
		}
		catch (const exception& ex)
		{
			cout << ex.what();
		}
	}
private:
	string Name;
	int AmountOfMembers;
	string OwnerName;
};
int main()
{
	vector<Organization> Org =//использование вектора элементов класса Town вместо массива
	{
		Organization("GGbet", 1000,"Vasya"),
		Organization("Freebet", 432, "Gena"),
		Organization("LightSaber", 20, "Gregory"),
		Organization("MY", 1, "Me"),
		Organization("Genius", 116,"Einstein")
	};

	//рабочий поток и положения файлов

	const string location = "C:\\Users\\POOLSHOT\\Desktop\\Files\\files.txt";
	const string locationB = "C:\\Users\\POOLSHOT\\Desktop\\Files\\binar.bin";
	fstream file(location);
	fstream fileB(locationB);

	for (int i = 0; i < 5; i++)//сохранение в файл вектора
	{
		Org[i].saveInFileT(file, location);
	}

	Org[0].readFromFileT(file, location, 2);//заменяем первый элемент вектора вторым

	cout << Org[0] << endl << endl;//вывод первого элемента

	for (int i = 0; i < 5; i++)//вывод всех координат вектора
	{
		cout << Org[i] << endl;
	}
	cout << endl;

	for (int i = 0; i < 5; i++)//сохранение вектора в бинарный файл
	{
		Org[i].saveInFileB(fileB, locationB);
	}

	Org[3].readFromFileB(fileB, locationB, 5);//заменяем четвертый элемент вектора пятым

	cout << Org[3] << endl << endl;//вывод четвертого элемента

	for (int i = 0; i < 5; i++)//вывод всех координат вектора
	{
		cout << Org[i] << endl;
	}
	cout << endl;
	
	return 0;
}