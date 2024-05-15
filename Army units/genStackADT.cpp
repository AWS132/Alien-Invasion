#include "genStackADT.h"
genStackADT::genStackADT()
{
}

bool genStackADT::addUnit(ArmyUnit* unt)
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

ArmyUnit* genStackADT::pickUnit()
{

	ArmyUnit* unt = pop();
	return unt;
}


void genStackADT::printList()
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

int genStackADT::getCount()
{
	return top+1;
}

genStackADT::~genStackADT()
{
	for (int i = 0; i <=top; i++)
	{
		delete items[i];
	}
}
