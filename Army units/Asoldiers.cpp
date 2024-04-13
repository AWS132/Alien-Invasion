#include "Asoldiers.h"

Asoldiers::Asoldiers() {
	count = 0;
}
bool Asoldiers::addUnit(ArmyUnit* as)
{
	count++;
	return enqueue(as);
}

int Asoldiers::getCount()
{
	return count;
}

Asoldiers::~Asoldiers()
{
	ArmyUnit* x;
	while (dequeue(x)) {
		if (x) delete x;
	}
}

ArmyUnit* Asoldiers::pickAsoldiers()
{
	if (!count)
		return nullptr;
	count--;
	ArmyUnit* as;
	dequeue(as);
	return as;
}

void Asoldiers::printAsoldiers()
{
	Node<ArmyUnit*>* ptr = frontPtr;

	cout << count << " AS [";
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
