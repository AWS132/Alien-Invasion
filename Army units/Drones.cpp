#pragma once 
#include "Drones.h"
#include <iostream>
#include"ArmyUnit.h"
using namespace std;

Drones::Drones(int id, unitType Type, int tj, int health, int power, int capacity): ArmyUnit(id,Type,tj,health,power,capacity)
{
}

void Drones::Attack(ArmyUnit* opponent)
{
//ADD ATTACK LOGIC 
}

void Drones::Print() const
{
	ArmyUnit::Print();
}
