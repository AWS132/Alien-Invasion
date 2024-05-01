#include "Esoldier.h"

Esoldier::Esoldier(int id, int tj, int health, int power, int capacity, GameClass* game) :ArmyUnit(id, ES, tj, health, power, capacity, game) {

}

void Esoldier::Attack(int flag)
{
	tmpList lst;
	tmpList toBePrinted;	//to print properly
	int attackCap = cap;
	double power = pwr;
	ArmyUnit* unit = nullptr;
	ArmyUnit* nl1 = nullptr;
	ArmyUnit* nl2 = nullptr;
	if (flag)
		cout << "ES " << ID << " shots ";

	while (attackCap--) {
		if ((unit=game->getAArmy()->PickAunit(AS, nl1, nl2), unit)) {
			unit->DecHlth(pwr);
			unit->setTa(game->getTime());
			if (unit->getHealth() > 0)
			{
				lst.addUnit(unit);
			}
			else {
				game->AddToKilledList(unit);
				unit->setTd(game->getTime());

			}
				toBePrinted.addUnit(unit);
		}
	}
	if (flag)
		toBePrinted.printTmpList();

	for (unit = nullptr;toBePrinted.PickUnit(););	//to make the "toBePrinted"list empty to save the kldLst from being destructed!!

	while ((unit = lst.PickUnit(), unit))
		game->getAArmy()->AddUnit(unit);
}
