#include "ArmyUnit.h"
#include <iostream>
#include <iomanip>
using namespace std;

ArmyUnit::ArmyUnit()
{
	// for testing randGen
	ID = 0;
	type = ET;
	Tj = 0;
	hlth = 100;
	pwr = 50;
	cap = 2;
	Td = 0;
	Ta = 0;
}

int ArmyUnit::getPower()
{
	return pwr;
}

int ArmyUnit::getHealth()
{
	return hlth;
}

ArmyUnit::ArmyUnit(int id, unitType Type, int tj, int health, int power, int capacity){ //TO ADD: a pointer to game class in the constructor's arguement
		
		ID = id;
		type = Type;
		Tj = tj;
		hlth = health;
		pwr = power;
		cap = capacity;
		Td = -1;
		Ta = -1;
	
}

void ArmyUnit::Attack(ArmyUnit* opponent)
{
}

bool ArmyUnit::DecHlth(int value)
{
	hlth -= value;
	if(hlth<=0)
	return false;
	return true;
}

void ArmyUnit::Print() const //prints the unit's info to the console
{
	switch (type)
	{
	case ES:
		break;
	case ET:
		cout << "Type: Tank\n";
		break;
	case EG:
		break;
	case AS:
		break;
	case AM:
		break;
	case AD:
		cout << "Type: Drones\n";
		break;
	default:
		break;
	}
	cout << "Td" << setw(6) << "ID" << setw(6) << "Tj" << setw(6) << "Df" << setw(6) << "Dd" << setw(6) << "Db" << endl;
	cout <<Td<< setw(6)<<ID<<setw(6)<<Tj<< setw(6) <<Ta-Tj <<setw(6)<<Td-Ta<<setw(6)<<Td-Tj<<endl;

}
