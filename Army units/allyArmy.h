#pragma once
#include <iostream>
#include "../Army units/genQueueADT.h"
#include "ArmyUnit.h"
using namespace std;
class allyArmy
{
private:
	genQueueADT* su;
	int id;
	bool isCalled;
public:
	allyArmy();
	int getId();
	void AddUnit(ArmyUnit* unit);
	void PrintArmy();
	void call();
	bool getStatus();
	void withdraw();
	int getCount() const;//returns the total count of the current ally Army
	~allyArmy();
	ArmyUnit* pickSUnit();
	void destructAll();
	ArmyUnit* peekSUnit();
};
