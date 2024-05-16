#pragma once

#include "../Army units/ArmyUnit.h"   
#include "../Game/GameClass.h"   
class Tank :public ArmyUnit
{
public:
	Tank(int id,  int tj, int health, int power, int capacity, GameClass* game);
	void attack(bool gameMode);  
};