#pragma once
#include <iostream>
#include "../Army units/ArmyUnit.h"
#include "../Game/GameClass.h"
class Monster :public ArmyUnit
{

public:
	Monster(int id, int tj, int health, int power, int capacity,GameClass* game);
	bool attack(bool gameMode);
};