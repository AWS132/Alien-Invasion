#pragma once
#include "../Army units/ArmyUnit.h"   
#include "../Game/GameClass.h"
class HU :public ArmyUnit
{

public:
	HU(int id, int tj, int health, int power, int capacity, GameClass* game);
	void Attack();
};
