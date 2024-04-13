#include "Asoldiers.h"

Asoldiers::Asoldiers() {
	count = 0;
}
bool Asoldiers::addUnit(ArmyUnit* as)
{
	count++;
	return enqueue(as);
}

void Asoldiers::printAsoldiers()
{
	Node<ArmyUnit*>* temp = frontPtr;
	while (temp != nullptr) {
		temp->getItem()->Print();
		temp = temp->getNext();
	}
}

int Asoldiers::getCount()
{
	return count;
}

ArmyUnit* Asoldiers::pickAsoldiers()
{
	return dequeue();
}
