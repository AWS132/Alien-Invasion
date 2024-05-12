#pragma once
#include <iostream>
#include "../Data Structures/ArrayStack.h"
#include "../Army units/ArmyUnit.h"   
using namespace std;
class genStackADT :public stack<ArmyUnit*>
{

public:	
	genStackADT();
	bool addUnit(ArmyUnit* unt);
	ArmyUnit* pickUnit();
	void printList();
	int getCount();
	~genStackADT();
};