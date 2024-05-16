#include "Tank.h"

Tank::Tank(int id, int tj, int health, int power, int capacity, GameClass* game) :ArmyUnit(id, ET, tj, health, power, capacity,game)
{
}

void Tank::attack(bool gameMode)  // Attack AM , AS (sometimes)
{
    GenQueueADT lst;             //temp list to keep the attacked units

                               /********Number of units to be attacked by the tank********/
    // at the beginning assume The tank will attack monster and soldiers 
    int AMtoAttack=min(cap/2, game->countOf(AM));
    int AStoAttack=min(cap- AMtoAttack,game->countOf(AS));

    //Dummy parameters needed for the pick function
    ArmyUnit* nl1 = nullptr;
    ArmyUnit* nl2 = nullptr;
    double damage;

    int no_AS = game->countOf(AS);
    int no_ES = game->countOf(ES);

    if (gameMode)               // print onlt if gameMode is 1 ==>active mode
        cout <<"ET " << ID << " shoots ";


                                    /******************Attacking Alien Soldiers******************/

    if((long double)(no_ES*1.0/ no_AS)*100<30)     // if earth soldiers are seriously less than alien soldiers
    { 
        double currPercent = (long double)(no_ES *1.0/ no_AS) * 100;  // percentage of ES/AS
        for (int i = 0; i < AStoAttack; i++)      // this attack will end if finished AStoAttack or currPercent became more than 80
        {
            if (currPercent < 80)                                     
            {
                ArmyUnit* unt = game->pickUnit(AS, nl1, nl2);
                if (unt)
                {
                    damage = (pwr * hlth / 100) / sqrt(unt->getHealth());
                    unt->decHlth(damage);
                    lst.addUnit(unt);
                }
                // updating the no_AS
                no_AS = game->countOf(AS);
                currPercent = (long double)(no_ES *1.0/ no_AS) * 100;
            }
            else
            {
                AMtoAttack += AStoAttack - (i); // if there are more AS to be attack but the currPercent is more than 80
                break;
            }
        }
    }
    else
    {
        AMtoAttack = min(cap,game->countOf(AM)); // the tank will only attack the the monsters 
    }

                               /******************Attacking Monsters******************/
        for (int i = 0; i < AMtoAttack; i++)
        {
            ArmyUnit* unt = game->pickUnit(AM, nl1, nl2);
            if (unt)
            {
                damage = (pwr * hlth / 100.0) / sqrt(unt->getHealth());
                unt->decHlth(damage);
                 lst.addUnit(unt);
            }
        }

        if (gameMode)
            lst.printList();        //printing the temp list (The attacked units )

        while (lst.getCount())
        {
            ArmyUnit* unt = lst.pickUnit();
            if (unt && unt->getHealth() > 0) // if the unit is alive :)
                game->addUnit(unt);
            else                             // if the unit is alive :)
            {
                game->addToKldList(unt);
            }
        }
}
