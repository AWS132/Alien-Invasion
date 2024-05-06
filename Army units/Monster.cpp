#include "Monster.h"

Monster::Monster(int id, int tj, int health, int power, int capacity, GameClass* game):ArmyUnit(id, AM, tj, health, power, capacity,game)
{
}

void Monster::Attack(int flag) // Attack both ET && ES
{
	genQueueADT lst;
	int ETtoAttack = cap/2;
	int EStoAttack = cap - ETtoAttack;
    ArmyUnit* nl1 = nullptr;
    ArmyUnit* nl2 = nullptr;
    double damage;
    if (flag)
        cout <<"AM " << ID << " Attacks ";
    for (int i = 0; i < ETtoAttack; i++)
    {
       ArmyUnit* unt = game->PickUnit(ET,nl1,nl2);
       if (unt)
       {
           damage = (pwr * hlth / 100) / sqrt(unt->getHealth());
           unt->DecHlth(damage);
           lst.addUnit(unt);
       }
    }

    for (int i = 0; i < EStoAttack; i++)
    {
       ArmyUnit* unt = game->PickUnit(ES,nl1,nl2);
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
        {
            if (unt->getHealth() < 0.2 * unt->getStartHlth())
                game->getEArmy()->AddToUML(unt);
            else
                game->AddUnit(unt, 0);
        }
        else
        {
            game->AddToKldList(unt);
        }
    }
}
