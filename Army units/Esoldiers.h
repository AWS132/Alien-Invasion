#pragma once
#include "Data Structures/Pqueue.h"
class Esoldiers:protected queue<ArmyUnit*>
{
private:
	int count;
public:
	Esoldiers();
	//bool CreateEsoldiers(int id, int tj, int health, int power, int capacity);
	bool addEsoldier(ArmyUnit* es);
	ArmyUnit* pickEsoldiers();
	void printEsoldiers();
	int getCount();
};

