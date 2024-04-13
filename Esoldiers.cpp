#include "Esoldiers.h"

Esoldiers::Esoldiers()
{
    count = 0;
}

//bool Esoldiers::CreateEsoldiers(int id, int tj, int health, int power, int capacity)
//{
//    ArmyUnit* Es = new ArmyUnit(id, ES, tj, health, power, capacity);
//    count++;
//    return enqueue(Es);
//}

bool Esoldiers::addUnit(ArmyUnit* es)
{
    count++;
    return enqueue(es);
}

ArmyUnit* Esoldiers::pickEsoldiers()
{
    if (!count)
        return false;
    count--;
    ArmyUnit* es;
    dequeue(es);
    return es;
}

void Esoldiers::printEsoldiers()
{
    Node<ArmyUnit*>* temp = frontPtr;
    while (temp != nullptr) {
        temp->getItem()->Print();
        temp = temp->getNext();
    }
}

int Esoldiers::getCount()
{
    return count;
}

Esoldiers::~Esoldiers()
{
    ArmyUnit* x;
    while (dequeue(x)) {
        if (x) delete x;
    }
}

