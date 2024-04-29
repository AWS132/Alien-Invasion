#include "HU.h"

HU::HU(int id, int tj, int health, int power, int capacity, GameClass* game) :ArmyUnit(id, HU_, tj, health, power, capacity, game) {}

void HU::Attack()
{
	tmpList lst;
	int attackCap = cap;
	ArmyUnit* unit = nullptr;

	while (attackCap--) {
		if ((unit = game->getEArmy()->pickFromUML(), unit))
		{
			int ta = unit->getTa();
			if (game->getTime() - ta > 10)
				game->AddToKilledList(unit);
			else {
				if (unit->IncHlth((pwr * hlth))) {//returns true if health is over than 20% of start health
					game->getEArmy()->AddUnit(unit);
				}
				else {
					lst.addUnit(unit);
				}
			}
		}
	}
	unit = nullptr;
	while ((unit = lst.PickUnit(), unit))
		game->getEArmy()->AddToUML(unit);
};
