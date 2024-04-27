#include "EarthArmy.h"

EarthArmy::EarthArmy() {
	t = new Tanks;
	es = new Esoldiers;
	g = new Gunnerys;
	id = 1;
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

int EarthArmy::getCount() const
{
	return es->getCount()+t->getCount()+g->getCount();
}

int EarthArmy::CountOf(unitType ut)
{
	switch (ut)
	{
	case ES:
		return es->getCount();
	case ET:
		return t->getCount();
	case EG:
		return g->getCount();
	default:
		return 0;
	}
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
		return nullptr;
		break;
	}
}
