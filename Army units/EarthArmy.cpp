#include "EarthArmy.h"

EarthArmy::EarthArmy() {
	t = new Tanks;
	es = new Esoldiers;
	g = new Gunnerys;
}

void EarthArmy::AddUnit(ArmyUnit* unit)
{
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
