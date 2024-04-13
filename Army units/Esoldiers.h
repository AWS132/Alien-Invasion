#pragma once
#include "../Data Structures/LinkedQueue.h"
class Esoldiers:protected LinkedQueue<ArmyUnit*>
{
private:
	int count;
public:
	Esoldiers();
	//bool CreateEsoldiers(int id, int tj, int health, int power, int capacity);
	bool addUnit(ArmyUnit* es);
	ArmyUnit* pickEsoldiers();
	void printEsoldiers();
	int getCount();
};

