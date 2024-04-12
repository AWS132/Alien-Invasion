#include "Esoldiers.h"

Esoldiers::Esoldiers()
{
    count = 0;
}

bool Esoldiers::CreateEsoldiers(int id, int tj, int health, int power, int capacity)
{
    ArmyUnit* Es = new ArmyUnit(id, ES, tj, health, power, capacity);
    count++;
    return enqueue(Es);
}

ArmyUnit* Esoldiers::pickEsoldiers()
{
    return dequeue();
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

