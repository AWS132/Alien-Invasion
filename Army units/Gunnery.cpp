#include "Gunnery.h"

Gunnery::Gunnery(int id, int tj, int health, int power, int capacity, GameClass* game) :ArmyUnit(id, EG, tj, health, power, capacity,game)
{
}

void Gunnery::Attack(int flag) //Attacks drones and monsters
{
    genQueueADT lst;
    int ADtoAttack =min(cap/2,game->CountOf(AD));
    int AMtoAttack =min(cap - ADtoAttack, game->CountOf(AM));
    ArmyUnit* nl1 = nullptr;
    ArmyUnit* nl2 = nullptr;
    double damage;
    if (flag)
        cout <<"EG " << ID << " shoots ";

        for (int i = 0; i < ADtoAttack;)
        {
            if (i + 1 == ADtoAttack  && ADtoAttack & 1)
            {
                game->PickUnit(AD, nl1, nl2, 0);
                i++;
                if (nl1)
                {
                    damage = (pwr * hlth / 100) / sqrt(nl1->getHealth());
                    nl1->DecHlth(damage);
                    lst.addUnit(nl1);
                }
            }
            else
            { 
                game->PickUnit(AD, nl1, nl2);
                i += 2;
                if (nl1)
                {
                    damage = (pwr * hlth / 100) / sqrt(nl1->getHealth());
                    nl1->DecHlth(damage);
                    lst.addUnit(nl1);
                } 
                if (nl2)
                {
                    damage = (pwr * hlth / 100) / sqrt(nl2->getHealth());
                    nl2->DecHlth(damage);
                    lst.addUnit(nl2);                
                }
            }
        }
    for (int i = 0; i < AMtoAttack; i++)
    {
        ArmyUnit* unt = game->PickUnit(AM, nl1, nl2);
        if (unt)
        {
            damage = (pwr * hlth / 100) / sqrt(unt->getHealth());
            unt->DecHlth(damage);
            lst.addUnit(unt);
        }
    }

    if (flag)
        lst.printList();
    while (lst.getCount())
    {
        ArmyUnit* unt = lst.pickUnit();
        if (unt && unt->getHealth() > 0)
            game->AddUnit(unt);
        else
        {
            game->AddToKldList(unt);
        }
    }
}
