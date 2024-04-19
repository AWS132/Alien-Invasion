#include "AlienArmy.h"
AlienArmy::AlienArmy() {
	m = new Monsters;
	as = new Asoldiers;
	d = new Drones;
	id = 2000;
}

int AlienArmy::getId() const
{
	return id;
}

void AlienArmy::AddUnit(ArmyUnit* unit)
{
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
	as->printAsoldiers();
	d->printDrones();
}

ArmyUnit* AlienArmy::PickAunit(unitType u,ArmyUnit*& d1, ArmyUnit*& d2)
{
	switch (u)
	{
	case AS:
		return as->pickAsoldiers();
	case AM:
		return m->pickMonster();
	case AD:
		d->pickDrones(d1,d2);
	default:
		return nullptr;
	}
}

AlienArmy::~AlienArmy()
{
	delete as;
	delete m;
	delete d;
}

