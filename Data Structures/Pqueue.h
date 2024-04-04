#ifndef PQUEUE_ADT_
#define PQUEUE_ADT_
#include<../../Army units/ArmyUnit.h>
#include<../../Data Structures/LinkedQueue.h>
class pQueue:public LinkedQueue<ArmyUnit*>
{
public:
	bool enqueue( ArmyUnit* gn)
	{
		Node<ArmyUnit*>* newNodePtr = new Node<ArmyUnit*>(gn);
		if (isEmpty())
		{
			frontPtr = newNodePtr;
			backPtr = frontPtr;
			backPtr->setNext(nullptr);
		}
		else
		{
			Node<ArmyUnit*>* ptr = frontPtr;
			Node<ArmyUnit*>* ptr2 = frontPtr;
			while (ptr != nullptr)
			{
				if (gn->getHealth() > ptr->getItem()->getHealth())
				{
					if (ptr == frontPtr) // inserting at the head of the list
					{
						newNodePtr->setNext(ptr);
						frontPtr = newNodePtr;
					}
					else
					{
						newNodePtr->setNext(ptr);
						ptr2->setNext(newNodePtr);
					}
					return true;
				}
				else if (gn->getHealth() == ptr->getItem()->getHealth())
				{

					if (gn->getPower() > ptr->getItem()->getPower())
					{
						if (ptr == frontPtr) // inserting at the head of the list
						{
							newNodePtr->setNext(ptr);
							frontPtr = newNodePtr;
						}
						else
						{
							newNodePtr->setNext(ptr);
							ptr2->setNext(newNodePtr);
						}
						return true;
					}
				}
				ptr2 = ptr;
				ptr = ptr->getNext();
			}
			if (ptr == nullptr)
			{
				backPtr->setNext(newNodePtr);
				newNodePtr->setNext(nullptr);
				backPtr = newNodePtr;
				return true;
			}
			return false;
		}
		
	} // end enqueue
	ArmyUnit* dequeue()
	{
		if (isEmpty())
			return nullptr;

		ArmyUnit* target = frontPtr->getItem();
		if (frontPtr == backPtr)
		{
			frontPtr = nullptr;
			backPtr = nullptr; 
		}
		else
		{ 
		frontPtr = frontPtr->getNext();
		}
		return target;
	}
}; 
#endif