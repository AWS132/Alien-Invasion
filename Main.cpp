 #include<iostream>
#include "Army units/Drones.h"
#include "Army units/Tanks.h"
#include "Army units/Monsters.h"
#include "Army units/Gunnerys.h"
#include "Game/GameClass.h"
#include "Game/randGen.h"

using namespace std;
int main()
{
	GameClass game;
	int x;
	ArmyUnit* unit;
	random_device rd;
	ArmyUnit* mns[5];
	ArmyUnit* drns[6];
	mt19937 gen(rd());
	ArmyUnit* nl= nullptr;
	while (game.getTime() <= 50)
	{
		x = (gen() % (100 - 1 + 1)) + 1;	//(rand() % (ub - lb + 1)) + lb
		game.initializer();
		if (x > 0 && x < 10)
		{
			unit = game.getEArmy()->pickEUnit(ES);
			if(unit)
			game.getEArmy()->AddUnit(unit);
		}
		else if (x > 10 && x < 20)
		{
			unit = game.PickUnit(ET, nl, nl);
			if(unit)
			game.AddToKilledList(unit);
		}
		else if (x > 20 && x < 30)
		{
			unit = game.PickUnit(EG, nl, nl);
			if(unit){
			unit->DecHlth(0.5 * unit->getHealth());
			game.AddUnit(unit);
		}
		}
		else if (x > 30 && x < 40)
		{
			ArmyUnit* soldiers[5];
			for (int i = 0; i < 5; i++)
			{
				soldiers[i] = game.PickUnit(AS, nl, nl);
			}
			for (int i = 0; i < 5; i++)
			{
				if(soldiers[i])
				soldiers[i]->DecHlth(10);  // random value
			}
			for (int i = 0; i < 5; i++)
			{
				//if (soldiers[i])
				game.AddtoTmpList(soldiers[i]);
			}
			for (int i = 0; i < 5; i++)
			{
				unit = game.pickFromTmpList();
			//	if(unit)
				game.AddUnit(unit);
			}
		}
		else if (x > 40 && x < 50)
		{
			for (int i = 0; i < 5; i++)
			{
				mns[i] = game.PickUnit(AM, nl, nl);
			}
			for (int i = 0; i < 5; i++)
			{
				if(mns[i])
				game.AddUnit(mns[i]);
			}
		}
		else if (x > 50 && x < 60)
		{
			for (int i = 0; i < 6; i += 2)
			{
				game.PickUnit(AD, drns[i], drns[i + 1]);
			}
			for (int i = 0; i < 6; i++)
			{
				if (drns[i])
				game.AddToKilledList(drns[i]);
			}
		}
	}
}