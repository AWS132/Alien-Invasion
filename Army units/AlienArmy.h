#pragma once
#include <iostream>
#include "Asoldiers.h"
#include "Asoldier.h"
#include "Monsters.h"
#include "Monster.h"
#include "Drones.h"
#include "ArmyUnit.h"
//#include "Drone.h"
class AlienArmy {
private:
	Asoldiers* as;
	Monsters* m;
	Drones* d;
public:
	AlienArmy();
	void AddUnit(ArmyUnit* unit) {
		if (dynamic_cast<Asoldier*>(unit))
			as->addAsoldier(unit);
		else if (dynamic_cast<Monster*>(unit))
			m->addUnit(unit);
		/*else if (dynamic_cast<Drone*>(unit))
			d->addUnit(unit);*/ //waiting for waleed 
	};
	~AlienArmy();
};
