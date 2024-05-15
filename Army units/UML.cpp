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
	if(count)
		count--;
	return dequeue();
}

int UML::getCount() const
{
	return count;
}

int UML::getTotalInfCount() const
{
	Node< ArmyUnit*>* ptr = frontPtr;
	int infCount = 0;
	while (ptr) {
		if (ptr->getItem()->isImmune()||ptr->getItem()->getInfectionState()) {
			infCount++;
		}
		ptr = ptr->getNext();
	}
	return infCount;
}


void UML::printList()
{
	Node< ArmyUnit*>* ptr = frontPtr;
	cout << "UML " << count << " [";
	while (ptr and ptr->getNext())
	{
		ptr->getItem()->print();
		ptr = ptr->getNext();
		cout << ", ";
	}
	if (ptr)
		ptr->getItem()->print();
	cout << "]\n";

}

UML::~UML()
{
	ArmyUnit* x;
	while ((x = dequeue(), x)) {
		if (x) delete x;
	}
}