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

void UML::printList()
{
	Node< ArmyUnit*>* ptr = frontPtr;
	cout << "UML " << count << " [";
	while (ptr and ptr->getNext())
	{
		ptr->getItem()->Print();
		ptr = ptr->getNext();
		cout << ", ";
	}
	if (ptr)
		ptr->getItem()->Print();
	cout << "]\n";

}

UML::~UML()
{
	ArmyUnit* x;
	while ((x = dequeue(), x)) {
		if (x) delete x;
	}
}