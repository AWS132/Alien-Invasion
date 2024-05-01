#pragma once
#include "../Army units/ArmyUnit.h"
#include "../Game/GameClass.h"
class Esoldier : public ArmyUnit
{
public:
	Esoldier(int id, int tj, int health, int power, int capacity, GameClass* game);
	void Attack(int flag);
};

