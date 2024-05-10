#include "genQueueADT.h"
#include"random"

genQueueADT::genQueueADT()
{
    count = 0;
	InfectedCount = 0;
}

bool genQueueADT::addUnit(ArmyUnit* Unit)
{
    count++;
	if (Unit->getInfectionState()) InfectedCount++;
    return enqueue(Unit);
}

int genQueueADT::getCount() const
{
    return count;
}

int genQueueADT::getInfectedCount() const
{
	return InfectedCount;
}

ArmyUnit* genQueueADT::pickUnit()
{
	if (!count)
		return nullptr;
	if (count > 0)
		count--;
	ArmyUnit* unt;
	dequeue(unt);
	return unt;
}

void genQueueADT::printList()
{
   Node< ArmyUnit*>* ptr= frontPtr;
	   cout << count << " [";
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

void genQueueADT::outKilled(ofstream& oFile,int& S,int& T,int& G,int& Df,int& Dd ,int type)
{
	Node< ArmyUnit*>* ptr = frontPtr;
	S = T = G = Df = Dd = 0;
	while (ptr)
	{
		unitType x = ptr->getItem()->getType();
		if (x >= type && x < type + 3)
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

void genQueueADT::infectRandomly()
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
				ptr->getItem()->become_infected();
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
	


genQueueADT::~genQueueADT()
{
    ArmyUnit* x=nullptr;
    while (dequeue(x)) {
        if (x) delete x;
    }
}
