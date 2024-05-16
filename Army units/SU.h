#pragma once

#include "../Army units/ArmyUnit.h"   
#include "../Game/GameClass.h"   
class SU :public ArmyUnit
{
public:
	SU(int id,  int tj, int health, int power, int capacity, GameClass* game);
	void attack(bool gameMode);
};