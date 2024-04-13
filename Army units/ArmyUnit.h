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
	ArmyUnit();
	int getPower();
	int getHealth();
	ArmyUnit(int id, unitType Type, int tj, int health, int power, int capacity);// TO ADD: pointer to game class
	//virtual bool addUnit(ArmyUnit* unit) = 0;
	virtual void Attack(ArmyUnit* opponent)=0; 
	virtual bool DecHlth(int value);// Decreases the Health by a certain "value" returns false if killed
	virtual void Print() const;
	virtual void Output() const;

};

