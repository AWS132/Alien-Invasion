#pragma once
#include <iostream>
#include "ArmyUnit.h"
class Drones: public ArmyUnit {
public:
	Drones(int id, unitType Type, int tj, int health, int power, int capacity);
	virtual void Attack(ArmyUnit* opponent);
	virtual void Print() const;

};
