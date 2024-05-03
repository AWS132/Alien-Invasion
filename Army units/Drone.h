#pragma once
#include <iostream>
#include "../Army units/ArmyUnit.h"
#include "../Game/GameClass.h"
class Drone :public ArmyUnit
{
public:
	Drone(int id, int tj, int health, int power, int capacity, GameClass* game);
	void Attack(int flag);
};