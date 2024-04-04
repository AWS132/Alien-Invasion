#include "Gunnery.h"

Gunnery::Gunnery()
{
	counter = 0;
}

bool Gunnery::CreatGunnery(int id, int tj, int health, int power, int capacity)
{
	ArmyUnit* gn = new ArmyUnit(id, EG, tj, health, power, capacity);
	counter++;
	return enqueue(gn);
}

int Gunnery::getCount()
{
	return counter;
}

ArmyUnit* Gunnery::pickGunnery()
{
	counter--;
	return dequeue();
}

void Gunnery::printGunnery()
{
	Node<ArmyUnit*>* ptr = frontPtr;
	while (ptr)
	{
		ptr->getItem()->Print();
		ptr = ptr->getNext();
	}
}

