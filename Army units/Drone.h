#pragma once
#include <iostream>
#include "../Army units/ArmyUnit.h"

class Drone :protected ArmyUnit
{
public:
	Drone(int id, int tj, int health, int power, int capacity);
	void Attack(ArmyUnit* opponent);
};