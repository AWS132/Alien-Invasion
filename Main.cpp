 #include<iostream>
#include "Game/GameClass.h"


using namespace std;
int main()
{
	GameClass game;
	cout << "Which mode of operation you want to select:\n1) Active mode\n2) Silent mode\n";
	int mode,fileName;
	cin >> mode;
	cout << "pick the number of the input file you want to select\n";
	cin >> fileName;
	game.initializer(mode%2,fileName);

	//int x; 
	//random_device rd;
	//mt19937 gen(rd());
	//ArmyUnit* nl = nullptr;
	//while (game.getTime() <= 50)
	//{
	//	x = (gen() % (100)) + 1;	//(rand() % (ub - lb + 1)) + lb
	//	game.initializer();
	//	cout <<"X = " << x;
	//	if (x > 0 && x < 10)
	//	{
	//		cout << ": Pick Earth Soldier and insert it again";
	//		ArmyUnit* unit = nullptr;
	//		unit = game.PickUnit(ES, nl, nl);
	//		game.AddUnit(unit);
	//	}
	//	else if (x > 10 && x < 20)
	//	{
	//		cout << ": Pick Earth tank from its list and move it to the kld lst";
	//		ArmyUnit* unit = nullptr;
	//		unit = game.PickUnit(ET, nl, nl);
	//		game.AddTogenQueueADT(unit);
	//	}
	//	else if (x > 20 && x < 30)
	//	{
	//		cout << ": Pick Eath gunnery from its list, and decrement its health to half then insert it again";
	//		ArmyUnit* unit=nullptr;
	//		unit = game.PickUnit(EG, nl, nl);
	//		if(unit)
	//		{
	//			unit->DecHlth(0.5 * unit->getHealth());
	//		}
	//		game.AddUnit(unit);
	//	}

	//	else if (x > 30 && x < 40)
	//	{
	//		cout << ": Pick 5 Alien soldiers, decrement their health, put them in a tmp lst and return them to their list";
	//		game.genQueueADTfn(AS,5,10);
	//	}
	//	else if (x > 40 && x < 50)
	//	{
	//		cout << ": Pick 5 Monsters and insert them again\n";
	//		ArmyUnit* mns[5];
	//		for (int i = 0; i < 5; i++)
	//		{
	//			mns[i] = nullptr;
	//		}
	//		for (int i = 0; i < 5; i++)
	//			mns[i] = game.PickUnit(AM, nl, nl);

	//		for (int i = 0; i < 5; i++)
	//		{
	//			game.AddUnit(mns[i]);
	//		}
	//	}
	//	else if (x > 50 && x < 60)
	//	{
	//		cout << ": Pick 6 drones and move them to killed list";
	//		ArmyUnit* drns[6];
	//		for (int i = 0; i < 6; i++)
	//		{
	//			drns[i] = nullptr;
	//		}
	//		for (int i = 0; i < 6; i += 2)
	//		{
	//			game.PickUnit(AD, drns[i], drns[i + 1]);
	//		}
	//		for (int i = 0; i < 6; i++)
	//		{
	//			game.AddTogenQueueADT(drns[i]);
	//		}
	//	}
	//	cout << endl;
	//}
}