#include "Esoldier.h"

Esoldier::Esoldier(int id, int tj, int health, int power, int capacity, GameClass* game) :ArmyUnit(id, ES, tj, health, power, capacity, game) {

}

bool Esoldier::attack(bool gameMode)
{
	GenQueueADT lst;
	GenQueueADT toBePrinted;	//to print properly
	int attackCap = cap;
	double power = pwr;
	ArmyUnit* unit = nullptr;
	ArmyUnit* nl1 = nullptr;
	ArmyUnit* nl2 = nullptr;
	double damage;
	if (gameMode) {
		cout << "ES ";
		this->print();
		cout<< " shoots ";
	}
	int infToAttack = min(cap - min(cap / 2, game->getAArmy()->countOf(AS)), game->getEArmy()->countOfInfected());
	int AsToAttack = min(cap - infToAttack, game->getAArmy()->countOf(AS));

	if (!infected)//normal ES would attack AS and infected ES
	{
		for (int i{}; i < infToAttack; i++) {//for attacking infected ES
			unit = game->getEArmy()->pickInfUnit();
			if (unit)
			{
				damage = (pwr * hlth / 100) / sqrt(unit->getHealth());
				unit->decHlth(damage);

				if (unit->getHealth() > 0 && unit->getHealth() < 0.2 * unit->getStartHlth())//if infected ES <20% , add to uml to be healed and be immune
				{
					game->getEArmy()->addToUML(unit);	//needs to wait in the UML
				}
				else if (unit->getHealth() > 0)
				{
					lst.addUnit(unit);
				}
				else
				{
					game->addToKldList(unit);
				}
				toBePrinted.addUnit(unit);
			}
		}
		for (int i{}; i < AsToAttack; i++) {//for attacking AS
			unit = game->getAArmy()->pickAUnit(AS, nl1, nl2);

			if (unit)
			{
				damage = (pwr * hlth / 100) / sqrt(unit->getHealth());
				unit->decHlth(damage);

				if (unit->getHealth() > 0)
				{
					lst.addUnit(unit);
				}
				else
				{
					game->addToKldList(unit);
				}
				toBePrinted.addUnit(unit);
			}
		}
	}
	else //infected would attack only ES & SU
	{
		ArmyUnit* dummy = nullptr;
		int tempCap = min(cap, game->countOf(SU_) + game->countOf(ES) - game->getEArmy()->countOfInfected());//to determine the capacity correctly
		for (int i{}; i < tempCap; i++) {
			if (i % 2 && game->getEArmy()->countOfInfected() < game->countOf(ES))
			{
				while (true)
				{
					unit = game->pickUnit(ES, dummy, dummy);
					if (!unit->getInfectionState())//not infected 
						break;
					else
						game->addUnit(unit);
				}

			}
			else {
				
				unit = game->pickUnit(SU_, dummy, dummy);
			}
			if (unit)
			{
				damage = (pwr * hlth / 100) / sqrt(unit->getHealth());
				unit->decHlth(damage);

				if (unit->getType() == ES && unit->getHealth() > 0 && unit->getHealth() < 0.2 * unit->getStartHlth())//if infected ES <20% , add to uml to be healed and be immune
				{
					game->getEArmy()->addToUML(unit);	//needs to wait in the UML
				}
				else if (unit->getHealth() > 0)
				{
					lst.addUnit(unit);
				}
				else
				{
					game->addToKldList(unit);
				}
				toBePrinted.addUnit(unit);
			}
			else {
				tempCap++;
			}
		}
	}
		if (gameMode)
			toBePrinted.printList();
		bool occurred = !toBePrinted.isEmpty();
		for (; toBePrinted.pickUnit(););	//to make the "toBePrinted"list empty to save the kldLst from being destructed!!

		while ((unit = lst.pickUnit(), unit))
		{
			game->addUnit(unit);
		}
		return occurred;
}