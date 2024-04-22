#include "Gunnery.h"

Gunnery::Gunnery(int id, int tj, int health, int power, int capacity, GameClass* game) :ArmyUnit(id, EG, tj, health, power, capacity,game)
{
}

void Gunnery::Attack() //Attacks drones and monsters
{
    tmpList lst;
    int ADtoAttack = cap / 2;
    int AMtoAttack = cap - ADtoAttack;
    if (ADtoAttack & 1 && AMtoAttack > 1)
    {
        ADtoAttack++;
        AMtoAttack--;
    }
    ArmyUnit* nl1 = nullptr;
    ArmyUnit* nl2 = nullptr;
    double damage;
    if ((ADtoAttack & 1) == 0)
    { 
        for (int i = 0; i < ADtoAttack/2; i++)
        {
            ArmyUnit* unt = game->PickUnit(AD, nl1, nl2);
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
    }
    else
    {
        for (int i = 0; i < ADtoAttack; i++)
        {
            ArmyUnit* unt = game->PickUnit(AD, nl1, nl2,0);
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
    }
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
        game->AddUnit(lst.PickUnit());
    }
}
