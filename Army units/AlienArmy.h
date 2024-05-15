#pragma once
#include <iostream>
#include"../Army units/Asoldier.h"
#include"../Army units/GenQueueADT.h"
#include "MonsterADT.h"
#include "Monster.h"
#include "DroneADT.h"
#include "Drone.h"
#include "ArmyUnit.h"
class AlienArmy {
private:
	GenQueueADT* as;
	MonsterADT* m;
	DroneADT* d;
	int id;
public:
	AlienArmy();
	int getId()/*const*/;
	void addUnit(ArmyUnit* unit/*, bool flag=1*/);
	void printArmy();
	bool checkID();
	int getCount() const;
	ArmyUnit* pickAUnit(unitType u,ArmyUnit*& d1, ArmyUnit*& d2,int dm=1);
	ArmyUnit* peekAunit(unitType u,ArmyUnit*& d1, ArmyUnit*& d2);
	int countOf(unitType ut);
	~AlienArmy();
};
