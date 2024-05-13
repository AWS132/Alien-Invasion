#pragma once
#include <iostream>

#include "../Army units/Esoldier.h"
#include "../Army units/genQueueADT.h"
#include "genStackADT.h"
#include "Gunnerys.h"
#include "ArmyUnit.h"
#include "Tank.h"
#include "Gunnery.h"
#include "UML.h"
using namespace std;
class EarthArmy
{
private:

	genQueueADT* es;
	genStackADT* t, * hl;
	Gunnerys* g;
	UML* uml;
	int id;
	int threshold;
	int totalHealed;
public:
	EarthArmy();
	int getId()/*const*/;
	void AddUnit(ArmyUnit* unit/*, bool flag = 1*/);
	void PrintArmy();
	int getCount() const;//returns the total count of the current Earth Army
	int CountOf(unitType ut);
	int countOfInfected();
	int countTotalInf();
	void incHealed();
	int getHealedCount();
	void setThreshold(int);
	bool limitReached();
	ArmyUnit* pickFromUML();
	bool checkID();//returns true if the id is less than 1000
	int getUMLCount();
	bool AddToUML(ArmyUnit* unit);
	~EarthArmy();
	ArmyUnit* pickEUnit(unitType u);
	ArmyUnit* peekEUnit(unitType u);
	ArmyUnit* pickInfUnit();
	void SpreadInfection();
};
