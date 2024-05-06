#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class GameClass;
enum unitType {
	ES,ET,EG,AS,AM,AD,HU_
};
class ArmyUnit
{
protected:
	int ID;
	unitType type;
	double hlth, startHlth;// health, startHealth

	int  Tj		//joining time,
		,pwr	// power,
		,cap	// attack capacity,
		,Ta		// time it was first attacked initially -1,
		,Td;	// time it was dismissed from the battle initially -1  
	GameClass* game;
public:
	ArmyUnit();
	int getPower();
	double getHealth()const;
	double getStartHlth()const;
	ArmyUnit(int id, unitType Type, int tj, int health, int power, int capacity, GameClass* game);
	unitType getType();
	int getDf()const;
	int getDd()const;
	int getTa()const;
	void setTa(int time);
	void setTd(int time);
	virtual void Attack(int)=0; 
	virtual bool DecHlth(double value);// Decreases the Health by a certain "value" returns false if killed
	virtual bool IncHlth(double product);// increases the heath by a certain value determined by a given equation,returns false if not over 20%
	virtual void Print() const;
	void Output(ofstream& oFile);

};

