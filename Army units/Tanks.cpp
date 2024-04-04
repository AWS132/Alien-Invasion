#include "Tanks.h"
bool Tanks::CreatTank(int id, int tj, int health, int power, int capacity)
{
	ArmyUnit* tnk = new ArmyUnit(id,ET,tj,health,power,capacity);
	return push(tnk);
}

ArmyUnit* Tanks::pickTank()
{
	return pop();
}

void Tanks::printTanks()
{
	for (int i = 0; i <= top; i++)
	{
		items[i]->Print();
	}
}

int Tanks::getCount()
{
	return top+1;
}
