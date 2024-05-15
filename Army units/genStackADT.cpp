#include "GenStackADT.h"
GenStackADT::GenStackADT()
{
}

bool GenStackADT::addUnit(ArmyUnit* unt)
{
	if (push(unt))
	{
		return true;
	}
	else
	{
		return false;
	}
}

ArmyUnit* GenStackADT::pickUnit()
{

	ArmyUnit* unt = pop();
	return unt;
}


void GenStackADT::printList()
{
	cout << getCount()<<" [";
	if(top>=0)
	{ 
	for (int i = 0; i <= top; i++)
	{
		items[i]->print();
		if(i-top)
		cout << ", ";
	}
	}
	cout << "]\n";
}

int GenStackADT::getCount()
{
	return top+1;
}

GenStackADT::~GenStackADT()
{
	for (int i = 0; i <=top; i++)
	{
		delete items[i];
	}
}
