#include "Monster.h"

Monster::Monster(int id, int tj, int health, int power, int capacity, GameClass* game):ArmyUnit(id, AM, tj, health, power, capacity,game)
{
}

void Monster::attack(int flag) // Attack both ET && ES
{
	GenQueueADT lst;
    int infectionPercentage = game->getInfectionPerc();
    int divFactor = (game->countOf(SU_)) ? 3 : 2;
    int ETtoAttack = min(cap - min(cap / divFactor, game->countOf(ES)) - min(cap / divFactor, game->countOf(SU_)), game->countOf(ET));
	int EStoAttack = min(cap - ETtoAttack - min(cap / divFactor, game->countOf(SU_)), game->countOf(ES));
    int SUtoAttack = min(cap - ETtoAttack - EStoAttack, game->countOf(SU_));
    ArmyUnit* nl1 = nullptr;
    ArmyUnit* nl2 = nullptr;
    double damage;

    if (flag)
        cout << "AM " << ID << " Attacks ";
    for (int i = 0; i < ETtoAttack; i++)
    {
        ArmyUnit* unt = game->pickUnit(ET, nl1, nl2);
        if (unt)
        {
            damage =  (pwr * hlth / 100) / sqrt(unt->getHealth());
            unt->decHlth(damage);
            lst.addUnit(unt);
        }
    }
    for (int i = 0; i < SUtoAttack; i++)
    {
        ArmyUnit* unt = game->pickUnit(SU_, nl1, nl2);
        if (unt)
        {
            damage = (pwr * hlth / 100) / sqrt(unt->getHealth());
            unt->decHlth(damage);
            lst.addUnit(unt);
        }
    }
    random_device rd;
    mt19937 gen(rd());
    for (int i = 0; i < EStoAttack; i++)
    {
        ArmyUnit* unt;
        unt = game->pickUnit(ES,nl1,nl2);
        if (unt)
        {
            damage = (pwr * hlth / 100) / sqrt(unt->getHealth());
            int infectionProb = (gen() % (101));
            //would be attacked if ->not about to be killed ,infcProp ,immune or already infected
            if (/*unt->getHealth() > damage ||*/ infectionProb > infectionPercentage || unt->isImmune() || unt->getInfectionState())
            {
                unt->decHlth(damage);
            }
            else
            {
                unt->becomeInfected();
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
            if (unt->getHealth() < 0.2 * unt->getStartHlth() && unt->getType() != SU_)
            {
                game->getEArmy()->addToUML(unt);
            }
            else
                game->addUnit(unt);
        }
        else
        {
            game->addToKldList(unt);
        }
    }
    
}
