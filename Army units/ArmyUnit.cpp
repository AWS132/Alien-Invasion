#include "ArmyUnit.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

ArmyUnit::ArmyUnit()
{
}

int ArmyUnit::getPower()
{
	return pwr;
}

int ArmyUnit::getHealth()
{
	return hlth;
}

ArmyUnit::ArmyUnit(int id, unitType Type, int tj, int health, int power, int capacity,GameClass* game){
		
		ID = id;
		type = Type;
		Tj = tj;
		hlth = health;
		pwr = power;
		cap = capacity;
		Td = -1;
		Ta = -1;
		this->game = game;
	
}

unitType ArmyUnit::getType()
{
	return type;
}

int ArmyUnit::getDf() const
{
	return Ta - Tj;
}

int ArmyUnit::getDd() const
{
	return Td - Ta;
}

bool ArmyUnit::DecHlth(double value)
{
	hlth -= value;
	if(hlth<=0)
	return false;
	return true;
}

void ArmyUnit::Print() const
{
	cout << ID;
}

void ArmyUnit::Output(ofstream& oFile)  //prints the unit's info to the output file
{
	oFile << "Td" << setw(6) << "ID" << setw(6) << "Tj" << setw(6) << "Df" << setw(6) << "Dd" << setw(6) << "Db" << endl;
	oFile << Td<< setw(6)<<ID<<setw(6)<<Tj<< setw(6) <<getDf() <<setw(6)<<getDd()<<setw(6)<<getDf()+getDd()<<endl;
}

