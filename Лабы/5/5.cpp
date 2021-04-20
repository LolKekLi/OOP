#include <fstream>
#include <iostream>
#include <windows.h>
#include <map>
#include <list>
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

class Number
{	
public:
	static int numbr;
	Number()
	{
		numbr ++;
	}
	friend bool operator < (const Number& n1, const Number& n2);
};
int Number::numbr;

bool operator < (const Number& n1, const Number& n2)
{
	return n1.numbr < n2.numbr;
}

class Participant :public base
{
public:
	string kindOfSport;
	string name;
	int age;

	void setInfo(string name, string kindOfSport, int age)
	{
		this->name = name;
		this->kindOfSport = kindOfSport;
		this->age = age;
	}



	friend ostream& operator<< (std::ostream& out, const Participant& point);

	friend bool operator<(const Participant& lhs, const Participant& rhs);
};

bool operator<(const Participant& lhs, const Participant& rhs)
{
	return lhs.age < rhs.age;
}

ostream& operator<< (std::ostream& out, const Participant& point)
{
	out << point.name << endl << "Возраст ";
	if (point.age == 20 || point.age == 25)
	{
		out << point.age << " лет\nВид спорта:";
	}
	else
	{
		out << point.age << " года\nВид спорта:";
	}
	out << point.kindOfSport << endl;

	return out;
}

int Random(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

template <typename T>
void Start(T& listPerson)
{
	string name[] = { "Антон","Борис","Вадим","Владислав","Глеб","Денис","Никита","Олег","Павел","Прохор" };
	string kindOfSport[] = { "Сквош","Керлинг","Триатлон","Вейкбординг","Сноубординг","Борьба","Армрестлинг","Бег" };
	
	for (int i = 0; i < 8; i++)
	{
		Participant participant;
		participant.setInfo(name[Random(0, name->size())], kindOfSport[Random(0, kindOfSport->size())], Random(20, 25));
		listPerson.push_back(participant);
	}	
	
}

template <typename T>
void Start_1(T& mapPerson)
{
	string name[] = { "Антон","Борис","Вадим","Владислав","Глеб","Денис","Никита","Олег","Павел","Прохор" };
	string kindOfSport[] = { "Сквош","Керлинг","Триатлон","Вейкбординг","Сноубординг","Борьба","Армрестлинг","Бег" };
	for (int i = 0; i < 8; i++)
	{
		Number numb;
		
		Participant participant;
		participant.setInfo(name[Random(0, name->size())], kindOfSport[Random(0, kindOfSport->size())], Random(20, 25));
		mapPerson.insert(make_pair(numb.numbr, participant));
	}
}

template <typename T>
void PrintList(const list<T>& lst)
{
	int b = 1;
	for (auto i = lst.cbegin(); i != lst.cend(); ++i, b++)
	{
		cout << b << ":" << *i << endl;

	}
}

template <typename T, typename U>
void PrintMap(const map<T,U>& map)
{
	for (auto i = map.begin(); i != map.end(); ++i )
	{
		cout << i->first <<":"<< i->second << endl;
	}
	
}

int main()
{
#pragma region start
	int choose;
	bool islist;
	cout << "1 - List\n2 - Map";
	cin >> choose;
	if(choose == 1)
	{
		islist = true;
	}
	else if (choose == 2)
	{
		islist = false;
	}
	else
	{
		cout << "Errorn\n";
	}
	system("cls");
	
	base base;
	setlocale(LC_ALL, "rus");
	list<Participant> participants;
	map<int, Participant> _map;
	Start(participants);
	Start_1(_map);
	PrintMap(_map);
	//Start_1(_map);
	/*cout << "Дамы и Господа\n";
	Sleep(500);
	cout << "Приветствуем вас на ВЕЛИЧАЙШИХ СОРЕВНОВАНИЯХ В ИСТОРИИ\n";
	Sleep(500);
	cout<<"И так участики соревнований\n"<<endl;
	Sleep(500);
	PrintList(participants);
	system("cls");*/
#pragma endregion
#pragma region функционал
	bool end = true;
	while (end)
	{
		int temp;
		int numb;

		string name;
		string kindOfsport;
		int age;
		Participant addParticipants;

		auto begin = participants.begin();

		ofstream out;
		out.open("res.txt");

		cout << "1 - Добавить участников соревнования\n2 - Удалить участников соревнования\n3 - Изменить информацию об участнике соревнования\n"
			"4 - Найти участинка соревнования\n5 - Отсортировать участиков\n6 - Зпись информации в файл\n7 - Просмотр списка участиников\n0 - Выход" << endl;
		temp = base.correctInput();
		switch (temp)
		{
#pragma region case 1 Добовление 
		case 1:
			system("cls");
			cout << "Введите информцию об участинках\nИмя" << endl;
			cin >> name;
			cout << "Возраст\n";
			age = base.correctInput();
			cout << "Вид спорта\n";
			cin >> kindOfsport;
			addParticipants.setInfo(name, kindOfsport, age);
			cout << "1 - Добавить в начало\n2 -Добавить в конец" << endl;
			cin >> temp;
			if (temp == 1)
			{
				participants.push_back(addParticipants);
			}
			else if (temp == 2)
			{
				participants.push_front(addParticipants);
			}
			else
			{
				cout << "Error\n";
			}
			break;
#pragma endregion
#pragma region case2 Удаление
		case 2:
			system("cls");
			PrintList(participants);
			cout << "Введите номер человека которого хотите удалить" << endl;
			numb = base.correctInput();
			if (numb == 1)
			{
				participants.pop_front();
			}
			else if (numb == participants.size())
			{
				participants.pop_back();
			}
			else
			{
				for (int i = 0; i < numb - 1; i++, begin++);
				participants.erase(begin);
			}

			break;
#pragma endregion
#pragma region case3 Изменение
		case 3:
			system("cls");
			PrintList(participants);
			cout << "Введите номер человека информацию о котром фы хотите изменить";
			numb = base.correctInput();
			begin = participants.begin();
			cout << "Введите информцию о новом участнике\nИмя" << endl;
			cin >> name;
			cout << "Возраст\n";
			age = base.correctInput();
			cout << "Вид спорта\n";
			cin >> kindOfsport;
			addParticipants.setInfo(name, kindOfsport, age);
			for (int i = 0; i <= numb - 2; i++, begin++);
			begin = participants.erase(begin);
			participants.insert(begin, addParticipants);
			break;
#pragma endregion
#pragma region case4 Поиск
		case 4:
			system("cls");
			cout << "Введите имя\n";
			cin >> name;
			begin = participants.begin();
			for (int i = 0; i < participants.size(); i++, begin++)
			{
				if (begin->name == name)
				{
					cout << *begin << endl;
				}
			}
			break;
#pragma endregion
#pragma region case5 Сортировка
		case 5:
			system("cls");
			participants.sort();
			cout << "Список успешно отсортирован)" << endl;
			break;
#pragma endregion	
		case 6:
			begin = participants.begin();
			for (int i = 0; i < participants.size(); i++, begin++)
			{
				out << begin->name << "\n" << begin->age << "\n" << begin->kindOfSport << "\n";
			}
			cout << "Информация об участниках успешна записана\n";
			break;
		case 7:
			system("cls");
			PrintList(participants);
			break;
		case 0:
			end = false;
			break;
		default:
			cout << "Error\n";
			break;
		}
	}
#pragma endregion	
}



