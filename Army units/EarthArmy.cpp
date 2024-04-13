#include "EarthArmy.h"

EarthArmy::EarthArmy() {
	t = new Tanks;
	es = new Esoldiers;
	g = new Gunnerys;
	id = 0;
}

int EarthArmy::getId() const
{
	return id;
}

void EarthArmy::AddUnit(ArmyUnit* unit)
{
	id += 1;
	if (dynamic_cast<Esoldier*>(unit))
		es->addUnit(unit);
	else if (dynamic_cast<Tank*>(unit))
		t->addUnit(unit);
	else if (dynamic_cast<Gunnery*>(unit))
		g->addUnit(unit);
}

void EarthArmy::PrintArmy()
{
	cout << "=============== Earth Army Alive Units===============\n";
	es->printEsoldiers();
	t->printTanks();
	g->printGunnery();

}

EarthArmy::~EarthArmy()
{
	delete t;
	delete es;
	delete g;
}
