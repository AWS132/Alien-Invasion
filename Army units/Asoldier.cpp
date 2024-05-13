#include "Asoldier.h"

Asoldier::Asoldier(int id, int tj, int health, int power, int capacity, GameClass* game) :ArmyUnit(id, AS, tj, health, power, capacity,game)
{
}

void Asoldier::Attack(int flag)
{
	genQueueADT lst;
	genQueueADT toBePrinted;	//to print properly
	
	int SUCap = min(cap - min(cap / 2, (game->CountOf(ES) - game->getEArmy()->countOfInfected())), game->CountOf(SU_));
	int ESCap = min(cap - SUCap, (game->CountOf(ES) - game->getEArmy()->countOfInfected()));
	double power = pwr;
	double damage;
	ArmyUnit* unit = nullptr;
	ArmyUnit* dummy = nullptr;
	if (flag)
		cout << "AS " << ID << " shoots ";
	for (int i = 0; i < SUCap; i++)
	{
		ArmyUnit* unt = game->PickUnit(SU_, unit, unit);		

		if (unt)
		{
			damage = (pwr * hlth / 100) / sqrt(unt->getHealth());
			unt->DecHlth(damage);
			if (unt->getHealth() > 0)
			{
				lst.addUnit(unt);	//ready to rejoin the battle
			}
			else {	//dead
				game->AddToKldList(unt);

			}
			toBePrinted.addUnit(unt);
		}
	}
	while (ESCap--) {
		unit = game->PickUnit(ES, dummy, dummy);
		if (unit) {
			damage = (pwr * hlth / 100) / sqrt(unit->getHealth());
			unit->DecHlth(damage);

			if (unit->getHealth() > 0 && unit->getHealth() < 0.2 * unit->getStartHlth())
			{
				unit->setTjUML(game->getTime());	//setting the time that the unit joined the UML
				game->getEArmy()->AddToUML(unit);	//needs to wait in the UML
			}
			else if (unit->getHealth() > 0)
			{
				lst.addUnit(unit);	//ready to rejoin the battle
			}
			else {	//dead
				game->AddToKldList(unit);

			}
			toBePrinted.addUnit(unit);//to be printed anyway (damaged > 80%,alive,dead)
		}

	}
	if (flag)
		toBePrinted.printList();

	for (;toBePrinted.pickUnit(););	//to make the "toBePrinted" list empty to save the kldLst from being destructed!!

	unit = nullptr;
	while ((unit = lst.pickUnit(), unit))//if ES reached this stage, its health would be > 20% * startHealth. So it's able to join the battle again
		game->AddUnit(unit);
}
