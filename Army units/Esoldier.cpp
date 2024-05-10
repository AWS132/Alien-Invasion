#include "Esoldier.h"

Esoldier::Esoldier(int id, int tj, int health, int power, int capacity, GameClass* game) :ArmyUnit(id, ES, tj, health, power, capacity, game) {

}

void Esoldier::Attack(int flag)
{
	genQueueADT lst;
	genQueueADT toBePrinted;	//to print properly
	int attackCap = cap;
	double power = pwr;
	ArmyUnit* unit = nullptr;
	ArmyUnit* nl1 = nullptr;
	ArmyUnit* nl2 = nullptr;
	if (flag)
		cout << "ES " << ID << " shoots ";


	while (attackCap--)
	{
		if (!infected)  //not infected 
			unit = game->getAArmy()->PickAunit(AS, nl1, nl2);
		else            //infected
			unit = game->getEArmy()->pickEUnit(ES);

		//if ((unit = game->getAArmy()->PickAunit(AS, nl1, nl2), unit))
		if (unit)
		{
			unit->DecHlth(pwr);

			if (unit->getHealth() > 0)
			{
				lst.addUnit(unit);
			}
			else
			{
				game->AddToKldList(unit);
			}
			toBePrinted.addUnit(unit);
		}
	}
	if (flag)
		toBePrinted.printList();

	for (unit = nullptr;toBePrinted.pickUnit(););	//to make the "toBePrinted"list empty to save the kldLst from being destructed!!

	while ((unit = lst.pickUnit(), unit))
	{
		if (unit->getType() == AS)
			game->getAArmy()->AddUnit(unit);
		else
			game->getEArmy()->AddUnit(unit);
	}
}