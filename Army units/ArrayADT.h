//	This is an updated version of code originally
//  created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** @file StackADT.h */

#ifndef ARRAY_ADT_
#define ARRAY_ADT_

template<typename T>
class ArrayADT
{
public:
    virtual bool isEmpty() const = 0;
    virtual bool push(const T& newEntry) = 0;
    virtual T pick(T& TopEntry) = 0;
    virtual ~ArrayADT() { }
};
#endif