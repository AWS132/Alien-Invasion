#pragma once
#include <iostream>
#include <fstream>
#include "ArmyUnit.h"
#include "../Data Structures/LinkedQueue.h"

using namespace std;
class GenQueueADT:public LinkedQueue<ArmyUnit*> {
private:
	int count;
	int InfectedCount;
public:

	GenQueueADT();
	bool addUnit(ArmyUnit* Unit);
	int getCount() const;
	int getInfectedCount() const;//returns the count of infected ES
	ArmyUnit* pickUnit();
	void printList();
	void outKilled(ofstream&,int&, int& ,int&, int&,int&,int&,int=0);// Writes killed unit information to file
	void infectRandomly();	//responsible for spreading infection in ES list randomly
	ArmyUnit* pickInfected();//picks an infected ES from its list
	int getImmuneCount()const;//count of immune units
	~GenQueueADT();
};