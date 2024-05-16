#pragma once
#include "../Army units/ArmyUnit.h"
#include "../Game/GameClass.h"
class Asoldier : public ArmyUnit
{
public:
	Asoldier(int id, int tj, int health, int power, int capacity, GameClass* game);
	void attack(bool gameMode);
};

