#include "Monster.h"

MonsterADT::MonsterADT()
{
	counter = 0;
}
bool MonsterADT::addUnit(ArmyUnit* newMonster)
{
	if (counter < MAX_SIZE)
	{
		monsters[counter++] = newMonster;
		return true;
	}
	return false;
}

int MonsterADT::getCount()
{
	return (counter);
}

ArmyUnit* MonsterADT::pickMonster()
{
	if (counter>0)
	{
		random_device rd;
		mt19937 gen(rd());
		int randomIndex= (gen() % (counter));			//(rand() % (ub - lb + 1)) + lb to generate random index form 0 to counter-1
		ArmyUnit* targetMonster = monsters[randomIndex];
		monsters[randomIndex] = monsters[--counter];
		return targetMonster;
	}
	else
		return nullptr;
}

ArmyUnit* MonsterADT::peekMonster()
{
	if (counter > 0)
	{
		random_device rd;
		mt19937 gen(rd());
		int randomIndex = (gen() % (counter));	//(rand() % (ub - lb + 1)) + lb
		ArmyUnit* targetMonster = monsters[randomIndex];
		
		return targetMonster;
	}
	else
		return nullptr;
}

void MonsterADT::printMonsters()
{
	
	cout << "AM " << getCount() << " [";
	if(counter>0)
	{ 
	for (int i = 0; i < counter; i++)
	{
		monsters[i]->print();
		if (counter - i - 1)
			cout << ", ";
	}
	
	}
	cout << "]\n";
}
MonsterADT::~MonsterADT()
{
	for (int i = 0; i < counter; i++)
	{
		delete monsters[i];
	}
}
