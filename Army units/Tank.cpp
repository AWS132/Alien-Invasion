#include "Tank.h"

Tank::Tank(int id, int tj, int health, int power, int capacity, GameClass* game) :ArmyUnit(id, ET, tj, health, power, capacity,game)
{
}

void Tank::Attack() //attack monsters
{
    tmpList lst;
    int AMtoAttack = cap / 2;
    int AStoAttack = cap - AMtoAttack;
    ArmyUnit* nl1 = nullptr;
    ArmyUnit* nl2 = nullptr;
    double damage;
    int no_ES = game->CountOf(ES);
    int no_AS = game->CountOf(AS);

    if((long double)(no_ES*1.0/ no_AS)*100<30)
    { 
        double currPercent = (long double)(no_ES *1.0/ no_AS) * 100;
        for (int i = 0; i < AStoAttack; i++)
        {
            if (currPercent < 80)
            {
                ArmyUnit* unt = game->PickUnit(AS, nl1, nl2);
                if (unt)
                {
                    damage = (pwr * hlth / 100) / sqrt(unt->getHealth());
                    if (unt->DecHlth(damage))
                    {
                        lst.addUnit(unt);
                    }
                    else
                    {
                        game->AddToKilledList(unt);
                    }
                }
                no_ES = game->CountOf(ES);
                no_AS = game->CountOf(AS);
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
            ArmyUnit* unt = game->PickUnit(AM, nl1, nl2);
            if (unt)
            {
                damage = (pwr * hlth / 100.0) / sqrt(unt->getHealth());
                if (unt->DecHlth(damage))
                {
                    lst.addUnit(unt);
                }
                else
                {
                    game->AddToKilledList(unt);
                }
            }
        }
        while (lst.getCount())
        {
            game->AddUnit(lst.PickUnit(),0);
        }
}
