#include "UML.h"

UML::UML()
{
	count = 0;
}

bool UML::addUnit(ArmyUnit* Unit)
{
	if (!Unit) return false;
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


int UML::getESCount() const
{
	Node< ArmyUnit*>* ptr = frontPtr;
	int ESCount = 0;
	while (ptr) {
		if (ptr->getItem()->getType() == ES) {
			ESCount++;
		}
		else
			break;
		ptr = ptr->getNext();
	}
	return ESCount;
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