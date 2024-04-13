#pragma once
#include <iostream>
#include "../Army units/Esoldier.h"
#include "../Army units/Esoldiers.h"
#include "Tanks.h"
#include "Gunnerys.h"
#include "ArmyUnit.h"
#include "Tank.h"
#include "Gunnery.h"
using namespace std;
class Tanks;
class Esoldiers;
class Gunnerys;
class EarthArmy
{
private:
	Esoldiers* es;
	Tanks* t;
	Gunnerys* g;
	int id;
public:
	EarthArmy();
	int getId()const;
	void AddUnit(ArmyUnit* unit);
	void PrintArmy();
	~EarthArmy();
	ArmyUnit* pickEUnit(unitType u);
};
