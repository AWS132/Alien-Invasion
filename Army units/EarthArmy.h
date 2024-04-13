#pragma once
#include <iostream>
#include "Esoldiers.h"
#include "Tanks.h"
#include "Gunnerys.h"
#include "ArmyUnit.h"
#include "Esoldier.h"
#include "Tank.h"
#include "Gunnery.h"
class EarthArmy {
private:
	Esoldiers* es;
	Tanks* t;
	Gunnerys* g;
public:
	EarthArmy();
	void AddUnit(ArmyUnit* unit) {
		if (dynamic_cast<Esoldier*>(unit))
			es->addEsoldier(unit);
		else if (dynamic_cast<Tank*>(unit))
			t->addUnit(unit);
		else if (dynamic_cast<Gunnery*>(unit))
			g->addUnit(unit);
	};//needs to be moved to .cpp file
	~EarthArmy();
};
