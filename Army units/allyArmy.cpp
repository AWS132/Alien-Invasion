#include "allyArmy.h"

allyArmy::allyArmy()
{
	id = 4000;
	su = new genQueueADT;
	isCalled = false;
}

int allyArmy::getId()
{
	return id++;
}

void allyArmy::AddUnit(ArmyUnit* unit)
{
	su->addUnit(unit);
}

void allyArmy::PrintArmy()
{
	cout << "======================Ally Army======================\nSU ";
	su->printList();
}

void allyArmy::call()
{
	isCalled = true;
}

bool allyArmy::getStatus() {
	return isCalled;
}
void allyArmy::withdraw()
{
	isCalled = false;
	destructAll();
}
int allyArmy::getCount() const
{
	return su->getCount();
}

allyArmy::~allyArmy()
{
	delete su;
}

ArmyUnit* allyArmy::pickSUnit()
{
	return su->pickUnit();
}

void allyArmy::destructAll()
{
	su->destructAll();
}

ArmyUnit* allyArmy::peekSUnit()
{
	ArmyUnit* unt = nullptr;
	return (su->peek(unt),unt);
}