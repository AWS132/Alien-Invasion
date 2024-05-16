#pragma once
#include <iostream>
#include "../Army units/Esoldier.h"
#include "../Army units/GenQueueADT.h"
#include "GenStackADT.h"
#include "GunneryADT.h"
#include "ArmyUnit.h"
#include "Tank.h"
#include "Gunnery.h"
#include "UML.h"
using namespace std;
class EarthArmy
{
private:

	GenQueueADT* es;
	GenStackADT* t, * hl;
	GunneryADT* g;
	UML* uml;
	int id;
	int threshold;
	int totalHealed;
public:
	EarthArmy();
	int getId();
	void addUnit(ArmyUnit* unit);
	void printArmy();
	int getCount() const;//returns the total count of the current Earth Army
	int countOf(unitType ut);
	int countOfInfected();
	int countTotalInf();
	void incHealed();
	int getHealedCount();
	void setThreshold(int);
	bool limitReached();
	ArmyUnit* pickFromUML();
	bool checkID();//returns true if the id is less than 1000
	int getUMLCount();
	bool addToUML(ArmyUnit* unit);
	~EarthArmy();
	ArmyUnit* pickEUnit(unitType u);
	ArmyUnit* peekEUnit(unitType u);
	ArmyUnit* pickInfUnit();
	void spreadInfection();
};