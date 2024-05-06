#pragma once
#include <iostream>
#include "../Data Structures/ArrayStack.h"
#include "../Army units/ArmyUnit.h"   
using namespace std;
class Tanks :public stack<ArmyUnit*>
{

public:	
	Tanks();
	bool addUnit(ArmyUnit* tnk);
	ArmyUnit* pickTank();
	void printTanks();
	int getCount();
	~Tanks();
};