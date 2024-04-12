#pragma once
#include <iostream>
#include "../Army units/ArmyUnit.h"
#include "../Data Structures/Pqueue.h"
class Gunnerys :public pQueue
{
private:
	int counter;
public:
	Gunnerys();
	bool AddGunnery(ArmyUnit* gn);
	int getCount();
	ArmyUnit* pickGunnery();
	void printGunnery();
};