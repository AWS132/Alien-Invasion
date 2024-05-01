#include "EarthArmy.h"

EarthArmy::EarthArmy() {
	t = new Tanks;
	es = new Esoldiers;
	g = new Gunnerys;
	hl = new HL;
	uml = new UML;
	id = 1;
}

int EarthArmy::getId() const
{
	return id;
}

void EarthArmy::AddUnit(ArmyUnit* unit,bool flag)  // flag==>0 returning unit to its list from 
{
	 
	unitType type = unit->getType();
	if(flag)
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
	case HU_:
		hl->addUnit(unit);
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
	hl->printHeal();
}

int EarthArmy::getCount() const
{
	return es->getCount() + t->getCount() + g->getCount() + hl->getCount();
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
	case HU_:
		return hl->getCount();
	default:
		return 0;
	}
}

ArmyUnit* EarthArmy::pickFromUML()
{
	return  uml->pickUnit();
}

bool EarthArmy::AddToUML(ArmyUnit* unit)
{
	return uml->addUnit(unit);
}

EarthArmy::~EarthArmy()
{
	delete t;
	delete es;
	delete g;
	delete hl;
	delete uml;
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
	case HU_:
		return hl->pickHealer();
		break;
	default:
		return nullptr;
		break;
	}
}
