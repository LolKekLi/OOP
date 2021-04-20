#include <iostream>
#include <ctime>
using namespace std;


int random(int size)
{
	size = size - 3;
	return rand() % 3 + size;
}

class Man
{
protected:
	string name[8] = { "Petia","Vania","Iggoooooor","VAlera"
	,"Anton","Kir","Senia","Egor"};	//Доделать 
};

class Client:Man
{
private:
	int numbName;
public:
	Client()
	{
		numbName = random(8);
	}
	void Show()
	{
		cout<<name[numbName]<<"\n";
	}
};

class Trainer:Man
{
private:
	int numbExp;
	int numbName;
	int Exp[4] = { 12,4,10000,25 };
public:
	Trainer()
	{
		numbExp = random(4);
		numbName = random(8);//Доделать 
	}

	void Show()
	{
		cout << Exp[numbExp] << "\n" << name[numbName] << "\n";
	}
	
};

class TrainingAp
{
private:
	string firm[5] = { "Atalnt","Sumsung","Nokia","Intel","Fil" };
	string groupOfMuscle[3] = { "Arms","Legs","Chest" };
	int numbFirm;
	int numbGroupOf;
public:
	TrainingAp()
	{
		numbFirm =random(5);	
		numbGroupOf = random(3);
	}
	void show()
	{
		cout << firm[numbFirm] << "\n" << groupOfMuscle[numbGroupOf]<<"\n";
	}
};

class Gym
{
private:
	int numbGym ;
	string gymName [3]= {"Adrenalin","ArGYMent","GYYYYYYYYM"};
	int sizeOfApp;
	TrainingAp trainingAp;
	Trainer trainer;
	
public:
	Gym(TrainingAp &training_ap, Trainer trainer)
	{
		this->trainer = trainer;
		trainingAp = training_ap;
		training_ap.show();
		numbGym = random(3);
	}
	void showName()
	{
		cout << gymName[numbGym];
	}
	
};



void main()
{
	srand(time(0));

	int sizeOfTraingAp = random(6);
	TrainingAp *training_ap = new TrainingAp[sizeOfTraingAp];
	/*for (int i =0 ; i<sizeOfTraingAp; i++)
	{
		training_ap[i].show();
	}*/
	
	Trainer trainer;
	Gym gym(*training_ap,trainer);
	cout << "Welcome in ";
	gym.showName();
	cout << " gym\nThis gym has ";
	
	
	
}
