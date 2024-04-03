
#ifndef _DNODE
#define _DNODE
template < typename T>
class DNode
{
private :
	T item; // A data item
	DNode<T>* next; // Pointer to next node
	DNode<T>* prev; //Pointer to previous node
public :
	DNode();
	DNode( const T & r_Item);	
	DNode( const T & r_Item, DNode<T>* nextNodePtr, DNode<T>* prevNodePtr);
	void setItem( const T & r_Item);
	void setNext(DNode<T>* nextNodePtr);
	void setPrev(DNode<T>* prevNodePtr);
	T getItem() const ;
	DNode<T>* getNext() const ;
	DNode<T>* getPrev() const;
}; // end Node


template < typename T>
DNode<T>::DNode() 
{
	next = nullptr;
	prev = nullptr;
} 

template < typename T>
DNode<T>::DNode( const T& r_Item)
{
	item = r_Item;
	next = nullptr;
	prev = nullptr;
} 

template < typename T>
DNode<T>::DNode( const T& r_Item, DNode<T>* nextNodePtr, DNode<T>* prevNodePtr)
{
	item = r_Item;
	next = nextNodePtr;
	prev = prevNodePtr;
}
template < typename T>
void DNode<T>::setItem( const T& r_Item)
{
	item = r_Item;
} 

template < typename T>
void DNode<T>::setNext(DNode<T>* nextNodePtr)
{
	next = nextNodePtr;
} 
template < typename T>
void DNode<T>::setPrev(DNode<T>* prevNodePtr)
{
	prev = prevNodePtr;
}
template < typename T>
T DNode<T>::getItem() const
{
	return item;
} 

template < typename T>
DNode<T>* DNode<T>::getNext() const
{
	return next;
}
template < typename T>
DNode<T>* DNode<T>::getPrev() const
{
	return prev;
}
#endif