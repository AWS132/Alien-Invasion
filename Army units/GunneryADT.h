#pragma once
#include <iostream>
#include "../Army units/ArmyUnit.h"
#include "../Data Structures/Pqueue.h"
using namespace std;
class GunneryADT :public pQueue
{
private:
	int counter;
public:
	GunneryADT();
	bool addUnit(ArmyUnit* gn);
	int getCount();
	ArmyUnit* pickGunnery();
	void printGunnerys();
	~GunneryADT();
};