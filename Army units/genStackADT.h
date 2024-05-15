#pragma once
#include <iostream>
#include "../Data Structures/ArrayStack.h"
#include "../Army units/ArmyUnit.h"   
using namespace std;
class GenStackADT :public stack<ArmyUnit*>
{

public:	
	GenStackADT();
	bool addUnit(ArmyUnit* unt);
	ArmyUnit* pickUnit();
	void printList();
	int getCount();
	~GenStackADT();
};