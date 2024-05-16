#pragma once
#include<../../Army units/ArmyUnit.h>
#include<../../Data Structures/LinkedQueue.h>
class ArmyUnit;
class PriQueue :public LinkedQueue<ArmyUnit*>
{
public:
	bool enqueue(ArmyUnit* eu)//earth unit
	{
		Node<ArmyUnit*>* newNodePtr = new Node<ArmyUnit*>(eu);
		if (isEmpty())
		{
			frontPtr = newNodePtr;
			backPtr = frontPtr;
			return true;
		}
		else
		{
			Node<ArmyUnit*>* ptr = frontPtr;
			Node<ArmyUnit*>* ptr2 = frontPtr;
			while (ptr != nullptr)
			{
				if (eu->getType() == ES) {
					if (ptr->getItem()->getType() == ES) {
						if (eu->getHealth() <= ptr->getItem()->getHealth())
						{
							if (ptr == frontPtr) {
								newNodePtr->setNext(ptr);
								frontPtr = newNodePtr;
							}
							else {
								newNodePtr->setNext(ptr);
								ptr2->setNext(newNodePtr);
							}
							return true;
						}
					}
					else {
						if (ptr == frontPtr) {
							newNodePtr->setNext(ptr);
							frontPtr = newNodePtr;
						}
						else {
							newNodePtr->setNext(ptr);
							ptr2->setNext(newNodePtr);
						}
						return true;
					}
				}
				else
				{
					backPtr->setNext(newNodePtr);	//if tank, put it at the end as a normal Q
					newNodePtr->setNext(nullptr);
					backPtr = newNodePtr;
					return true;
				}
				ptr2 = ptr;
				ptr = ptr->getNext();
			}
			if (!ptr) {
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
