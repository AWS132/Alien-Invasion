#include "HU.h"

HU::HU(int id, int tj, int health, int power, int capacity, GameClass* game) :ArmyUnit(id, HU_, tj, health, power, capacity, game) {}

void HU::attack(int flag)
{
	GenQueueADT lst;
	int attackCap = cap;
	ArmyUnit* unit = nullptr;
	GenQueueADT toBePrinted;	//to print properly
	if (flag)
		cout << "HU " << ID << " Heals ";
	while (attackCap--) {
		if ((unit = game->getEArmy()->pickFromUML(), unit))
		{
			int tjUML = unit->getTjUML();
			if (game->getTime() - tjUML > 10) {
				unit->decHlth(unit->getHealth());
				game->addToKldList(unit);
			}
			else
			{
				if (unit->getInfectionState())//divided by 2 to take double the time
				{
					if (unit->incHlth((pwr * hlth) / 2))	//returns true if health is over than 20% of start health
					{//if true => would be immune ;)
						unit->becomeImmune();
						game->getEArmy()->addUnit(unit);
						game->getEArmy()->incHealed();
					}
					else
						lst.addUnit(unit);

				}
				else if (unit->incHlth((pwr * hlth))) {	//returns true if health is over than 20% of start health
					game->getEArmy()->addUnit(unit);
					game->getEArmy()->incHealed();
				}
				else {
					lst.addUnit(unit);
				}
				toBePrinted.addUnit(unit);//to be printed anyway
			}
		}
	}
	if(flag)//if added to killedLst, it didn't get healed (no need to print it)
		toBePrinted.printList();

	if(!toBePrinted.isEmpty())
	{
		game->getEArmy()->pickEUnit(HU_);
		this->decHlth(this->getHealth());
		game->addToKldList(this);	//killing the HU
	}
	for (;toBePrinted.pickUnit(););	//to make the "toBePrinted" list empty to save the kldLst from being destructed!!

	while ((unit = lst.pickUnit(), unit))
	{
		game->getEArmy()->AddToUML(unit);
	}


	/*while (lst.getCount()) {
		if (unit = lst.PickUnit(), unit) {
			int ta = unit->getTa();
			if (game->getTime() - ta > 10)
				game->addToKldList(unit);
			else
				game->getEArmy()->AddToUML(unit);

		}
	}*/
};
