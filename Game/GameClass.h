#pragma once
#include "../Army units/EarthArmy.h"
#include "../Army units/AlienArmy.h"
#include "../Army units/allyArmy.h"
#include "../Game/randGen.h"
#include "../Army units/genQueueADT.h"
#include <iostream>
#include <fstream>
using namespace std;
class AlienArmy;
class EarthArmy;
class allyArmy;
class randGen;
class genQueueADT;

class GameClass
{
private:
	EarthArmy* EArmy;
	AlienArmy* AArmy;
	allyArmy* SArmy;
	randGen* randGenerator;
	genQueueADT* klst;
	int crntTime;
public:
	GameClass();
	void incrementTime();
	int getTime()const;
	EarthArmy* getEArmy();
	AlienArmy* getAArmy();
	allyArmy* getSArmy();
	void initializer(int mode,int fileName);
	void pokeUnits(int flag);
	void loadData(int fileName);
	ArmyUnit* PickUnit(unitType unit, ArmyUnit*& d1, ArmyUnit*& d2,int dm=1);
	bool AddToKldList(ArmyUnit* unit);
	void PrintArmies()const;
	void AddUnit(ArmyUnit*u1);
	void createOFile(int winner);
	int CountOf(unitType ut);
	int getInfection_perc();
};

