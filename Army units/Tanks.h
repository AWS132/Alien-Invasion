#pragma once
#include <iostream>
#include "../Data Structures/ArrayStack.h"
#include "../Army units/ArmyUnit.h"
class Tanks :protected ArrayStack<ArmyUnit>
{
public:
	bool CreatTank(int id, int tj, int health, int power, int capacity);
	ArmyUnit* pickTank();
	void printTanks();
};