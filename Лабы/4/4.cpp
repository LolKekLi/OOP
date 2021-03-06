#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include "stdlib.h"
#include <string>
#include <vector>

#include "Windows.h"
using namespace std;

string filenameINFO = "info.txt";
string resfile = "res.txt";

class BASE
{
    ifstream in;   
    string info;
public:
    
    BASE()
    {
        in.open(filenameINFO);
    	if(in.is_open())
    	{
            while (getline(in, info,'\0'));            
    	}
    	else
    	{
            cout << "Error! File not open";
    	}
    }    
	
    void FileInf(string array[], int number_of_elements, string inf)
    {
        int position2=0;        
        int count;
        int position1;
        int i = 0;
        int start = info.find(inf);
        int end = info.find("|||", start);
        count = end - start;
        string substr = info.substr(start, count);

        while (i < number_of_elements)
        {
            position1 = substr.find('\n', position2 + 1);
            position2 = substr.find('\n', position1 + 1);
            count = position2 - position1;
            array[i] = substr.substr(1 + position1, count - 1);
            i++;
            position2 = position1;
        }

    }
	
	int correctInputInt()
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

    char correctInpitChar(char correctChar1, char correctChar2)
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

    int random(int a, int b)
    {

        if (a > 0) return a + rand() % (b - a);
        else return a + rand() % (abs(a) + b);
    }

    int makingCollection(int a, int b)
    {
        if (b == 0)
            throw std::runtime_error("Fail!");
        return a / b;

    }

};

class Man
{
protected:
    string name[8];
};

class Trainer :Man, BASE
{
private:
    BASE base;
    int numbExp;
    int numbName;
    int Exp[4] = { 12,4,10000,25 };
public:
    Trainer()
    {
        FileInf(name, 8, "NAME");
        numbExp = random(0, 4);
        numbName = random(0, 8);//Доделать 
    }

    void Show()
    {
        cout << name[numbName] << " Exp " << Exp[numbExp] << " years" << "\n\n";
    }

};

class TrainingAp: BASE
{
private:
    string firm[5];
    string groupOfMuscle[3];
    int numbFirm;
    int numbGroupOf;
public:
    TrainingAp()
    {        
        FileInf(firm, 5, "FIRM");
        FileInf(groupOfMuscle, 3, "GROUPOFMUSCLE");
        numbFirm = random(0, 5);
        numbGroupOf = random(0, 3);
    }	
    void show()
    {
        cout << "Firm " << firm[numbFirm] << " for " << groupOfMuscle[numbGroupOf] << "\n";
    }
};

class Gym:BASE
{
private:
    int numbGym;
    string gymName[3];
    int sizeOfApp = 0;
    Trainer trainer;

public:
    string aboniment[4];

    Gym(Trainer trainer)
    {
        FileInf(gymName, 3, "GYMNAME");
        FileInf(aboniment,4,"ABONIMENT");
        this->trainer = std::move(trainer);

        numbGym = random(0, 3);
    }

    Gym()
    {
        FileInf(gymName, 3, "GYMNAME");
        FileInf(aboniment, 4, "ABONIMENT");
	    numbGym = random(0, 3);
    }

    void showTrainer()
    {
        trainer.Show();
    }

    void showName()
    {
        cout << gymName[numbGym];
    }

    void showAbonument()
    {
        cout.setf(ios::right);

        for (int i = 0; i < 4; i++)
        {
            cout.width(25);
            cout << i + 1 << " " << aboniment[i] << endl;
        }
        cout.width(25);

        cout.unsetf(ios::right);
    }

};

class Client :Man
{
private:
    ofstream out;
    int numbName;
    double money;
    string Name;
    int* check = new int;
    Gym gym_;

public:
    int numberOfCheck;
    Client(string name, double money) : gym_()
    {
        numberOfCheck = 0;
        Name = name;
        this->money = money;
    }

    void showMoney()
    {
        cout << money << "$";
    }

    void eddToCheck(int numberOfAboniment)
    {
        check[numberOfCheck] = numberOfAboniment;
        numberOfCheck++;
    }

    void deleteSmth(int numberOfDelete)
    {
        for (int i = numberOfDelete; i < numberOfCheck; i++)
        {
            check[i] = check[i + 1];
        }
        numberOfCheck--;
    }

    void showCheck()
    {
        cout << "\nYour check" << endl;
        for (int i = 0; i < numberOfCheck; i++)
        {
            cout << i << " " << gym_.aboniment[check[i]] << endl;
        }
        cout << endl;

    }

