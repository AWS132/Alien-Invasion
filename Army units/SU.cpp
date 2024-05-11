#include "SU.h"

SU::SU(int id, int tj, int health, int power, int capacity, GameClass* game) :ArmyUnit(id, SU_, tj, health, power, capacity,game)
{
}

void SU::Attack(int flag) 
{
	genQueueADT lst;
	double dmg = hlth * pwr / 100.0;
	ArmyUnit* unt = nullptr;
	if (flag)
		cout << "SU " << ID << " Attacks ";
	int tempCap = min(cap, game->CountOf(AS) + game->getEArmy()->countOfInfected());
	for (int i = 0; i < tempCap; i++) {
		if (i % 2) {
			unt = game->getEArmy()->pickEUnit(AS);
		}
		else {
			unt = game->getEArmy()->pickInfUnit();
		}
		if (unt) {
			unt->DecHlth(dmg / sqrt(unt->getHealth()));
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
				game->getEArmy()->AddToUML(unt);
			else
				game->AddUnit(unt);
		}
		else
		{
			game->AddToKldList(unt);
		}
	}

}