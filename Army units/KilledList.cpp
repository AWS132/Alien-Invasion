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

void KilledList::outKilled(ofstream& oFile,int& S,int& T,int& G,int& Df,int& Dd ,int type)
{
	Node< ArmyUnit*>* ptr = frontPtr;
	S = T = G = Df = Dd = 0;
	while (ptr)
	{
		unitType x = ptr->getItem()->getType();
		if (x > type && x < type + 2)
		{
			if (x == ES + type)
				S++;
			else if (x == ET + type)
				T++;
			else if (x == EG + type)
				G++;
			
			ptr->getItem()->Output(oFile);
			Dd+=ptr->getItem()->getDd();
			Df += ptr->getItem()->getDf();
		}
			ptr = ptr->getNext();
	}
}
	


KilledList::~KilledList()
{
    ArmyUnit* x=nullptr;
    while (dequeue(x)) {
        if (x) delete x;
    }
}
