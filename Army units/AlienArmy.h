#pragma once
#include <iostream>
#include "Asoldiers.h"
#include "Asoldier.h"
#include "Monsters.h"
#include "Monster.h"
#include "Drones.h"
#include "Drone.h"
#include "ArmyUnit.h"
//#include "Drone.h"
class AlienArmy {
private:
	Asoldiers* as;
	Monsters* m;
	Drones* d;
	int id;
public:
	AlienArmy();
	int getId()const;
	void AddUnit(ArmyUnit* unit);
	void PrintArmy();
	~AlienArmy();
};
