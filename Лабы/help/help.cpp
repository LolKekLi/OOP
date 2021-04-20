#include <iostream>
#include <map>

using namespace std;
int main() {
    setlocale(0, "");
    map <int, int> mp;

    cout << "Введите количество элементов: ";
	int n;
	cin >> n;

    for (int i = 0; i < n; i++) {
        cout << i << ") ";
    	int a;
    	cin >> a;
        mp[a] = i;  // добавляем новые элементы
    }

    map <int, int> ::iterator it = mp.begin();
    cout << "А вот все отсортированно: " << endl;
    for (int i = 0; it != mp.end(); it++, i++) {  // выводим их
        cout << i << ") Ключ " << it->first << ", значение " << it->second << endl;
    }

    system("pause");
    return 0;
}