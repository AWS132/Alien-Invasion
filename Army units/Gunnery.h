#pragma once
#include"../../Army units/ArmyUnit.h"
#include "../Game/GameClass.h"

class Gunnery :public ArmyUnit
{
public:
	Gunnery(int id, int tj, int health, int power, int capacity, GameClass* game);
	bool attack(bool gameMode);
};