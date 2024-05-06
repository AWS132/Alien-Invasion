#include "AlienArmy.h"
AlienArmy::AlienArmy() {
	m = new Monsters;
	as = new genQueueADT;
	d = new Drones;
	id = 2000;
}

int AlienArmy::getId() const
{
	return id;
}

void AlienArmy::AddUnit(ArmyUnit* unit,bool flag)
{
	if(flag)
	id += 1;
	unitType type = unit->getType();
	switch (type)
	{
	case AS:
		as->addUnit(unit);
		break;
	case AM:
		m->addUnit(unit);
		break;
	case AD:
		d->addUnit(unit);
		break;
	default:
		break;
	}
}

void AlienArmy::PrintArmy()
{
	cout << " =============== Alien Army Alive Units =============== \n";
	m->printMonsters();
	cout << "AS ";
	as->printList();
	d->printDrones();
}

int AlienArmy::getCount() const
{
	return as->getCount()+m->getCount()+d->getCount();
}

ArmyUnit* AlienArmy::PickAunit(unitType u,ArmyUnit*& d1, ArmyUnit*& d2,int dm)
{
	switch (u)
	{
	case AS:
		return as->pickUnit();
	case AM:
		return m->pickMonster();
	case AD:
		d->pickDrones(d1,d2,dm);
	default:
		return nullptr;
	}
}ArmyUnit* AlienArmy::peekAunit(unitType u,ArmyUnit*& d1, ArmyUnit*& d2)
{
	ArmyUnit* unt = nullptr;
	switch (u)
	{
	case AS:
		 as->peek(unt);
		 break;
	case AM:
		 return m->peekMonster();
	case AD:
		d->peek(d1);
		d->Rpeek(d2);
		break;
	default:
		return nullptr;
	}
	return unt;
}

int AlienArmy::CountOf(unitType ut)
{
	switch (ut)
	{
	case AS:
		return as->getCount();
	case AM:
		return m->getCount();
	case AD:
		return d->getCount();
	default:
		return 0;
	}
}

AlienArmy::~AlienArmy()
{
	delete as;
	delete m;
	delete d;
}

