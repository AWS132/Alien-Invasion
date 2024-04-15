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

void Monsters::printMonsters()
{
	
	cout << counter<<" AM [";
	if(counter>1)
	{ 
	for (int i = 0; i < counter-1; i++)
	{
		monsters[i]->Print();
		cout<< ", ";
	}
	monsters[counter - 1]->Print();
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
//void Monsters::printMonsters()
//{
//	for (int i = 0; i < counter; i++)
//	{
//		monsters[i]->Print();
//	}
//}
