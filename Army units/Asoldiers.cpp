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
