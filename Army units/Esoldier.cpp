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
	double damage;
	if (flag)
		cout << "ES " << ID << " shoots ";

	int infToAttack=0;
	int AsToAttack;
	if(!infected)//normal ES would attack AS and infected ES
	{
		if (game->getEArmy()->countOfInfected()) {
			if (game->getEArmy()->countOfInfected() >= cap / 2) {
				infToAttack = cap / 2;
			}
			else
				infToAttack = game->getEArmy()->countOfInfected();
		}
		AsToAttack = cap - infToAttack;
			
		for (int i{};i < infToAttack;i++) {//for attacking infected ES
			unit = game->getEArmy()->pickInfUnit();
			if (unit)
			{
				damage = (pwr * hlth / 100) / sqrt(unit->getHealth());
				unit->DecHlth(damage);

				if (unit->getHealth() > 0 && unit->getHealth() < 0.2 * unit->getStartHlth())//if infected ES <20% , add to uml to be healed and be immune
					game->getEArmy()->AddToUML(unit);	//needs to wait in the UML
				else if (unit->getHealth() > 0)
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
		for (int i{};i < AsToAttack;i++) {//for attacking AS
			unit = game->getAArmy()->PickAunit(AS, nl1, nl2);

			if (unit)
			{
				damage = (pwr * hlth / 100) / sqrt(unit->getHealth());
				unit->DecHlth(damage);

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
	}
	else //infected would attack only ES
	{
		for (int i{};i < cap;i++) {
			if (game->getEArmy()->countOfInfected() < game->CountOf(ES))
			{
				while (true)
				{
					unit = game->getEArmy()->pickEUnit(ES);
					if (!unit->getInfectionState())//not infected 
						break;
					else
						game->getEArmy()->AddUnit(unit);
				}
				if (unit)
				{
					damage = (pwr * hlth / 100) / sqrt(unit->getHealth());
					unit->DecHlth(damage);

					if (unit->getHealth() > 0 && unit->getHealth() < 0.2 * unit->getStartHlth())//if infected ES <20% , add to uml to be healed and be immune
						game->getEArmy()->AddToUML(unit);	//needs to wait in the UML
					else if (unit->getHealth() > 0)
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
			else break;
		}
	}
	
	if (flag)
		toBePrinted.printList();

	for (;toBePrinted.pickUnit(););	//to make the "toBePrinted"list empty to save the kldLst from being destructed!!

	while ((unit = lst.pickUnit(), unit))
	{
		game->getEArmy()->AddUnit(unit);
	}
}