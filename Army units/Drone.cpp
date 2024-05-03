#pragma once 
#include "Drone.h"
#include <iostream>
#include"ArmyUnit.h"

using namespace std;

Drone::Drone(int id, int tj, int health, int power, int capacity, GameClass* game): ArmyUnit(id,AD,tj,health,power,capacity,game)
{
}


void Drone::Attack(int flag)
{
	tmpList lst;
	double dmg = hlth * pwr / 100.0;
	ArmyUnit* unt = nullptr;
	if (flag)
		cout << "AD " << ID << " Attacks ";
	for (int i = 0; i < cap; i++) {
		if (i % 2) {
			unt = game->getEArmy()->pickEUnit(EG);
		}
		else {
			unt = game->getEArmy()->pickEUnit(ET);
		}
		if (unt) {
			unt->DecHlth(dmg / sqrt(unt->getHealth()));
			lst.addUnit(unt);
		}
	}
	if (flag)
		lst.printTmpList();

	while (lst.getCount())
	{
		ArmyUnit* unt = lst.PickUnit();
		if (unt && unt->getHealth() > 0)
			game->AddUnit(unt, 0);
		else
		{
			unt->setTd(game->getTime());
			game->AddToKilledList(unt);
		}
	}
}