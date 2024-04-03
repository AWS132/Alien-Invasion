#include "Tanks.h"
bool Tanks::CreatTank(int id, int tj, int health, int power, int capacity)
{
	ArmyUnit* tnk = new ArmyUnit(id,ET,tj,health,power,capacity);
	return push(*tnk);
}

ArmyUnit* Tanks::pickTank()
{
	if (isEmpty()) return NULL;
	top--;
	return &items[top];
}

void Tanks::printTanks()
{
	for (int i = 0; i <= top; i++)
	{
		items[i].Print();
	}
}
