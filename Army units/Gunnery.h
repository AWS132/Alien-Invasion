#pragma once
#include"../../Army units/ArmyUnit.h"
class Gunnery :public ArmyUnit
{
public:
	Gunnery(int id, int tj, int health, int power, int capacity);
	void Attack(ArmyUnit* opponent);
};