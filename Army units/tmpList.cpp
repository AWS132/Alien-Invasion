#include "tmpList.h"

tmpList::tmpList()
{
    count = 0;
}

bool tmpList::addUnit(ArmyUnit*& Unit)
{
    count++;
    return enqueue(Unit);
}

ArmyUnit* tmpList::PickUnit()
{
    ArmyUnit* unt;
     dequeue(unt);
     return unt;
}

int tmpList::getCount() const
{
    return count;
}

void tmpList::printTmpList()
{
    Node< ArmyUnit*>* temp = frontPtr;
    cout << "============== TempList Units ===============\n";
    cout << count << " units [";
    if (temp == nullptr)
    {
        cout << "]\n";
    }
    while (temp && temp->getItem()) {
        temp->getItem()->Print();
        if (!(temp->getNext()))cout << "]\n";
        else cout << ", ";
        temp = temp->getNext();
    }
}

tmpList::~tmpList()
{
    ArmyUnit* x = nullptr;
    while (dequeue(x)) {
        if (x) delete x;
    }
}
