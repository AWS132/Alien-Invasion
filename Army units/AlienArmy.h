#pragma once
#include <iostream>
#include"../Army units/Asoldier.h"
#include"../Army units/genQueueADT.h"
#include "MonsterADT.h"
#include "Monster.h"
#include "Drones.h"
#include "Drone.h"
#include "ArmyUnit.h"
class AlienArmy {
private:
	genQueueADT* as;
	MonsterADT* m;
	Drones* d;
	int id;
public:
	AlienArmy();
	int getId()/*const*/;
	void addUnit(ArmyUnit* unit/*, bool flag=1*/);
	void PrintArmy();
	bool checkID();
	int getCount() const;
	ArmyUnit* pickAUnit(unitType u,ArmyUnit*& d1, ArmyUnit*& d2,int dm=1);
	ArmyUnit* peekAunit(unitType u,ArmyUnit*& d1, ArmyUnit*& d2);
	int countOf(unitType ut);
	~AlienArmy();
};
