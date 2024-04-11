#pragma once
#include <iostream>
#include "Gunnery.h"
#include "Tanks.h"
#include "soldiers.h"
#include "ArmyUnit.h"
class EarthArmy {
private:
	Tanks* t;
	//solidiers* s;
	Gunnery* g;
public:
	EarthArmy();
	~EarthArmy();
};
