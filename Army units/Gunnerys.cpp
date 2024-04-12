#include "Gunnerys.h"


Gunnerys::Gunnerys()
{
	counter = 0;
}

//bool Gunnerys::PushGunnery(Army)
//{
//	ArmyUnit* gn = new ArmyUnit(id, EG, tj, health, power, capacity);
//	counter++;
//	return enqueue(gn);
//}
bool Gunnerys::AddGunnery(ArmyUnit* gn)
{
	counter++;
	return enqueue(gn);
}

int Gunnerys::getCount()
{
	return counter;
}

ArmyUnit* Gunnerys::pickGunnery()
{
	counter--;
	return dequeue();
}

void Gunnerys::printGunnery()
{
	Node<ArmyUnit*>* ptr = frontPtr;
	while (ptr)
	{
		ptr->getItem()->Print();
		ptr = ptr->getNext();
	}
}


