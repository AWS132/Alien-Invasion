#pragma once
#include "../Data Structures/PriQueue.h"
class UML :public PriQueue
{
private:
	int count;
public:
	UML();
	bool addUnit(ArmyUnit* Unit);
	ArmyUnit* pickUnit();
	int getCount() const;
	int getTotalInfCount() const;
	void printList();
	~UML();
};