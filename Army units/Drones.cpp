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

bool Drones::CreatDrone(int id, int tj, int health, int power, int capacity)
{
	ArmyUnit* D= new ArmyUnit (id, AD, tj, health, power, capacity);
	count++;
	return enqueue(D);
}

bool Drones::pickDrones(ArmyUnit* D1, ArmyUnit* D2)
{
	if(count<2)
	return false;
	count--;
	dequeue(D2);
	return pop(D1);
}

int Drones::getCount() const
{
	return count;
}

void Drones::printDrones() const
{
	DNode<ArmyUnit*> * temp = frontPtr;
	while (temp!=nullptr) {
		temp->getItem()->Print();
		temp = temp->getNext();
	}

}


