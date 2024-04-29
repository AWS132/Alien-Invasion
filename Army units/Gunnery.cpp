#include "Gunnery.h"

Gunnery::Gunnery(int id, int tj, int health, int power, int capacity, GameClass* game) :ArmyUnit(id, EG, tj, health, power, capacity,game)
{
}

void Gunnery::Attack() //Attacks drones and monsters
{
    tmpList lst;
    int ADtoAttack = cap / 2;
    int AMtoAttack = cap - ADtoAttack;
 /*   if (ADtoAttack & 1 && AMtoAttack > 1)
    {
        ADtoAttack++;
        AMtoAttack--;
    }*/
    ArmyUnit* nl1 = nullptr;
    ArmyUnit* nl2 = nullptr;
    double damage;
  /*  if ((ADtoAttack & 1) == 0)
    { */
        for (int i = 0; i < ADtoAttack;)
        {
            if (i + 1 == ADtoAttack  && ADtoAttack & 1)
            {
                game->PickUnit(AD, nl1, nl2, 0);
                i++;
                if (nl1)
                {
                    damage = (pwr * hlth / 100) / sqrt(nl1->getHealth());
                    if (nl1->DecHlth(damage))
                    {
                        lst.addUnit(nl1);
                    }
                    else
                    {
                        game->AddToKilledList(nl1);
                    }
                }
            }
            else
            { 

                game->PickUnit(AD, nl1, nl2);
                i += 2;
                if (nl1)
                {
                    damage = (pwr * hlth / 100) / sqrt(nl1->getHealth());
                    if (nl1->DecHlth(damage))
                    {
                        lst.addUnit(nl1);
                    }
                    else
                    {
                        game->AddToKilledList(nl1);
                    }
                } 
                if (nl2)
                {
                    damage = (pwr * hlth / 100) / sqrt(nl2->getHealth());
                    if (nl2->DecHlth(damage))
                    {
                        lst.addUnit(nl2);
                    }
                    else
                    {
                        game->AddToKilledList(nl2);
                    }
                }
            }
        }
    //}
    //else
    //{
    //    for (int i = 0; i < ADtoAttack; i++)
    //    {
    //         game->PickUnit(AD, nl1, nl2,0);
    //        if (nl1)
    //        {
    //            damage = (pwr * hlth / 100) / sqrt(nl1->getHealth());
    //            if (nl1->DecHlth(damage))
    //            {
    //                lst.addUnit(nl1);
    //            }
    //            else
    //            {
    //                game->AddToKilledList(nl1);
    //            }
    //        }
    //    }
    //}
    for (int i = 0; i < AMtoAttack; i++)
    {
        ArmyUnit* unt = game->PickUnit(AM, nl1, nl2);
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
    }


    while (lst.getCount())
    {
        game->AddUnit(lst.PickUnit(),0);
    }
}
