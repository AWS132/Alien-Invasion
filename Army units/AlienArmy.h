#pragma once
#include <iostream>
#include"../Army units/Asoldier.h"
#include"../Army units/Asoldiers.h"
#include "Monsters.h"
#include "Monster.h"
#include "Drones.h"
#include "Drone.h"
#include "ArmyUnit.h"
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
	ArmyUnit* PickAunit(unitType u,ArmyUnit*& d1, ArmyUnit*& d2,int dm=1);
	~AlienArmy();
};
