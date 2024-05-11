#include "Monster.h"

Monster::Monster(int id, int tj, int health, int power, int capacity, GameClass* game):ArmyUnit(id, AM, tj, health, power, capacity,game)
{
}

void Monster::Attack(int flag) // Attack both ET && ES
{
	genQueueADT lst;
    int infection_Percentage = game->getInfection_perc();
	int ETtoAttack = cap/2;
	int EStoAttack = cap - ETtoAttack;
    ArmyUnit* nl1 = nullptr;
    ArmyUnit* nl2 = nullptr;
    double damage;

    if (flag)
        cout << "AM " << ID << " Attacks ";
    for (int i = 0; i < ETtoAttack; i++)
    {
        ArmyUnit* unt = game->PickUnit(ET, nl1, nl2);
        if (unt)
        {
            damage = (pwr * hlth / 100) / sqrt(unt->getHealth());
            unt->DecHlth(damage);
            lst.addUnit(unt);
        }
    }
    random_device rd;
    mt19937 gen(rd());
    for (int i = 0; i < EStoAttack; i++)
    {
        ArmyUnit* unt;
        if (game->getEArmy()->countOfInfected() < game->CountOf(ES))
        {
            while (true)
            {
                unt = game->getEArmy()->pickEUnit(ES);
                if (unt && !unt->getInfectionState())//not infected 
                    break;
                else
                    game->getEArmy()->AddUnit(unt);
            }
            if (unt)
            {
                damage = (pwr * hlth / 100) / sqrt(unt->getHealth());
                int infectionProb = (gen() % (101));
                if (unt->getHealth() > damage || infectionProb > infection_Percentage || unt->isImmune())
                {
                    unt->DecHlth(damage);
                }
                else
                {
                    unt->become_infected();
                }
                lst.addUnit(unt);
            }
        }
        else break;
    }
    if (flag)
        lst.printList();

    while (lst.getCount())
    {
        ArmyUnit* unt = lst.pickUnit();
        if (unt && unt->getHealth() > 0)
        {
            /*if (unt->getHealth() < 0.2 * unt->getStartHlth())
                game->getEArmy()->AddToUML(unt);*/
            if (unt->getHealth() < 0.2)
                game->AddUnit(unt/*,0*/);
        }
        else
        {
            game->AddToKldList(unt);
        }
    }
    
}
