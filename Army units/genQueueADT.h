#pragma once
#include <iostream>
#include <fstream>
#include "ArmyUnit.h"
#include "../Data Structures/LinkedQueue.h"

using namespace std;
class genQueueADT:public LinkedQueue<ArmyUnit*> {
private:
	int count;
	int InfectedCount;
public:

	genQueueADT();
	bool addUnit(ArmyUnit* Unit);
	int getCount() const;
	int getInfectedCount() const;
	ArmyUnit* pickUnit();
	void printList();
	void outKilled(ofstream&,int&, int& ,int&, int&,int&,int&,int=0);
	void infectRandomly();
	ArmyUnit* pickInfected();
	void destructAll();
	~genQueueADT();
};