#pragma once
#include "ArmyUnit.h"
class Asoldier : public ArmyUnit
{
public:
	Asoldier(int id, int tj, int health, int power, int capacity);
	void Attack(ArmyUnit* opponent);
};

