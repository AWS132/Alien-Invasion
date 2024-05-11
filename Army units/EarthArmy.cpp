#include "EarthArmy.h"

EarthArmy::EarthArmy() {
	t = new Tanks;
	es = new genQueueADT;
	g = new Gunnerys;
	hl = new genQueueADT;
	uml = new UML;
	id = 0;
}

int EarthArmy::getId() /*const*/
{
	id++;
	return id;
}

void EarthArmy::AddUnit(ArmyUnit* unit/*,bool flag*/)  // flag==>0 returning unit to its list from 
{
	 
	unitType type = unit->getType();
	//if(flag)
	//id += 1;
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
	cout << "ES ";
	es->printList();
	t->printTanks();
	g->printGunnerys();
	cout << "HU ";
	hl->printList();
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

int EarthArmy::countOfInfected()
{
	return es->getInfectedCount();
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
	return es->pickUnit();
		break;
	case ET:
	return t->pickTank();
		break;
	case EG:
	return g->pickGunnery();
		break;
	case HU_:
		return hl->pickUnit();
		break;
	default:
		return nullptr;
		break;
	}
}

ArmyUnit* EarthArmy::peekEUnit(unitType u)
{
	ArmyUnit* unt = nullptr;
	switch (u)
	{
	case ES:
		return (es->peek(unt),unt);
	case ET:
		return (t->peek(unt),unt);
	case EG:
		return (g->peek(unt), unt);
	case HU_:
		return (hl->peek(unt),unt);
	default:
		return nullptr;
	}
}

ArmyUnit* EarthArmy::pickInfUnit()
{
	return es->pickInfected();
}

void EarthArmy::SpreadInfection()
{
	int numOfInfected = es->getInfectedCount();
	while(numOfInfected--)
	{ 
		random_device rd;
		mt19937 gen(rd());
		int infectionSpreadProb = (gen() % (101)); //(rand() % (ub - lb + 1)) + lb
		if (infectionSpreadProb <2)
		{
			es->infectRandomly();
		}
	}
	

}
