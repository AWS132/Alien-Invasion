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
	mt19937 gen(rd());
	while (game.getTime() <= 50)
	{

		srand(time(0));
		x = (gen() % (100)) + 1;	//(rand() % (ub - lb + 1)) + lb
		game.initializer();
		if (x > 0 && x < 10)
		{
			unit = game.getEArmy()->pickEUnit(ES);
			game.getEArmy()->AddUnit(unit);
		}
		else if (x > 10 && x < 20)
		{
			unit = game.PickUnit(ET, nullptr, nullptr);
			game.AddToKilledList(unit);
		}
		else if (x > 20 && x < 30)
		{
			unit = game.PickUnit(EG, nullptr, nullptr);
			if (unit) {
				unit->DecHlth(0.5 * unit->getHealth());
				game.AddUnit(unit);
			}
		}
		else if (x > 30 && x < 40)
		{
			ArmyUnit* soldiers[5];
			for (int i = 0; i < 5; i++)
			{
				soldiers[i] = game.PickUnit(AS, nullptr, nullptr);
			}
			for (int i = 0; i < 5; i++)
			{
				soldiers[i]->DecHlth(10);  // random value
			}
			for (int i = 0; i < 5; i++)
			{
				game.AddtoTmpList(soldiers[i]);
			}
			for (int i = 0; i < 5; i++)
			{
				game.AddUnit(game.pickFromTmpList());
			}
		}
		else if (x > 40 && x < 50)
		{
			ArmyUnit* mns[5];
			for (int i = 0; i < 5; i++)
			{
				mns[i] = game.PickUnit(AM, nullptr, nullptr);
			}
			for (int i = 0; i < 5; i++)
			{
				game.AddUnit(mns[i]);
			}
		}
		else if (x > 50 && x < 60)
		{
			ArmyUnit* drns[6];
			for (int i = 0; i < 6; i += 2)
			{
				game.PickUnit(AD, drns[i], drns[i + 1]);
			}
			for (int i = 0; i < 6; i++)
			{
				game.AddToKilledList(drns[i]);
			}

		}
	}
}