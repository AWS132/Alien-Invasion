#include "Tanks.h"
Tanks::Tanks()
{
}

bool Tanks::addUnit(ArmyUnit* tnk)
{
	if (push(tnk))
	{
		return true;
	}
	else
	{
		return false;
	}
}

ArmyUnit* Tanks::pickTank()
{
	ArmyUnit* tnk = pop();
	return tnk;
}


void Tanks::printTanks()
{
	cout << getCount() << " ET [";
	if(top>1)
	{ 
	for (int i = 0; i < top; i++)
	{
		items[i]->Print();
		cout << ", ";
	}
	}
	if(top>0)
	{ 
	items[top]->Print();
	}
	cout << "]\n";
}

int Tanks::getCount()
{
	return top+1;
}

Tanks::~Tanks()
{
	for (int i = 0; i <=top; i++)
	{
		delete items[i];
	}
}
