#pragma once
#include "Data Structures/Pqueue.h"
class Esoldiers:protected queue<ArmyUnit*>
{
private:
	int count;
	queue<ArmyUnit*> ES_list;
public:
	Esoldiers();
	bool CreateEsoldiers(int id, int tj, int health, int power, int capacity);
	ArmyUnit* pickEsoldiers();
	void printEsoldiers();
	int getCount();
};

