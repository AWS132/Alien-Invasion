#pragma once
#include <iostream>
#include "../Data Structures/ArrayStack.h"
#include "../Army units/ArmyUnit.h"   
class Tanks :protected stack<ArmyUnit*>
{
public:
	
	//bool CreatTank(int id, int tj, int health, int power, int capacity);
	bool addUnit(ArmyUnit* tnk);
	ArmyUnit* pickTank();
	void printTanks();
	int getCount();
};