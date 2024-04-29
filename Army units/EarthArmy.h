#pragma once
#include <iostream>
#include "../Army units/Esoldier.h"
#include "../Army units/Esoldiers.h"
#include "Tanks.h"
#include "Gunnerys.h"
#include "ArmyUnit.h"
#include "Tank.h"
#include "Gunnery.h"
#include "HL.h"
#include "UML.h"
using namespace std;
class EarthArmy
{
private:
	Esoldiers* es;
	Tanks* t;
	Gunnerys* g;
	HL* hl;
	UML* uml;
	int id;
public:
	EarthArmy();
	int getId()const;
	void AddUnit(ArmyUnit* unit, bool flag = 1);
	void PrintArmy();
	int getCount() const;//returns the total count of the current Earth Army
	int CountOf(unitType ut);
	ArmyUnit* pickFromUML();
	bool AddToUML(ArmyUnit* unit);
	~EarthArmy();
	ArmyUnit* pickEUnit(unitType u);
};
