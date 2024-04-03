#include "ArmyUnit.h"
#include <iostream>
#include <iomanip>
using namespace std;

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

bool ArmyUnit::DecHlth(int value)
{
	hlth -= value;
	if(hlth<=0)
	return false;
	return true;
}

void ArmyUnit::Print() const //prints the unit's info to the console
{
	cout << "Td" << setw(6) << "ID" << setw(6) << "Tj" << setw(6) << "Df" << setw(6) << "Dd" << setw(6) << "Db" << endl;
	cout <<Td<< setw(6)<<ID<<setw(6)<<Tj<< setw(6) <<Ta-Tj <<setw(6)<<Td-Ta<<setw(6)<<Td-Tj<<endl;

}
