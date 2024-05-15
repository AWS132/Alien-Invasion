#include "SU.h"

SU::SU(int id, int tj, int health, int power, int capacity, GameClass* game) :ArmyUnit(id, SU_, tj, health, power, capacity,game)
{
}

void SU::attack(int flag)
{
	GenQueueADT lst;
	double dmg = hlth * pwr / 100.0;
	ArmyUnit* unt = nullptr;
	ArmyUnit* unit = nullptr;
	if (flag)
		cout << "SU " << ID << " Attacks ";
	int tempCap = min(cap, game->countOf(AS) + game->getEArmy()->countOfInfected());
	for (int i = 0; i < tempCap; i++) {
		if (i % 2) {
			unt = game->pickUnit(AS, unit, unit);
		}
		else {
			unt = game->getEArmy()->pickInfUnit();
		}
		if (unt) {
			unt->decHlth(dmg / sqrt(unt->getHealth()));
			lst.addUnit(unt);
		}
		else {
			tempCap++;
		}
	}
	if (flag)
		lst.printList();

	while (lst.getCount())
	{
		ArmyUnit* unt = lst.pickUnit();
		if (unt && unt->getHealth() > 0)
		{
			if (unt->getHealth() < 0.2 * unt->getStartHlth() && unt->getType() == ES)
			{
				game->getEArmy()->AddToUML(unt);
			}
			else
				game->addUnit(unt);
		}
		else
		{
			game->addToKldList(unt);
		}
	}

}
