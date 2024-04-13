#pragma once
#include <iostream>
#include "ArmyUnit.h"
#include "../Data Structures/LinkedQueue.h"

class KilledList:protected LinkedQueue<ArmyUnit*> {
private:
	int count;
public:

	KilledList();
	bool addUnit(ArmyUnit* Unit);
	int getCount() const;
	void printKilled();
	~KilledList();
};