#pragma once
#include <iostream>
#include "../Data Structures/DLinkedQueue.h"
#include "../Army units/ArmyUnit.h"

class Drones :protected DLinkedQueue<ArmyUnit*>
{
	int count;
public:
	Drones();
	//bool CreatDrone(int id, int tj, int health, int power, int capacity);
	bool addUnit(ArmyUnit* D);
	bool pickDrones(ArmyUnit* D1, ArmyUnit*D2);
	int getCount() const;
	void printDrones() const;
};
