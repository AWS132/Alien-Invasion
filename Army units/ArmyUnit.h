#pragma once
#include <iostream>
enum unitType {
	ES,ET,EG,AS,AM,AD
};
class ArmyUnit
{
private:
	// TO ADD: pointer to game class
	int ID;
	unitType type;
	int  Tj		//joining time,
		,hlth	// health,
		,pwr	// power,
		,cap	// attack capacity,
		,Ta		// time it was first attacked initially -1,
		,Td;	// time it was dismissed from the battle initially -1  
public:
	ArmyUnit(int id, unitType Type,int tj, int health, int power, int capacity){ //TO ADD: a pointer to game class in the constructor's arguement
		ID = id;
		type = Type;
		Tj = tj;
		hlth = health;
		pwr = power;
		cap = capacity;
		Td = -1;
		Ta = -1;
	}
	virtual void Attack(ArmyUnit* opponent) = 0;
	virtual void Print() = 0; //pure virtual TEMPORARILY
	
};

