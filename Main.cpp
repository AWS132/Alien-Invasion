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
	ArmyUnit* unit;
	int x;
	while (game.getTime() <= 50)
	{
		srand(time(0));
		x = (rand() / (double)(RAND_MAX)) * 100;
		game.initializer();
		if (x > 0 && x < 10)
		{
			unit=game.getEArmy()->pickEUnit(ES);
			game.getEArmy()->AddUnit(unit);
		}
		else if (x > 10 && x < 20)
		{
			unit = game.getEArmy()->pickEUnit(ET);
			game.AddToKilledList(unit);
		}
	}

}