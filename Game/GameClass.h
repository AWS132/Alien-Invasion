#pragma once
#include "../Army units/EarthArmy.h"
#include "../Army units/AlienArmy.h"
#include "../Game/randGen.h"
#include "../Army units/KilledList.h"
#include "../Army units/tmpList.h"
#include <iostream>
#include <fstream>
using namespace std;
class AlienArmy;
class EarthArmy;
class randGen;
class KilledList;

class GameClass
{
private:
	EarthArmy* EArmy;
	AlienArmy* AArmy;
	randGen* randGenerator;
	KilledList* klst;
	int crntTime;
public:
	GameClass();
	void incrementTime();
	int getTime()const;
	EarthArmy* getEArmy();
	AlienArmy* getAArmy();
	void initializer(int x);
	void pokeUnits();
	void loadData();
	ArmyUnit* PickUnit(unitType unit, ArmyUnit*& d1, ArmyUnit*& d2,int dm=1);
	bool AddToKilledList(ArmyUnit* unit);
	void PrintArmies()const;
	void AddUnit(ArmyUnit*u1);
	void createOFile(int winner);
	void TmpListfn(unitType type,int capacity,int damage);
	int CountOf(unitType ut);
};

