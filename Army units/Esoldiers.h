#pragma once
#include "../Data Structures/LinkedQueue.h"
#include "../Army units/ArmyUnit.h"
class Esoldiers:protected LinkedQueue<ArmyUnit*>
{
private:
	int count;
public:
	Esoldiers();
	bool addUnit(ArmyUnit* es);
	ArmyUnit* pickEsoldiers();
	void printEsoldiers();
	int getCount();
	~Esoldiers();
};

