#pragma once
#include "Data Structures/LinkedQueue.h"
#include"Army units/ArmyUnit.h"
class Asoldiers :protected LinkedQueue<ArmyUnit*>
{
private:
	int count;
public:
	Asoldiers();
	bool addUnit(ArmyUnit* as);
	ArmyUnit* pickAsoldiers();
	void printAsoldiers();
	int getCount();
	~Asoldiers();
};

