#pragma once
#include <iostream>
#include "../Army units/GenQueueADT.h"
#include "ArmyUnit.h"
using namespace std;
class AllyArmy
{
private:
	GenQueueADT* su;
	int id;
	bool isCalled;
public:
	AllyArmy();
	int getId();
	void addUnit(ArmyUnit* unit);
	void printArmy();
	void call();
	bool getStatus();
	bool checkID();
	void withdraw();
	int getCount() const;//returns the total count of the current ally Army
	~AllyArmy();
	ArmyUnit* pickSUnit();
	void destructAll();
	ArmyUnit* peekSUnit();
};
