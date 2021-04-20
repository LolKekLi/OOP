#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <Windows.h>

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
		while (true)
		{
			cin >> chr;
			if (chr == correctChar1 || chr == correctChar2)
			{
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

	int Random(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}

};

class property :public base
{
private:
	string name;
	int cost = 0;
public:
	string getName()
	{
		return name;
	}
	int getCost()
	{
		return cost;
	}
	void setName(const string name)
	{
		this->name = name;
	}
	void setCost(const int cost)
	{
		this->cost = cost;
	}

	friend ostream& operator<< (std::ostream& out, const property& point);

	friend bool operator<(const property& lhs, const property& rhs);
};

ostream& operator<<(std::ostream& out, const property& point)
{
	out << point.name << "\nЦена " << point.cost << "$\n" << endl;
	return out;
}

bool operator<(const property& lhs, const property& rhs)
{
	return lhs.cost < rhs.cost;
}

class function : public property
{
private:
	string name[7] = { "Многоэтажка","ДомВДеревне","Вилла","ЗемленойУчасток","Сарай","Гараж","Квартира" };

	property add()
	{
		property pr;
		string name;
		int cost;
		cout << "Введите название недвижемости" << endl;
		cin >> name;
		cout << "Введите стоимость недвижемости" << endl;
		cost = correctInput();
		pr.setCost(cost);
		pr.setName(name);
		return pr;
	}

	string change(string& newName, int& newCost)
	{
		string oldName;
		cout << "Введите имя недвижемости информацию о котрой нужно изменить" << endl;
		cin >> oldName;
		cout << "Введите имя новой недвижемости" << endl;
		cin >> newName;
		cout << "Введите цену новой недвижемости" << endl;
		newCost = correctInput();
		return oldName;
	}

	property start(int i)
	{
		property pr;
		pr.setCost(Random(5000, 25000));
		pr.setName(name[i]);
		return pr;
	}

public:

	void stStart(stack<property, vector<property>>& stack)
	{
		for (int i = 0; i < 7; i++)
		{
			stack.push(start(i));
		}
	}

	void qStart(queue<property>& queue)
	{
		for (int i = 0; i < 7; i++)
		{
			queue.push(start(i));
		}
	}

	void pqStart(priority_queue<property>& pq_property)
	{
		for (int i = 0; i < 7; i++)
		{
			pq_property.push(start(i));
		}
	}

	void stShow(const stack<property, vector<property>>& stack)
	{
		auto st = stack;
		while (!st.empty())
		{
			cout << st.top();
			st.pop();
		}
	}

	void qShow(const queue<property>& queue)
	{
		auto q = queue;
		while (!q.empty())
		{
			cout << q.front();
			q.pop();
		}

	}

	void pqShow(const priority_queue<property>& pq_property)
	{
		auto q = pq_property;
		while (!q.empty())
		{
			cout << q.top();
			q.pop();
		}
	}

	void stAdd(stack<property, vector<property>>& stack)
	{
		property pr;
		pr = add();
		stack.push(pr);
	}

	void qAdd(queue<property>& queue)
	{
		property pr;
		pr = add();
		queue.push(pr);
	}

	void pqAdd(priority_queue<property>& pq_property)
	{
		property pr;
		pr = add();
		pq_property.push(pr);
	}

	void stChange(stack<property, vector<property>>& stack_0)
	{

		bool flag = true;
		int i = 0;
		string name_;
		int cost;
		vector<property> prVector;
		string name = change(name_, cost);
		while (flag)
		{
			if (!stack_0.empty())
			{
				auto stName = stack_0.top();
				stack_0.pop();
				i++;
				if (stName.getName() == name)
				{
					flag = false;
					break;
				}
				prVector.push_back(stName);
			}
			else
			{
				break;
			}
		}
		if (flag)
		{
			cout << "Такой недвижемости не существует" << endl;
		}
		else
		{
			property pr;
			pr.setName(name_);
			pr.setCost(cost);
			stack_0.push(pr);
			int size = prVector.size()-1;
			int b = 0;
			while (size>=b)
			{
				stack_0.push(prVector[size]);
				size--;
			}		
				
			
		}


	}

	void qChange(queue<property>& queue_0)
	{
		bool flag = true;

		string name_;
		int cost;
		vector<property> qVector;
		string name = change(name_, cost);
		while (flag)
		{
			if (!queue_0.empty())
			{
				auto stName = queue_0.front();
				queue_0.pop();
				if (stName.getName() == name)
				{
					flag = false;
					break;

				}
				qVector.push_back(stName);
			}
			else
			{
				break;
			}
		}
		if (flag)
		{
			cout << "Такой недвижемости не существует" << endl;
		}
		else
		{
			queue<property> q;
			property pr;
			pr.setName(name_);
			pr.setCost(cost);
			for (int i = 0; i < qVector.size(); i++)
			{
				q.push(qVector[i]);
			}
			q.push(pr);
			while (!queue_0.empty())
			{
				q.push(queue_0.front());
				queue_0.pop();
			}
			q.swap(queue_0);
		}
	}

	void pqChange(priority_queue<property>& pq_property)
	{
		bool flag = true;

		string name_;
		int cost;
		vector<property> pqVector;
		string name = change(name_, cost);
		while (flag)
		{
			if (!pq_property.empty())
			{
				auto stName = pq_property.top();
				pq_property.pop();
				if (stName.getName() == name)
				{
					flag = false;
					break;

				}
				pqVector.push_back(stName);
			}
			else
			{
				break;
			}
		}
		if (flag)
		{
			cout << "Такой недвижемости не существует" << endl;
		}
		else
		{
			
			property pr;
			pr.setName(name_);
			pr.setCost(cost);
			pq_property.push(pr);
			for (int i =0; i < pqVector.size(); i++)
			{
				pq_property.push(pqVector[i]);
			}
		}

	};
};


int main()
{	
	setlocale(LC_ALL, "rus");

	function fu;
	base base;
	int conteiner;
	int index;
	bool exit = true;
	stack<property, vector<property>> stProperty;
	queue<property> qProperty;
	priority_queue<property> pqProperty;	
	while (exit)
	{
		cout << "1 - Queue\n2 - Stack\n3 - Priority_queue" << endl;
		conteiner = base.correctInput();
		conteiner--;
		switch (conteiner)
		{
		case 0:
			fu.qStart(qProperty);
			exit = false;
			break;
		case 1:
			fu.stStart(stProperty);
			exit = false;
			break;
		case 2:
			fu.pqStart(pqProperty);
			exit = false;
			break;
		default:
			cout << "Error"<<endl;
			break;

		}
	}
	exit = true;
	string name[3] = { "queue","stack","priority_queue" };
	system("cls");	
	while (exit)
	{
		
		cout << "1 - Добовление информации в "<<name[conteiner]<<"\n2 - Вывод информации из "<<name[conteiner]<<
			"\n3 - Редактирование информации в "<<name[conteiner]<<"\n0 - Выход"<<endl;
		index = base.correctInput();
		switch (index)
		{
		case 1://Добовление
			system("cls");
			switch (conteiner)
			{
			case 0:
				fu.qAdd(qProperty);				
				break;
			case 1:
				fu.stAdd(stProperty);				
				break;
			case 2:
				fu.pqAdd(pqProperty);				
				break;
			}
			break;
		case 2://Вывод
			system("cls");
			switch (conteiner)
			{
			case 0:
				fu.qShow(qProperty);
				break;
			case 1:
				fu.stShow(stProperty);
				break;
			case 2:
				fu.pqShow(pqProperty);
				break;
			}
			break;
		case 3://Редактирование
			system("cls");
			switch (conteiner)
			{
			case 0:
				fu.qShow(qProperty);
				fu.qChange(qProperty);
				break;
			case 1:
				fu.stShow(stProperty);
				fu.stChange(stProperty);
				break;
			case 2:
				fu.pqShow(pqProperty);
				fu.pqChange(pqProperty);
				break;
			}
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
