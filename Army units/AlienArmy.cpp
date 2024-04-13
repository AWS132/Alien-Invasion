#include "AlienArmy.h"
#include "Asoldiers.h"
AlienArmy::AlienArmy() {
	m = new Monsters;
	as = new Asoldiers;
	d = new Drones;
	id = 1999;
}

int AlienArmy::getId() const
{
	return id;
}

void AlienArmy::AddUnit(ArmyUnit* unit)
{
	id += 1;
	if (dynamic_cast<Asoldier*>(unit))
		as->addUnit(unit);
	else if (dynamic_cast<Monster*>(unit))
		m->addUnit(unit);
	else if (dynamic_cast<Drone*>(unit))
		d->addUnit(unit);
}

void AlienArmy::PrintArmy()
{
	cout << " =============== Alien Army Alive Units =============== \n";
	m->printMonsters();
	as->printAsoldiers();
	d->printDrones();
}

AlienArmy::~AlienArmy()
{
	delete as;
	delete m;
	delete d;
}
