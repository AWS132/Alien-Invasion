#pragma once
#include <iostream>
#include "../Army units/ArmyUnit.h"
class Monsters 
{
public:
	bool CreatMonster(int id, int tj, int health, int power, int capacity);
	ArmyUnit* pickMonster();
	void printMonsters();
	int getCount();
};