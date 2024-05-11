#include "ArmyUnit.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "../Game/GameClass.h"
using namespace std;

ArmyUnit::ArmyUnit()
{
}

int ArmyUnit::getPower()
{
	return pwr;
}

double ArmyUnit::getHealth()const
{
	return hlth;
}

double ArmyUnit::getStartHlth()const
{
	return startHlth;
}

ArmyUnit::ArmyUnit(int id, unitType Type, int tj, int health, int power, int capacity, GameClass* game) {

	ID = id;
	type = Type;
	Tj = tj;
	startHlth = health;
	hlth = health;
	pwr = power;
	cap = capacity;
	Td = -1;
	Ta = -1;
	this->game = game;
	infected = 0;       // initially all the units are not infected
	immune = false;	// initially all ESs are not immuned yet
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

int ArmyUnit::getTa()const
{
	return Ta;
}

bool ArmyUnit::getInfectionState()
{
	return infected;
}

void ArmyUnit::setTa(int time)
{
	if(Ta==-1)
		Ta = time;
}

void ArmyUnit::setTd(int time)
{
	if (Td == -1)
		Td = time;
}

int ArmyUnit::getID() const
{
	return ID;
}

bool ArmyUnit::DecHlth(double value)
{
	setTa(game->getTime());
	hlth -= value;
	if (hlth <= 0) {
	setTd(game->getTime());
	}
	return (hlth > 0);
}

bool ArmyUnit::IncHlth(double product)
{
	double imp = (product / 100) / sqrt(hlth);
	hlth += imp;
	return (hlth > (0.2 * startHlth));
}

void ArmyUnit::Print() const
{
	if (infected)
		cout << "*!*";
	cout << ID;
	
}

void ArmyUnit::Output(ofstream& oFile)  //prints the unit's info to the output file
{
	oFile << "Td" << setw(6) << "ID" << setw(6) << "Tj" << setw(6) << "Df" << setw(6) << "Dd" << setw(6) << "Db" << endl;
	oFile << Td<< setw(6)<<ID<<setw(6)<<Tj<< setw(6) <<getDf() <<setw(6)<<getDd()<<setw(6)<<getDf()+getDd()<<endl;
}

void ArmyUnit::become_infected()
{
	infected = 1;    // this unit is infected now;
}

void ArmyUnit::become_immune()
{
	infected = false;	//not infected anymore ^_^
	immune = true;
}

bool ArmyUnit::isImmune()
{

	return immune;
}

