#pragma once

#include "../Army units/ArmyUnit.h"   
class Tank :public ArmyUnit
{
public:
	Tank(int id,  int tj, int health, int power, int capacity);
	void Attack(ArmyUnit* opponent);
};