#include "Monster.h"

Monster::Monster(int id, int tj, int health, int power, int capacity, GameClass* game):ArmyUnit(id, AM, tj, health, power, capacity,game)
{
}

void Monster::attack(bool gameMode) // Attack ET , ES , SU
{
	GenQueueADT lst;       //temp list to keep the attacked units
    int infectionPercentage = game->getInfectionPerc(); 
    int divFactor = (game->countOf(SU_)) ? 3 : 2;  // if there is SU monsters will attack 3 types else it will attack only two

                                     /********Number of units to be attacked by the monster********/
    int ETtoAttack = min(cap - min(cap / divFactor, game->countOf(ES)) - min(cap / divFactor, game->countOf(SU_)), game->countOf(ET));
	int EStoAttack = min(cap - ETtoAttack - min(cap / divFactor, game->countOf(SU_)), game->countOf(ES));
    int SUtoAttack = min(cap - ETtoAttack - EStoAttack, game->countOf(SU_));

    //Dummy parameters needed for the pick function
    ArmyUnit* nl1 = nullptr;
    ArmyUnit* nl2 = nullptr;

    double damage;

    if (gameMode)          // print onlt if gameMode is 1 ==>active mode
        cout << "AM " << ID << " Attacks ";

                                /******************Attacking Tanks******************/
    for (int i = 0; i < ETtoAttack; i++)
    {
        ArmyUnit* unt = game->pickUnit(ET, nl1, nl2);
        if (unt)
        {
            damage =  (pwr * hlth / 100) / sqrt(unt->getHealth());
            unt->decHlth(damage);
            lst.addUnit(unt);
        }
    }
                                /******************Attacking SU******************/
    for (int i = 0; i < SUtoAttack; i++)
    {
        ArmyUnit* unt = game->pickUnit(SU_, nl1, nl2);
        if (unt)
        {
            damage = (pwr * hlth / 100) / sqrt(unt->getHealth());
            unt->decHlth(damage);
            lst.addUnit(unt);
        }
    }
                               /******************Attacking soldiers******************/
    random_device rd;
    mt19937 gen(rd());
    for (int i = 0; i < EStoAttack; i++)
    {
        ArmyUnit* unt;
        unt = game->pickUnit(ES,nl1,nl2);
        if (unt)
        {
            damage = (pwr * hlth / 100) / sqrt(unt->getHealth());
            int infectionProb = (gen() % (101));

            //would be attacked if ->not about to be killed ,infcProp ,immune or already infected
            if (/*unt->getHealth() > damage ||*/ infectionProb > infectionPercentage || unt->isImmune() || unt->getInfectionState())
            {
                unt->decHlth(damage);
            }
            else
            {
                unt->becomeInfected();
            }
            lst.addUnit(unt);
        }
    }
    if (gameMode)  
        lst.printList();            //printing the temp list (The attacked units )

    while (lst.getCount())
    {
        ArmyUnit* unt = lst.pickUnit();
        if (unt && unt->getHealth() > 0) // if the unit is alive :)
        {
            if (unt->getHealth() < 0.2 * unt->getStartHlth() && unt->getType() != SU_)  // if seriously damaged 
            {
                game->getEArmy()->addToUML(unt);   // adding the unit to UML to be healed
            }
            else
                game->addUnit(unt);               // adding in back to its list
        }
        else                            // if the unit is killed :(
        {
            game->addToKldList(unt);
        }
    }
    
}
