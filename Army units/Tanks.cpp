#include "Tanks.h"
//bool Tanks::CreatTank(int id, int tj, int health, int power, int capacity)
//{
//	ArmyUnit* tnk = new ArmyUnit(id,ET,tj,health,power,capacity);
//	return push(tnk);
//}

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
/*void Tanks::printTanks()
{
	for (int i = 0; i <= top; i++)
	{
		items[i]->Print();
	}
}*/

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
