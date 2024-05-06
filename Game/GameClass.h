#pragma once
#include "../Army units/EarthArmy.h"
#include "../Army units/AlienArmy.h"
#include "../Game/randGen.h"
#include "../Army units/genQueueADT.h"
#include <iostream>
#include <fstream>
using namespace std;
class AlienArmy;
class EarthArmy;
class randGen;
class genQueueADT;

class GameClass
{
private:
	EarthArmy* EArmy;
	AlienArmy* AArmy;
	randGen* randGenerator;
	genQueueADT* klst;
	int crntTime;
public:
	GameClass();
	void incrementTime();
	int getTime()const;
	EarthArmy* getEArmy();
	AlienArmy* getAArmy();
	void initializer(int x);
	void pokeUnits(int flag);
	void loadData();
	ArmyUnit* PickUnit(unitType unit, ArmyUnit*& d1, ArmyUnit*& d2,int dm=1);
	bool AddToKldList(ArmyUnit* unit);
	void PrintArmies()const;
	void AddUnit(ArmyUnit*u1, bool flag=1);
	void createOFile(int winner);
	int CountOf(unitType ut);
};

