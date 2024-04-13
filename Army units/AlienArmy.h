#pragma once
#include <iostream>
#include"../Army units/Asoldier.h"
#include"../Army units/Asoldiers.h"
#include "../Army units/Monsters.h"
#include "../Army units/Monster.h"
#include "../Army units/Drones.h"
#include "../Army units/Drone.h"
#include "../Army units/ArmyUnit.h"
class Asoldiers;
class Monsters;
class Drones;
class AlienArmy 
{
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
