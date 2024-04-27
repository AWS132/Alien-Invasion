#pragma once
#include <iostream>
#include <fstream>
#include<../../Army units/tmpList.h>
using namespace std;
class GameClass;
enum unitType {
	ES,ET,EG,AS,AM,AD
};
class ArmyUnit
{
protected:
	int ID;
	unitType type;
	int  Tj		//joining time,
		,hlth	// health,
		,pwr	// power,
		,cap	// attack capacity,
		,Ta		// time it was first attacked initially -1,
		,Td;	// time it was dismissed from the battle initially -1  
	GameClass* game;
public:
	ArmyUnit();
	int getPower();
	int getHealth();
	ArmyUnit(int id, unitType Type, int tj, int health, int power, int capacity, GameClass* game);
	unitType getType();
	int getDf()const;
	int getDd()const;
	virtual void Attack()=0; 
	virtual bool DecHlth(double value);// Decreases the Health by a certain "value" returns false if killed
	virtual void Print() const;
	void Output(ofstream& oFile);

};

