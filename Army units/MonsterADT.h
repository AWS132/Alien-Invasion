#pragma once
#include <iostream>
#include <random>
#include <time.h>
#include "../Army units/ArmyUnit.h"
using namespace std;
class MonsterADT
{
	enum { MAX_SIZE = 1000 };		// The max size of the array
protected:
	ArmyUnit* monsters[MAX_SIZE];
	int counter;
public:
	MonsterADT();
	bool addUnit(ArmyUnit* newMonster);
	int getCount();
	ArmyUnit* pickMonster();
	ArmyUnit* peekMonster();
	void printMonsters();
	~MonsterADT();
};