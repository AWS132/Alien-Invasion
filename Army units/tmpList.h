#pragma once
#include <iostream>
#include "ArmyUnit.h"
#include "../Data Structures/LinkedQueue.h"
class ArmyUnit;
class tmpList:protected LinkedQueue<ArmyUnit*> {
private:
	int count;
public:

	tmpList();
	bool addUnit(ArmyUnit* Unit);
	ArmyUnit* PickUnit();
	int getCount() const;
	void printTmpList();
	~tmpList();
};