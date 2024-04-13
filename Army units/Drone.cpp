#pragma once 
#include "Drone.h"
#include <iostream>
#include"ArmyUnit.h"

using namespace std;

Drone::Drone(int id, int tj, int health, int power, int capacity): ArmyUnit(id,AD,tj,health,power,capacity)
{
}

void Drone::Attack(ArmyUnit* opponent)
{
}
