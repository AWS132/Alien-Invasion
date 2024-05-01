#include "Asoldier.h"

Asoldier::Asoldier(int id, int tj, int health, int power, int capacity, GameClass* game) :ArmyUnit(id, AS, tj, health, power, capacity,game)
{
}

void Asoldier::Attack(int flag)
{
	tmpList lst;
	tmpList toBePrinted;	//to print properly
	int attackCap = cap;
	double power = pwr;
	
	ArmyUnit* unit = nullptr;
	if (flag)
		cout << "AS " << ID << " shots ";

	while (attackCap--) {
		if ((unit = game->getEArmy()->pickEUnit(ES), unit)) {
			unit->DecHlth(pwr);
			unit->setTa(game->getTime());
			if (unit->getHealth() > 0 && unit->getHealth() < 0.2 * unit->getStartHlth())
				game->getEArmy()->AddToUML(unit);	//needs to wait in the UML
			else if(unit->getHealth() > 0)
			{
				lst.addUnit(unit);	//ready to rejoin the battle
			}
			else {	//dead
				game->AddToKilledList(unit);
				unit->setTd(game->getTime());
			}
			toBePrinted.addUnit(unit);//to be printed anyway (damaged > 80%,alive,dead)
		}
	}
	if (flag)
		toBePrinted.printTmpList();

	for (;toBePrinted.PickUnit(););	//to make the "toBePrinted" list empty to save the kldLst from being destructed!!

	unit = nullptr;
	while ((unit = lst.PickUnit(), unit))//if ES reached this stage, its health would be > 20% * startHealth. So it's able to join the battle again
		game->getEArmy()->AddUnit(unit);
}
