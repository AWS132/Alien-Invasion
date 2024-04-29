#pragma once
#include "../Data Structures/ArrayStack.h"
#include "ArmyUnit.h"
class HL :public stack<ArmyUnit*>
{

public:
	HL();
	bool addUnit(ArmyUnit* Unit);
	ArmyUnit* pickHealer();
	int getCount() const;
	void printHeal();
	~HL();
};