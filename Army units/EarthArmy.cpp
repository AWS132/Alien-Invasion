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
	unitType type = unit->getType();
	id += 1;
	switch (type)
	{
	case ES:
		es->addUnit(unit);
		break;
	case ET:
		t->addUnit(unit);
		break;
	case EG:
		g->addUnit(unit);
		break;
	default:
		break;
	}
}

void EarthArmy::PrintArmy()
{
	cout << "=============== Earth Army Alive Units===============\n";
	es->printEsoldiers();
	t->printTanks();
	g->printGunnerys();

}

EarthArmy::~EarthArmy()
{
	delete t;
	delete es;
	delete g;
}

ArmyUnit* EarthArmy::pickEUnit(unitType u)
{
	switch (u)
	{
	case ES:
	return es->pickEsoldiers();
		break;
	case ET:
	return t->pickTank();
		break;
	case EG:
	return g->pickGunnery();
		break;
	default:
		break;
	}
}
