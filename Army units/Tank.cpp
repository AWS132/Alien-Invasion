#include "Tank.h"

Tank::Tank(int id, int tj, int health, int power, int capacity, GameClass* game) :ArmyUnit(id, ET, tj, health, power, capacity,game)
{
}

void Tank::Attack() //attack monsters
{
     tmpList lst;
    int AMtoAttack = cap;
    ArmyUnit* nl1 = nullptr;
    ArmyUnit* nl2 = nullptr;
    double damage;
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
}
