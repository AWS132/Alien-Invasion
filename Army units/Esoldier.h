#pragma once
#include "ArmyUnit.h"
class Esoldier : public ArmyUnit
{
public:
	Esoldier(int id, int tj, int health, int power, int capacity);
	void Attack(ArmyUnit* opponent);
};

