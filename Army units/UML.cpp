#include "UML.h"

UML::UML()
{
	count = 0;
}

bool UML::addUnit(ArmyUnit* Unit)
{
	count++;
	return enqueue(Unit);
}

ArmyUnit* UML::pickUnit()
{
	count--;
	return dequeue();
}

int UML::getCount() const
{
	return count;
}

UML::~UML()
{
	ArmyUnit* x;
	while ((x = dequeue(), x)) {
		if (x) delete x;
	}
}