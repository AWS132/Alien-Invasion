#pragma once
#include <iostream>
#include "../Army units/ArmyUnit.h"
#include "../Data Structures/Pqueue.h"
using namespace std;
class Gunnerys :protected pQueue
{
private:
	int counter;
public:
	Gunnerys();
	bool addUnit(ArmyUnit* gn);
	int getCount();
	ArmyUnit* pickGunnery();
	void printGunnerys();
	~Gunnerys();
};