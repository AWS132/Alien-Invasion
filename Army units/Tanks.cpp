#include "Tanks.h"
Tanks::Tanks()
{
	counter = 0;
}

bool Tanks::addUnit(ArmyUnit* tnk)
{
	if (push(tnk))
	{
		counter++;
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
	if (tnk)
	{
		counter--;
	}
	return tnk;
}


void Tanks::printTanks()
{
	cout << counter << " ET [";
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
