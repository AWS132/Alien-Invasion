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
   Node< ArmyUnit*>* ptr= frontPtr;
   cout << "============== Killed/Destructed Units ===============\n";
	   cout << count << " units [";
	   while (ptr and ptr->getNext())
	   {
		   ptr->getItem()->Print();
		   ptr = ptr->getNext();
		   cout << ", ";
	   }
	   if (ptr)
		   ptr->getItem()->Print();
	   cout << "]\n";;
 
}

KilledList::~KilledList()
{
    ArmyUnit* x=nullptr;
    while (dequeue(x)) {
        if (x) delete x;
    }
}
