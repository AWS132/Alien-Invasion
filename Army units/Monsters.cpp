#include "Monsters.h"

Monsters::Monsters()
{
	counter = 0;
}

//bool Monsters::CreatMonster(int id, int tj, int health, int power, int capacity)
//{
//	if(counter<MAX_SIZE)
//	{ 
//	ArmyUnit* mns = new ArmyUnit(id, AM, tj, health, power, capacity);
//	monsters[counter++] = mns;
//	return true;
//	}
//	return false;
//}

bool Monsters::AddMonster(ArmyUnit* mns)
{
	if(counter<MAX_SIZE)
	{ 
	monsters[counter++] = mns;
	return true;
	}
	return false;

}

int Monsters::getCount()
{
	return (counter);
}

ArmyUnit* Monsters::pickMonster()
{
	if (counter>0)
	{
		srand(time(0));
		int randomdx = floor((rand() * 1.0 / RAND_MAX) * counter);
		ArmyUnit* target = monsters[randomdx];
		monsters[randomdx] = monsters[--counter];
		return target;
	}
	else
		return nullptr;
}

void Monsters::printMonsters()
{
	for (int i = 0; i < counter; i++)
	{
		monsters[i]->Print();
	}
}
