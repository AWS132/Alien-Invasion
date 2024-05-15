#pragma once
#include "../Army units/EarthArmy.h"
#include "../Army units/AlienArmy.h"
#include "../Army units/AllyArmy.h"
#include "../Game/RandGen.h"
#include "../Army units/GenQueueADT.h"
#include <iostream>
#include <fstream>
using namespace std;
class AlienArmy;
class EarthArmy;
class AllyArmy;
class RandGen;
class GenQueueADT;

class GameClass
{
private:
	EarthArmy* EArmy;
	AlienArmy* AArmy;
	AllyArmy* SArmy;
	RandGen* randGenerator;
	GenQueueADT* klst;
	int crntTime;
public:
	GameClass();
	void incrementTime();
	int getTime()const;
	EarthArmy* getEArmy();
	AlienArmy* getAArmy();
	AllyArmy* getSArmy();
	void initializer(int mode);
	void pokeUnits(int flag);
	bool loadData(int fileName);
	ArmyUnit* pickUnit(unitType unit, ArmyUnit*& d1, ArmyUnit*& d2, int dm = 1);
	bool addToKldList(ArmyUnit* unit);
	void printArmies()const;
	void addUnit(ArmyUnit* u1);
	void createOFile(int winner);
	int countOf(unitType ut);
	int getInfectionPerc();
	~GameClass();
};

