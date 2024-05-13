#pragma once
#include <iostream>
#include"../Army units/Asoldier.h"
#include"../Army units/genQueueADT.h"
#include "Monsters.h"
#include "Monster.h"
#include "Drones.h"
#include "Drone.h"
#include "ArmyUnit.h"
class AlienArmy {
private:
	genQueueADT* as;
	Monsters* m;
	Drones* d;
	int id;
public:
	AlienArmy();
	int getId()/*const*/;
	void AddUnit(ArmyUnit* unit/*, bool flag=1*/);
	void PrintArmy();
	bool checkID();
	int getCount() const;
	ArmyUnit* PickAunit(unitType u,ArmyUnit*& d1, ArmyUnit*& d2,int dm=1);
	ArmyUnit* peekAunit(unitType u,ArmyUnit*& d1, ArmyUnit*& d2);
	int CountOf(unitType ut);
	~AlienArmy();
};
