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
        return nullptr;
    if(count>0)
    count--;
    ArmyUnit* es;
    dequeue(es);
    return es;
}

void Esoldiers::printEsoldiers()
{
    Node<ArmyUnit*>* ptr = frontPtr;

    cout << count << " ES [";
    while (ptr and ptr->getNext())
    {
        ptr->getItem()->Print();
        ptr = ptr->getNext();
        cout << ", ";
    }
    if (ptr)
        ptr->getItem()->Print();
    cout << "]\n";
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

