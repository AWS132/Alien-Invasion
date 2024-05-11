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
	genQueueADT lst;
	double dmg = hlth * pwr / 100.0;
	ArmyUnit* unt = nullptr;
	if (flag)
		cout << "AD " << ID << " Attacks ";
	int tempCap = min(cap,game->getEArmy()->CountOf(ET)+ game->getEArmy()->CountOf(EG));
	for (int i = 0; i < tempCap; i++) {
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
		else {
			tempCap++;
		}
	}
	if (flag)
		lst.printList();

	while (lst.getCount())
	{
		ArmyUnit* unt = lst.pickUnit();
		if (unt && unt->getHealth() > 0)
		{
			if (unt->getHealth() < 0.2 * unt->getStartHlth())
				game->getEArmy()->AddToUML(unt);
			else
				game->AddUnit(unt/*,0*/);
		}
		else
		{
			unt->setTd(game->getTime());
			game->AddToKldList(unt);
		}
	}
}