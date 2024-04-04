#pragma once
#include <iostream>
#include "../Army units/ArmyUnit.h"
#include "../Data Structures/Pqueue.h"
class Gunnery :public pQueue
{
private:
	int counter;
public:
	Gunnery();
	bool CreatGunnery(int id, int tj, int health, int power, int capacity);
	int getCount();
	ArmyUnit* pickGunnery();
	void printGunnery();
};