#include "Gunnery.h"

Gunnery::Gunnery(int id, int tj, int health, int power, int capacity, GameClass* game) :ArmyUnit(id, EG, tj, health, power, capacity,game)
{
}

void Gunnery::attack(bool gameMode)  //Attacks drones and monsters
{
    GenQueueADT lst;     //temp list to keep the attacked units
                    /********Number of units to be attacked by the gunnery********/
    int ADtoAttack = min(cap - min(cap / 2, game->countOf(AM)), game->countOf(AD));
    int AMtoAttack =min(cap - ADtoAttack, game->countOf(AM));

    //Dummy parameters needed for the pick function
    ArmyUnit* nl1 = nullptr;
    ArmyUnit* nl2 = nullptr;
    double damage;
    if (gameMode)          // print onlt if gameMode is 1 ==>active mode
        cout <<"EG " << ID << " shoots ";

                      /******************Attacking Drones******************/
        for (int i = 0; i < ADtoAttack;)
        {
            if (i + 1 == ADtoAttack  && ADtoAttack & 1) // if number of drones to attack is odd (at the last iteration) 
            {
                game->pickUnit(AD, nl1, nl2, 0);      //picking one drone
                i++;                                  // increment the counter ==> the last iteration  
                if (nl1)                            
                {
                    damage = (pwr * hlth / 100) / sqrt(nl1->getHealth());
                    nl1->decHlth(damage);
                    lst.addUnit(nl1);
                }
            }
            else                                       // if the number of drones to attack is odd or at any iteration before the last one 
            { 
                game->pickUnit(AD, nl1, nl2);         // picking two drones
                i += 2;                              
                if (nl1)
                {
                    damage = (pwr * hlth / 100) / sqrt(nl1->getHealth());
                    nl1->decHlth(damage);
                    lst.addUnit(nl1);
                } 
                if (nl2)
                {
                    damage = (pwr * hlth / 100) / sqrt(nl2->getHealth());
                    nl2->decHlth(damage);
                    lst.addUnit(nl2);                
                }
            }
        }
                   /******************Attacking monsters******************/
    for (int i = 0; i < AMtoAttack; i++)
    {
        ArmyUnit* unt = game->pickUnit(AM, nl1, nl2);
        if (unt)
        {
            damage = (pwr * hlth / 100) / sqrt(unt->getHealth());
            unt->decHlth(damage);
            lst.addUnit(unt);
        }
    }

    if (gameMode)
        lst.printList();    //printing the temp list (The attacked units )


    while (lst.getCount())
    {
        ArmyUnit* unt = lst.pickUnit();
        if (unt && unt->getHealth() > 0) // if the unit is alive :)
            game->addUnit(unt);
        else                             // if the unit is dead :(
        {
            game->addToKldList(unt);
        }
    }
}
