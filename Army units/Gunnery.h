#pragma once
#include"../Army units/ArmyUnit.h"
class GameClass;
class Gunnery :public ArmyUnit
{
public:
	Gunnery(int id, int tj, int health, int power, int capacity, GameClass* game);
	void Attack(ArmyUnit* opponent);
};