#include "GenQueueADT.h"
#include"random"


GenQueueADT::GenQueueADT()
{
    count = 0;
	InfectedCount = 0;
}

bool GenQueueADT::addUnit(ArmyUnit* Unit)
{
	if (!Unit)
		return false;
	count++;
	if (Unit->getInfectionState())
		InfectedCount++;
    return enqueue(Unit);
}

int GenQueueADT::getCount() const
{
    return count;
}

int GenQueueADT::getInfectedCount() const
{
	return InfectedCount;
}

ArmyUnit* GenQueueADT::pickUnit()
{
	if (!count)
		return nullptr;
	if (count > 0)
		count--;

	ArmyUnit* unt;
	dequeue(unt);
	if (unt && unt->getInfectionState())InfectedCount--;
	return unt;
}

void GenQueueADT::printList()
{
   Node< ArmyUnit*>* ptr= frontPtr;
	   cout << count << " [";
	   while (ptr and ptr->getNext())
	   {
		   ptr->getItem()->print();
		   ptr = ptr->getNext();
		   cout << ", ";
	   }
	   if (ptr)
		   ptr->getItem()->print();
	   cout << "]\n";
 
}



void GenQueueADT::outKilled(ofstream& oFile, int& S, int& T, int& G, int& HU, int& Df, int& Dd, int type)
{
	Node< ArmyUnit*>* ptr = frontPtr;
	S = T = G = HU = Df = Dd = 0;
	while (ptr)
	{
		unitType x = ptr->getItem()->getType();
		if (x >= type && x < type + 4 && x != 7)
		{
			if (x == ES + type)
				S++;
			else if (x == ET + type)
				T++;
			else if (x == EG + type)
				G++;
			else if (x == HU_ + type)
				HU++;
			ptr->getItem()->Output(oFile);
			Dd += ptr->getItem()->getDd();
			Df += ptr->getItem()->getDf();
		}
		ptr = ptr->getNext();
	}

}
void GenQueueADT::infectRandomly()
{
	random_device rd;
	mt19937 gen(rd());
	int A = (gen() % (count)) + 1;    //(rand() % (ub - lb + 1)) + lb  To generate Random index to be infected ! 
	Node< ArmyUnit*>* ptr = frontPtr;
	for (int i = 1; i <= count && InfectedCount<count; i++)
	{
		if (A == i)
		{
			if (!ptr->getItem()->getInfectionState())
			{
				ptr->getItem()->becomeInfected();
				InfectedCount++;
				return;
			}
			else
			{
				if (i == count)
				{
					A = 0;
					i = 0;
				}
				else
				{
					A++;
				}
			}
		}
	}
}

ArmyUnit* GenQueueADT::pickInfected()
{
	Node< ArmyUnit*>* ptr = frontPtr,*next;
	ArmyUnit* unt;

	if (!ptr)
		return nullptr;
	
	next = ptr->getNext();
	if (ptr->getItem()->getInfectionState())	//if the infected ES is at the beginning
	{
		count--;
		InfectedCount--;
		dequeue(unt);
		return unt; //returns dequeued unit
	}

	while (next) {
		if (next->getItem()->getInfectionState())
		{
			ptr->setNext(next->getNext());
			unt = next->getItem();
			if (!next->getNext())
				backPtr = ptr;
			delete next;
			count--;
			InfectedCount--;
			return unt;
		}
		else
		{
			ptr = next;
			next = next->getNext();
		}
	}
	return nullptr;
}

int GenQueueADT::getImmuneCount() const
{
	Node< ArmyUnit*>* ptr = frontPtr;
	int immCount=0;
	while (ptr) {
		if (ptr->getItem()->isImmune()) {
			immCount++;
		}
		ptr = ptr->getNext();
	}
	return immCount;
}

void GenQueueADT::destructAll()
{
	count = 0;
	ArmyUnit* x = nullptr;
	while (dequeue(x)) {
		if (x) delete x;
	}
}
	


GenQueueADT::~GenQueueADT()
{
	destructAll();
}
