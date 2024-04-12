#pragma once
#include <iostream>
#include "Gunnery.h"
#include "Tanks.h"
#include "Esoldiers.h"
#include "ArmyUnit.h"
class EarthArmy {
private:
	Tanks* t;
	Esoldiers* es;
	Gunnery* g;
public:
	EarthArmy();
	void addUnit(ArmyUnit* unit) {
	};//needs to be moved to .cpp file
	~EarthArmy();
};
