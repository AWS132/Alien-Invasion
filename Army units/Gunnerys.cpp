#include "Gunnerys.h"
Gunnerys::Gunnerys()
{
	counter = 0;
}

bool Gunnerys::addUnit(ArmyUnit* gn)
{
	counter++;
	return enqueue(gn);
}

//bool Gunnerys::PushGunnery(Army)
//{
//	ArmyUnit* gn = new ArmyUnit(id, EG, tj, health, power, capacity);
//	counter++;
//	return enqueue(gn);
//}

int Gunnerys::getCount()
{
	return counter;
}

ArmyUnit* Gunnerys::pickGunnery()
{
	counter--;
	return dequeue();
}
void Gunnerys::printGunnerys()
{
	Node<ArmyUnit*>* ptr = frontPtr;

	cout << counter << " EG [";
	while (ptr->getNext())
	{
		ptr->getItem()->Print();
		ptr = ptr->getNext();
		cout << ", ";
	}
	ptr->getItem()->Print();
	cout << "]\n";
}

Gunnerys::~Gunnerys()
{
	//Node<ArmyUnit*>* ptr1 = frontPtr;
	//Node<ArmyUnit*>* ptr2 = frontPtr;
	//while (ptr1)
	//{
	//	ptr2 = ptr1;
	//	ptr1 = ptr1->getNext();
	//	delete ptr2;
	//}
}

//void Gunnerys::printGunnery()
//{
//	Node<ArmyUnit*>* ptr = frontPtr;
//	while (ptr)
//	{
//		ptr->getItem()->Print();
//		ptr = ptr->getNext();
//	}
//}


