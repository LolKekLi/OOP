#include <iostream>
#include <map>    //подключили библиотеку для работы с map
using namespace std;

template <typename T,typename U>
void p(map<T,U>& myFirstMap)
{
    for (auto it = myFirstMap.begin(); it != myFirstMap.end(); ++it)
    {
        cout << it->first << " : " << it->second << endl;
    }
}

int main()
{
    map <string, int> myFirstMap = { { "Mother", 37 },
                                   { "Father", 40 },///map явно инициализирована
                                   { "Brother", 15 },
                                   { "Sister", 20 } };
    p(myFirstMap);
    /*///вывод явно инициализированной map на экран
    for (auto it = myFirstMap.begin(); it != myFirstMap.end(); ++it)
    {
        cout << it->first << " : " << it->second << endl;
    }

    char c;
    map <char, int> mySecondMap;
    for (int i = 0, c = 'a'; i < 5; ++i, ++c)
    {
        mySecondMap.insert(pair<char, int>(c, i));
    }

    ///вывод не явно инициализированной map на экран
    for (auto it = mySecondMap.begin(); it != mySecondMap.end(); ++it)
    {
        cout << (*it).first << " : " << (*it).second << endl;
    }*/
    return 0;
}