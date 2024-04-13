#pragma once
#include <iostream>
#include "Esoldiers.h"
#include "Tanks.h"
#include "Gunnerys.h"
#include "ArmyUnit.h"
#include "Esoldier.h"
#include "Tank.h"
#include "Gunnery.h"
using namespace std;
class EarthArmy {
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
};