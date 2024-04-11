#pragma once
#include <iostream>
#include "Monsters.h"
#include "Drones.h"
#include "soldiers.h"
#include "ArmyUnit.h"
class AlienArmy {
private:
	Monsters* m;
	//solidiers* s;
	Drones* d;
public:
	AlienArmy();
	
	~AlienArmy();
};
