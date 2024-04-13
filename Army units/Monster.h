#pragma once
#include <iostream>
#include "../Army units/ArmyUnit.h"
class GameClass;
class Monster :public ArmyUnit
{

public:
	Monster(int id, int tj, int health, int power, int capacity, GameClass* game);
	void Attack(ArmyUnit* opponent);
};