#include "AllyArmy.h"

AllyArmy::AllyArmy()
{
	id = 4000;
	su = new GenQueueADT;
	isCalled = false;
}

int AllyArmy::getId()
{
	return ++id;
}

void AllyArmy::addUnit(ArmyUnit* unit)
{
	su->addUnit(unit);
}

void AllyArmy::printArmy()
{
	cout << "======================Ally Army======================\nSU ";
	su->printList();
}

void AllyArmy::call()
{
	isCalled = true;
}

bool AllyArmy::getStatus() {
	return isCalled;
}
bool AllyArmy::checkID()
{
	return id<4999;
}
void AllyArmy::withdraw()
{
	isCalled = false;
	destructAll();
}
int AllyArmy::getCount() const
{
	return su->getCount();
}

AllyArmy::~AllyArmy()
{
	delete su;
}

ArmyUnit* AllyArmy::pickSUnit()
{
	return su->pickUnit();
}

void AllyArmy::destructAll()
{
	ArmyUnit* x = nullptr;
	while ((x = su->pickUnit(), x)) {
		x->addToKlst();
	}
}

ArmyUnit* AllyArmy::peekSUnit()
{
	ArmyUnit* unt = nullptr;
	return (su->peek(unt),unt);
}
