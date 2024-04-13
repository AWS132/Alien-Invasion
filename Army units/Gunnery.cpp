#include "Gunnery.h"

Gunnery::Gunnery(int id, int tj, int health, int power, int capacity, GameClass* game) :ArmyUnit(id, EG, tj, health, power, capacity,game)
{
}

void Gunnery::Attack(ArmyUnit* opponent)
{
}
