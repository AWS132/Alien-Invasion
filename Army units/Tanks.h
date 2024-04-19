#pragma once
#include <iostream>
#include "../Data Structures/ArrayStack.h"
#include "../Army units/ArmyUnit.h"   
using namespace std;
class Tanks :protected stack<ArmyUnit*>
{
private:
	int counter;
public:	
	Tanks();
	bool addUnit(ArmyUnit* tnk);
	ArmyUnit* pickTank();
	void printTanks();
	int getCount();
	~Tanks();
};