#pragma once
#include <iostream>
#include <fstream>
#include "ArmyUnit.h"
#include "../Data Structures/LinkedQueue.h"
using namespace std;
class KilledList:protected LinkedQueue<ArmyUnit*> {
private:
	int count;
public:

	KilledList();
	bool addUnit(ArmyUnit* Unit);
	int getCount() const;
	void printKilled();
	void outKilled(ofstream&,int&, int& , int&,int&,int&,int=0);
	~KilledList();
};