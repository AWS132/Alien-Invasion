#pragma once 
#include "DroneADT.h"
#include <iostream>
#include"ArmyUnit.h"
#include "..\Data Structures\DNode.h"
using namespace std;

DroneADT::DroneADT()
{
	count = 0;
}



bool DroneADT::addUnit(ArmyUnit* D)
{
	count++;
	return enqueue(D);
}

bool DroneADT::pickDrones(ArmyUnit*& D1, ArmyUnit*& D2, int dum)
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

int DroneADT::getCount() const
{
	return count;
}

void DroneADT::printDrones() const
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

DroneADT::~DroneADT()
{
	ArmyUnit* x;
	while (dequeue(x)) {
		if (x) delete x;
	}
}


