#include "Monsters.h"

Monsters::Monsters()
{
	counter = 0;
}
bool Monsters::addUnit(ArmyUnit* mns)
{
	if (counter < MAX_SIZE)
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
		random_device rd;
		mt19937 gen(rd());
		int randomdx = (gen() % (counter-1 - 0 + 1)) + 0;	//(rand() % (ub - lb + 1)) + lb
		ArmyUnit* target = monsters[randomdx];
		monsters[randomdx] = monsters[--counter];
		return target;
	}
	else
		return nullptr;
}

ArmyUnit* Monsters::peekMonster()
{
	if (counter > 0)
	{
		random_device rd;
		mt19937 gen(rd());
		int randomdx = (gen() % (counter - 1 - 0 + 1)) + 0;	//(rand() % (ub - lb + 1)) + lb
		ArmyUnit* target = monsters[randomdx];
		
		return target;
	}
	else
		return nullptr;
}

void Monsters::printMonsters()
{
	
	cout << "AM " << getCount() << " [";
	if(counter>0)
	{ 
	for (int i = 0; i < counter; i++)
	{
		monsters[i]->Print();
		if (counter - i - 1)
			cout << ", ";
	}
	
	}
	cout << "]\n";
}
Monsters::~Monsters()
{
	for (int i = 0; i < counter; i++)
	{
		delete monsters[i];
	}
}
