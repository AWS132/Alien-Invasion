#pragma once 
#include "Drone.h"
#include <iostream>
#include"ArmyUnit.h"

using namespace std;

Drone::Drone(int id, int tj, int health, int power, int capacity, GameClass* game): ArmyUnit(id,AD,tj,health,power,capacity,game)
{
}


bool Drone::attack(bool gameMode)
{
	GenQueueADT lst;
	double dmg = hlth * pwr / 100.0;
	ArmyUnit* unt = nullptr;
	ArmyUnit* unit = nullptr;
	if (gameMode)
		cout << "AD " << ID << " Attacks ";
	int tempCap = min(cap,game->getEArmy()->countOf(ET)+ game->getEArmy()->countOf(EG));
	for (int i = 0; i < tempCap; i++) {
		if (i % 2) {
			unt = game->pickUnit(EG,unit,unit);
		}
		else {
			unt = game->pickUnit(ET,unit,unit);
		}
		if (unt) {
			unt->decHlth(dmg / sqrt(unt->getHealth()));
			lst.addUnit(unt);
		}
		else {
			tempCap++;
		}
	}
	if (gameMode)
		lst.printList();
	bool occurred = !lst.isEmpty();
	while (lst.getCount())
	{
		ArmyUnit* unt = lst.pickUnit();
		if (unt && unt->getHealth() > 0)
		{
			if (!game->getEArmy()->addToUML(unt))
				game->addUnit(unt);
		}
		else
		{
			unt->setTd(game->getTime());
			game->addToKldList(unt);
		}
	}
	return occurred;
}