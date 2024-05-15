#pragma once 
#include "Drones.h"
#include <iostream>
#include"ArmyUnit.h"
#include "..\Data Structures\DNode.h"
using namespace std;

Drones::Drones()
{
	count = 0;
}



bool Drones::addUnit(ArmyUnit* D)
{
	count++;
	return enqueue(D);
}

bool Drones::pickDrones(ArmyUnit*& D1, ArmyUnit*& D2, int dum)
{
	if (count == 0)
		return false;
	count--;
	if (dum&&count)
	{
		pop(D2);
		count--;
	}
	return dequeue(D1);

}

int Drones::getCount() const
{
	return count;
}

void Drones::printDrones() const
{
	DNode<ArmyUnit*> * temp = frontPtr;
	cout << "AD " << getCount() << " [";
	if (!temp) cout << "]\n";
	while (temp!=nullptr) {
		temp->getItem()->print();
		temp = temp->getNext();
		if (temp) cout << ", ";
		else cout << "]\n";
	}
}

Drones::~Drones()
{
	ArmyUnit* x;
	while (dequeue(x)) {
		if (x) delete x;
	}
}


