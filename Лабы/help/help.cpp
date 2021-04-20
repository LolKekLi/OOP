#include <fstream>
#include <iostream>
using namespace std;
#include <fstream>
#include <iostream>
using namespace std;
class Person {
protected:
	string name;//имя
	int age;//возраст
public:
	void getData()
	{//получить данные о человеке
		cout << "\nВведите имя: ";

		cin >> name;
		cout << "Введите возраст: ";
		cin >> age;
	}
	void showData()
	{//вывод данных о человеке
		cout << "\n Имя: " << name;
		cout << "\n Возраст: " << age;
	}
};
int main() {
	system("chcp 1251");
	system("cls");
	Person pers;//создать объект person
	ifstream infile;//создать входной файл
	infile.open("GROUP.DAT", ios::in | ios::binary);
	infile.seekg(0, ios::end);//установить указатель на 0 байт отконца файла
	int endposition = infile.tellg();//найти позицию в файле
	int n = endposition / sizeof(Person);//число человек
	cout << "\nВ файле " << n << " человек(а)";
	cout << "\nВведите номер персоны: ";
	cin >> n;
	int position = (n - 1) * sizeof(Person);//умножить размерсозданных данных на число персон
	infile.seekg(position);//число байт от начала
		//прочитать одну персону
	infile.read(reinterpret_cast<char*>(&pers), sizeof(pers));
	pers.showData();//вывести одну персону
	cout << endl;
	return 0;
}