#pragma once
#include <iostream>
using namespace std;
#include "../Army units/ArmyUnit.h"
class Monsters 
{
	enum { MAX_SIZE = 1000 };
protected:
	ArmyUnit* monsters[MAX_SIZE];
	int counter;
public:
	Monsters();
	//bool CreatMonster(int id, int tj, int health, int power, int capacity);
	bool addUnit(ArmyUnit* mns);
	int getCount();
	ArmyUnit* pickMonster();
	void printMonsters();
	~Monsters();
};