    void deleteAll()
    {
        for (int i = 0; i < numberOfCheck; i++)
        {
            check[i] = 0;
        }
        numberOfCheck = 0;
    }

    void showName()
    {
        cout << Name;
    }

	void writeCheck()
    {
        out.open(resfile); // окрываем файл для записи
        if (out.is_open())
        {
            out << Name;
            out << "\nYour check" << endl;
            for (int i = 0; i < numberOfCheck; i++)
            {
                out << i << " " << gym_.aboniment[check[i]] << endl;
            }
            
        }
        
    }
};



int main()
{
    BASE base;
    srand(time(0));
    string name;
    cout << "Enter your name" << endl;
    cin >> name;
    char temp;
    int money;
    cout << "Enter quantity your money\n";
    money = base.correctInputInt();
    Client client(name, money);

    int sizeOfTraingAp = base.random(1, 6);
    TrainingAp* training_ap = new TrainingAp[sizeOfTraingAp];
    Trainer trainer;
    Gym gym((std::move(trainer)));
    cout << "Welcome ";
    client.showName();
    cout << " in ";
    gym.showName();
    cout << " gym\nThis gym has " << sizeOfTraingAp << " Treneri \n";
    for (int i = 0; i < sizeOfTraingAp; i++)
    {
        cout << i + 1 << ")";
        training_ap[i].show();
    }
    cout << "\nYour trainer is ";
    gym.showTrainer();
    cout << "You want to see information about aboniments ?\nY/N" << endl;
    temp = base.correctInpitChar('Y', 'N');
    if (temp == 'Y')
    {
        gym.showAbonument();
        cout << "Your have ";
        client.showMoney();
        cout << "\nYou want to by aboniment?\nY/N" << endl;
        {
            temp = base.correctInpitChar('Y', 'N');
            if (temp == 'Y')
            {
                system("CLS");
                cout << "What aboniment you want to by\n";
                gym.showAbonument();
                cout << "Enter number \n";
                int numberOfAboniment;
                numberOfAboniment = base.correctInputInt();
                client.eddToCheck(numberOfAboniment - 1);
                client.showCheck();
                int f = true;
                while (f)
                {
                    cout << "You want to 2 - delete/3 - add somth to your zakaz?/Any other letter - cancel\n" << endl;
                    int tempp;
                    tempp = base.correctInputInt();

                    switch (tempp)
                    {
                    case 2:
                        cout << "Your want do delete all?\nY/N" << endl;
                        cin >> temp;
                        if (temp == 'Y' || temp == 'y')
                        {
                            client.deleteAll();
                            client.showCheck();

                        }
                        else
                        {
                            cout << "Enter number what you whant to delete" << endl;
                            client.showCheck();
                            cin >> tempp;
                            client.deleteSmth(tempp);
                            client.showCheck();
                        }
                        break;
                    case 3:
                        client.showCheck();
                        cout << "What your whant to add to your check?\n";
                        gym.showAbonument();
                        cout << "\nEnter number ";
                        cin >> tempp;
                        client.eddToCheck(tempp - 1);
                        client.showCheck();

                        break;


                    default:
                        f = false;
                        break;
                    }
                    temp = ' ';
                }
            }
            else
            {
                cout << "Well, okay";
            }
        }
    }
    else
    {
        cout << "Well, okay";
    }
    cout << "You want to write info in file?\nY/N\n";
    temp = base.correctInpitChar('Y', 'N');
    if (temp == 'Y')
    {
        client.writeCheck();
    }
    cout << "\nYou need to make collection\nMake?\nY/N\n";
    bool end = false;
    while (!end)
    {
        temp = ' ';
        cin >> temp;
        if (temp == 'y' || temp == 'Y')
        {
            int show = money;
            for (int i = 0; i <= money; i++)
            {
                system("cls");
                cout << "Processing " << show-- << " attempt to make a collection";
                Sleep(1000 / 3);
                system("cls");

            }
            if (base.random(0, 2) == 0)
            {
                cout << "Fail(";
            }
            else
            {
                cout << "Secsess!!!!!!!!!!!!!";
            }

            end = true;
        }
        else
        {
            if (temp == 'N' || temp == 'n')
            {
                cout << "Well, okay\nIt's all";
                end = true;
            }
            else
            {
                temp = '\0';
                cout << "Try press button again\nMake?\nY/N\n";
            }
        }
    }
    return 0;
}