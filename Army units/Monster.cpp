#include "Monster.h"

Monster::Monster(int id, int tj, int health, int power, int capacity, GameClass* game):ArmyUnit(id, AM, tj, health, power, capacity,game)
{
}

void Monster::Attack(int flag) // Attack both ET && ES
{
	genQueueADT lst;
    int infection_Percentage = game->getInfection_perc();
    int divFactor = (game->CountOf(SU_)) ? 3 : 2;
    int ETtoAttack = min(cap - min(cap / divFactor, game->CountOf(ES)) - min(cap / divFactor, game->CountOf(SU_)), game->CountOf(ET));
	int EStoAttack = min(cap - ETtoAttack - min(cap / divFactor, game->CountOf(SU_)), game->CountOf(ES));
    int SUtoAttack = min(cap - ETtoAttack - EStoAttack, game->CountOf(SU_));
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
            damage =  (pwr * hlth / 100) / sqrt(unt->getHealth());
            unt->DecHlth(damage);
            lst.addUnit(unt);
        }
    }
    for (int i = 0; i < SUtoAttack; i++)
    {
        ArmyUnit* unt = game->PickUnit(SU_, nl1, nl2);
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
        unt = game->PickUnit(ES,nl1,nl2);
        if (unt)
        {
            damage = (pwr * hlth / 100) / sqrt(unt->getHealth());
            int infectionProb = (gen() % (101));
            //would be attacked if ->not about to be killed ,infcProp ,immune or already infected
            if (/*unt->getHealth() > damage ||*/ infectionProb > infection_Percentage || unt->isImmune() || unt->getInfectionState())
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
    if (flag)
        lst.printList();

    while (lst.getCount())
    {
        ArmyUnit* unt = lst.pickUnit();
        if (unt && unt->getHealth() > 0)
        {
            if (unt->getHealth() < 0.2 * unt->getStartHlth())
            {
                unt->setTjUML(game->getTime());	//setting the time that the unit joined the UML
                game->getEArmy()->AddToUML(unt);
            }
            else
                game->AddUnit(unt);
        }
        else
        {
            game->AddToKldList(unt);
        }
    }
    
}
