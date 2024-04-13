#include "KilledList.h"

KilledList::KilledList()
{
    count = 0;
}

bool KilledList::addUnit(ArmyUnit* Unit)
{
    count++;
    return enqueue(Unit);
}

int KilledList::getCount() const
{
    return count;
}

void KilledList::printKilled()
{
   Node< ArmyUnit*>* temp= frontPtr;
   cout << "============== Killed/Destructed Units ===============\n";
   cout << count << "units [";
   if (!temp)
   {
       cout << "]\n";
   }
   while (temp) {
       temp->getItem()->Print();
       if (!(temp->getNext()))cout << "]\n";
       else cout << ", ";
       temp = temp->getNext();
   }
}

KilledList::~KilledList()
{
    ArmyUnit* x=nullptr;
    while (dequeue(x)) {
        if (x) delete x;
    }
}
