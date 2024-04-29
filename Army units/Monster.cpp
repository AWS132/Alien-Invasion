#include "Monster.h"

Monster::Monster(int id, int tj, int health, int power, int capacity, GameClass* game):ArmyUnit(id, AM, tj, health, power, capacity,game)
{
}

void Monster::Attack() // Attack both ET && ES
{
	tmpList lst;
	int ETtoAttack = cap/2;
	int EStoAttack = cap - ETtoAttack;
    ArmyUnit* nl1 = nullptr;
    ArmyUnit* nl2 = nullptr;
    double damage;
    for (int i = 0; i < ETtoAttack; i++)
    {
       ArmyUnit* unt = game->PickUnit(ET,nl1,nl2);
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

    for (int i = 0; i < EStoAttack; i++)
    {
       ArmyUnit* unt = game->PickUnit(ES,nl1,nl2);
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
