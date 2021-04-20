#include <iostream>
#include <windows.h>
using namespace std;

class base
{
public:
	int correctInput()
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		int i;
		while (true) {

			cin >> i;
			if (cin.good())
			{
				break;
			}
			cin.clear();
			cout << "Error\n";
			cin.ignore(10, '\n');
		}
		return i;
	}

	char correctInput(char correctChar1, char correctChar2)
	{
		char chr;
		bool flag = true;
		while (flag)
		{
			cin >> chr;
			if (chr == correctChar1 || chr == correctChar2)
			{
				flag = false;
				return chr;
			}
			else
			{
				cin.clear();
				cout << "Error\n";
				cin.ignore();
			}
		}
	}
};

class Property:public base
{
private:
	string name;
	int cost;
public:
	string getName()
	{
		return name;
	}
	int getCost()
	{
		return cost;
	}
	void setName(string name)
	{
		this->name = name;
	}
	void setCost(int cost)
	{
		this->cost = cost;
	}
};

int main()
{
	base base;
	setlocale(LC_ALL, "rus");
	int conteiner;
	cout << "1 - Queue\n2 - Stack\n3 - Priority\n4 - _queue"<<endl;
	conteiner = base.correctInput();
	conteiner--;
	string name[4] = { "queue","stack","priority","_queue" };
	system("cls");
	int index;
	bool exit = true;
	while (exit)
	{
		
		cout << "1 - Добовление информации в "<<name[conteiner]<<"\n2 - Вывод информации из "<<name[conteiner]<<
			"\n3 - Редактирование информации в "<<name[conteiner]<<"\n0 - Выход"<<endl;
		index = base.correctInput();
		switch (index)
		{
		case 1://Добовление
			system("cls");
			break;
		case 2://Вывод
			system("cls");
			break;
		case 3://Редактирование
			system("cls");
			break;
		case 0://Выход
			exit = false;
			break;
		default://Error
			system("cls");
			cout << "Error\n";
			break;
		}
	}
}
