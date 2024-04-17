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

bool Drones::pickDrones(ArmyUnit*& D1, ArmyUnit*& D2)
{
	bool flag1;
	bool flag2;
	if (count < 2)
		return false;
	flag1 = dequeue(D2);
	flag2 = pop(D1);
	if (flag1)
	{
		count--;
	}
	if (flag2)
	{
		count--;	
	}
	return(flag1 && flag2);
}

int Drones::getCount() const
{
	return count;
}

void Drones::printDrones() const
{
	DNode<ArmyUnit*> * temp = frontPtr;
	cout << count<<" AD [";
	if (!temp) cout << "]\n";
	while (temp!=nullptr) {
		temp->getItem()->Print();
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


