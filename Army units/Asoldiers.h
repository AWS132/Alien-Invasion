#pragma once
#include "Data Structures/Pqueue.h"
class Asoldiers :protected queue<ArmyUnit*>
{
private:
	int count;
public:
	Asoldiers();
	bool addAsoldier(ArmyUnit* as);
	ArmyUnit* pickAsoldiers();
	void printAsoldiers();
	int getCount();
};

