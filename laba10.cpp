#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Town
{
private:
	unsigned int m_id;
	string m_name;

public:
	Town(int id, string name)
	{
		m_id = id;
		m_name = name;
	}


	string Name()
	{
		return m_name;
	}

	~Town()
	{
		cout << "Город " << m_name << " удален!" << endl;
	}

};

class Country
{
private:
	unsigned int m_id;
	string m_name;
	vector<Town*> m_towns;

public:
	Country(int id, string name)
	{
		m_id = id;
		m_name = name;
	}

	void AddTown(Town*& town)
	{
		m_towns.push_back(town);
	}

	void PrintTown()
	{
		cout << "Страна: " << m_name << endl << "\nГорода: " << endl;
		for (size_t i = 0; i < m_towns.size(); i++)
			cout << m_towns[i]->Name() << endl;
		cout << "----------\n";
	}

	~Country() {
		for (size_t i = 0; i < m_towns.size(); i++)
		{
			delete m_towns[i];
		}
		m_towns.clear();
		cout << "Country " << m_name << " deleted\n";
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Country* country0 = new Country(0, "Россия");
	Country* country1 = new Country(1, "США");
	Country* country2 = new Country(2, "Украина");


	Town* town1 = new Town(0, "Москва");
	Town* town2 = new Town(0, "Волгоград");
	Town* town3 = new Town(0, "Воронеж");
	Town* town4 = new Town(0, "Калининград");

	Town* town5 = new Town(1, "Вашингтон");
	Town* town6 = new Town(1, "Техас");
	Town* town7 = new Town(1, "Лос-Анджелес");

	Town* town8 = new Town(2, "Одесса");
	Town* town9 = new Town(2, "Киев");

	country0->AddTown(town1);
	country0->AddTown(town2);
	country0->AddTown(town3);
	country0->AddTown(town4);

	country1->AddTown(town5);
	country1->AddTown(town6);
	country1->AddTown(town7);

	country2->AddTown(town8);
	country2->AddTown(town9);

	country0->PrintTown();
	country1->PrintTown();
	country2->PrintTown();
	delete country0;
	
	delete country1;

	//Использую связь "Композиция": при удалении страны удаляются и города
}
