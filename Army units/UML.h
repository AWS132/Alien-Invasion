#pragma once
#include "../Data Structures/priQueue.h"
class UML :public priQueue
{
private:
	int count;
public:
	UML();
	bool addUnit(ArmyUnit* Unit);
	ArmyUnit* pickUnit();
	int getCount() const;
	void printList();
	~UML();
};