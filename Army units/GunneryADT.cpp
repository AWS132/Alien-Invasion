#include "GunneryADT.h"
GunneryADT::GunneryADT()
{
	counter = 0;
}

bool GunneryADT::addUnit(ArmyUnit* newGunnery)
{
	counter++;
	return enqueue(newGunnery);
}

int GunneryADT::getCount()
{
	return counter;
}

ArmyUnit* GunneryADT::pickGunnery()
{
	if(counter>0){
	counter--;               //upadting the counter if it is not empty
	}
	return dequeue();
}
void GunneryADT::printGunnerys()
{
	Node<ArmyUnit*>* ptr = frontPtr;

	cout << "EG " << getCount() << " [";
	while (ptr and ptr->getNext())
	{
		ptr->getItem()->print();
		ptr = ptr->getNext();
		cout << ", ";
	}
	if(ptr)
		ptr->getItem()->print();
	cout << "]\n";
}

GunneryADT::~GunneryADT()
{
	Node<ArmyUnit*>* ptr1 = frontPtr;
	Node<ArmyUnit*>* ptr2 = frontPtr;
	while (ptr1)
	{
		ptr2 = ptr1;
		ptr1 = ptr1->getNext();
		delete ptr2->getItem();
	}
}



