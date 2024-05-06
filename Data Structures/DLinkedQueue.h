
/*
This is a program that implements the DLinkedQueue abstract data type using a linked list.
The queue is implemented as a chain of linked DNodes that has two pointers, 
a frontPtr pointer for the front of the queue and a backPtr pointer for the back of the queue.
*/


#ifndef D_LINKED_QUEUE_
#define D_LINKED_QUEUE_

#include "DNode.h"
#include "QueueADT.h"
#include <vector>
using namespace std;


template <typename T>
class DLinkedQueue:public QueueADT<T>
{
protected :
	
	DNode<T>* backPtr;
	DNode<T>* frontPtr;
public :
	DLinkedQueue();	
	bool isEmpty() const ;
	bool enqueue(const T& newEntry);
	bool push(const T& newEntry); //to add to the front
	bool dequeue(T& frntEntry); 
	bool pop(T& bckEntry); //to pop an item from the rear
	bool peek(T& frntEntry)  const;
	bool Rpeek(T& bckEntry)  const; //To get the value of the item in the rear
	~DLinkedQueue();

	//copy constructor
	DLinkedQueue(const DLinkedQueue<T> & LQ);
};
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: Queue()
The constructor of the Queue class.

*/

template <typename T>
DLinkedQueue<T>::DLinkedQueue()
{
	backPtr=nullptr;
	frontPtr=nullptr;

}
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: isEmpty
Sees whether this queue is empty.

Input: None.
Output: True if the queue is empty; otherwise false.
*/
template <typename T>
bool DLinkedQueue<T>::isEmpty() const
{
	return (frontPtr==nullptr);
}

/////////////////////////////////////////////////////////////////////////////////////////

/*Function:enqueue
Adds newEntry at the back of this queue.

Input: newEntry .
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool DLinkedQueue<T>::enqueue( const T& newEntry)
{
	DNode<T>* newDNodePtr = new DNode<T>(newEntry);
	newDNodePtr->setPrev(backPtr);
	// Insert the new DNode
	if (isEmpty())	//special case if this is the first DNode to insert
	{
		frontPtr = newDNodePtr; // The queue is empty
	}
	else
		backPtr->setNext(newDNodePtr); // The queue was not empty

	backPtr = newDNodePtr; // New DNode is the last DNode now
	return true ;
} // end enqueue

////////////////////////////////////////////////////////////////////////////////////////

/*
Function: push()
Adds a newEntry to the front of this quwuw

Input: newEntry .
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool DLinkedQueue<T>::push(const T& newEntry)
{
	DNode<T>* newDNodePtr = new DNode<T>(newEntry);
	newDNodePtr->setNext(frontPtr);
	// Insert the new DNode
	if (isEmpty())	//special case if this is the first DNode to insert
	{
		backPtr = newDNodePtr; // The queue is empty
	}
	else
		frontPtr->setPrev(newDNodePtr); // The queue was not empty

	frontPtr = newDNodePtr; // New DNode is the last DNode now
	return true;
} // end push

/////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Function: dequeue
Removes the front of this queue. That is, removes the item that was added
earliest.

Input: None.
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool DLinkedQueue<T>::dequeue(T& frntEntry)  
{
	if(isEmpty())
		return false;

	DNode<T>* DNodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();
	// Queue is not empty; remove front
	if (DNodeToDeletePtr == backPtr)	 // Special case: last DNode in the queue
		backPtr = nullptr ;	
	else {
		frontPtr->setPrev(nullptr);
	}
	// Free memory reserved for the DLinkedQueueued DNode
	delete DNodeToDeletePtr;

	return true;

}

/*Function: pop
Removes the rear of this queue. That is, removes the item that was added
last.

Input: None.
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool DLinkedQueue<T>::pop(T& bckEntry)
{
	if (isEmpty())
		return false;

	DNode<T>* DNodeToDeletePtr = backPtr;
	bckEntry = backPtr->getItem();
	backPtr = backPtr->getPrev();
	// Queue is not empty; remove back
	if (DNodeToDeletePtr == frontPtr)	 // Special case: first DNode in the queue
		frontPtr = nullptr;
	else {
		backPtr->setNext(nullptr);
	}
	// Free memory reserved for the DLinkedQueueued DNode
	delete DNodeToDeletePtr;

	return true;

}
/////////////////////////////////////////////////////////////////////////////////////////
/*
Function: peek
copies the front of this queue to the passed param. The operation does not modify the queue.

Input: None.
Output: The front of the queue.
*/
template <typename T>
bool DLinkedQueue<T>:: peek(T& frntEntry) const 
{
	if (frontPtr == backPtr)
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}
/////////////////////////////////////////////////////////////////////////////////////////
/*
Function: Rpeek
copies the back of this queue to the passed param. The operation does not modify the queue.

Input: None.
Output: The back of the queue.
*/
template <typename T>
bool DLinkedQueue<T>::Rpeek(T& bckEntry) const
{
	if (frontPtr == backPtr)
		return false;
	bckEntry = backPtr->getItem();
	return true;

}
///////////////////////////////////////////////////////////////////////////////////
/*
Function: destructor
removes all DNodes from the queue by DLinkedQueueuing them
*/
template <typename T>
DLinkedQueue<T>::~DLinkedQueue()
{
	//Free all DNodes in the queue
	T temp;
	while(dequeue(temp));
}
/////////////////////////////////////////////////////////////////////////////////////////
/*
Function: Copy constructor
To avoid shallow copy, 
copy constructor is provided

Input: DLinkedQueue<T>: The Queue to be copied
Output: none
*/

template <typename T>
DLinkedQueue<T>::DLinkedQueue(const DLinkedQueue<T> & LQ)
{	
	frontPtr = backPtr = nullptr;
	DNode<T>* DNodePtr = LQ.frontPtr;	//start at the front DNode in LQ
	while (DNodePtr)
	{
		enqueue(DNodePtr->getItem());	//get data of each DNode and enqueue it in this queue 
		DNodePtr = DNodePtr->getNext();
	}	
}
#endif