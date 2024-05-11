#pragma once
#include <iostream>

#include "../Army units/Esoldier.h"
#include "../Army units/genQueueADT.h"
#include "Tanks.h"
#include "Gunnerys.h"
#include "ArmyUnit.h"
#include "Tank.h"
#include "Gunnery.h"
#include "UML.h"
using namespace std;
class EarthArmy
{
private:

	genQueueADT* es,*hl;
	Tanks* t;
	Gunnerys* g;
	UML* uml;
	int id;
	int threshold;
public:
	EarthArmy();
	int getId()/*const*/;
	void AddUnit(ArmyUnit* unit/*, bool flag = 1*/);
	void PrintArmy();
	int getCount() const;//returns the total count of the current Earth Army
	int CountOf(unitType ut);
	int countOfInfected();
	void setThreshold(int);
	bool limitReached();
	ArmyUnit* pickFromUML();
	bool AddToUML(ArmyUnit* unit);
	~EarthArmy();
	ArmyUnit* pickEUnit(unitType u);
	ArmyUnit* peekEUnit(unitType u);
	ArmyUnit* pickInfUnit();
	void SpreadInfection();
};
