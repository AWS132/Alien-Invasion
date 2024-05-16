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
	bool isConcluded(int&, bool isAttacked);
	void initializer(bool gameMode);//resposible for the game logic
	bool pokeUnits(bool gameMode);	//pokes both aliens and earthers to attack each other
	bool loadData(int fileName);//loads the data from the file
	ArmyUnit* pickUnit(unitType unit, ArmyUnit*& d1, ArmyUnit*& d2, int dm = 1);
	bool addToKldList(ArmyUnit* unit);
	void printArmies()const;
	void addUnit(ArmyUnit* u1);//adds the unit to the appropriate army
	void createOFile(int winner);//creates output file
	int countOf(unitType ut);
	int getInfectionPerc();
	~GameClass();
};

