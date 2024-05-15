#include "Tank.h"

Tank::Tank(int id, int tj, int health, int power, int capacity, GameClass* game) :ArmyUnit(id, ET, tj, health, power, capacity,game)
{
}

void Tank::attack(int flag) //attack monsters
{
    GenQueueADT lst;
    int no_AS = game->countOf(AS);
    int AMtoAttack=min(cap/2, game->countOf(AM));
    int AStoAttack=min(cap- AMtoAttack,game->countOf(AS));
    ArmyUnit* nl1 = nullptr;
    ArmyUnit* nl2 = nullptr;
    double damage;
    int no_ES = game->countOf(ES);
    if (flag)
        cout <<"ET " << ID << " shoots ";
    if((long double)(no_ES*1.0/ no_AS)*100<30)
    { 
        double currPercent = (long double)(no_ES *1.0/ no_AS) * 100;
        for (int i = 0; i < AStoAttack; i++)
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
                no_ES = game->countOf(ES);
                no_AS = game->countOf(AS);
                currPercent = (long double)(no_ES *1.0/ no_AS) * 100;
            }
            else
            {
                AMtoAttack += AStoAttack - (i); // if there are more AS to be attack
                break;
            }
        }
    }
    else
    {
        AMtoAttack = cap;
    }

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
        if (flag)
            lst.printList();
        while (lst.getCount())
        {
            ArmyUnit* unt = lst.pickUnit();
            if (unt && unt->getHealth() > 0)
                game->addUnit(unt);
            else
            {
                game->addToKldList(unt);
            }
        }
}
