#pragma once
#include <iostream>
#include "../Army units/ArmyUnit.h"

class Drone :public ArmyUnit
{
public:
	Drone(int id, int tj, int health, int power, int capacity, GameClass* game);
	void Attack(ArmyUnit* opponent);
};