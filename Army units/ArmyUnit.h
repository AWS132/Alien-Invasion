#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class GameClass;
enum unitType {
	ES, ET, EG, HU_, AS, AM, AD,SU_
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
		,Td	// time it was dismissed from the battle initially -1  
		,TjUML;	// time it entered uml
	bool infected//infected by monster Attack==>1  not infected==>0 (defualt state)
		,immune;// protected from being infected again
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
	bool getInfectionState();
	void setTa(int time);
	void setTd(int time);
	void setTjUML();
	int getID()const;
	int getTjUML()const;
	virtual void Attack(int)=0; 
	virtual bool DecHlth(double value);// Decreases the Health by a certain "value" returns false if killed
	virtual bool IncHlth(double product);// increases the heath by a certain value determined by a given equation,returns false if not over 20%
	virtual void Print() const;
	void Output(ofstream& oFile);
	void become_infected();        //The AM infeceted this unit
	void become_immune();        //became immune 
	bool isImmune();	

};

