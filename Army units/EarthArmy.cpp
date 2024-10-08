#include "EarthArmy.h"

EarthArmy::EarthArmy() {
	t = new GenStackADT;
	es = new GenQueueADT;
	g = new GunneryADT;
	hl = new GenStackADT;
	uml = new UML;
	id = 0;
	totalHealed = 0;
}

int EarthArmy::getId()
{
	return ++id;
}
bool EarthArmy::checkID() {
	return id < 999;
}
void EarthArmy::addUnit(ArmyUnit* unit)  
{
	 
	unitType type = unit->getType();
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

void EarthArmy::printArmy()
{
	cout << "=============== Earth Army Alive Units===============\n";
	cout << "ES ";
	es->printList();
	cout << "ET ";
	t->printList();
	g->printGunnerys();
	cout << "HU ";
	hl->printList();
	uml->printList();
	cout << "Percentage of Infected Soldiers: "<<((countOfInfected())? countOfInfected()*100.0/countOf(ES):0)<<"%\n";

}

int EarthArmy::getCount() const
{
	return es->getCount() + t->getCount() + g->getCount() + hl->getCount();
}

int EarthArmy::countOf(unitType ut)
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
int EarthArmy::countTotalInf()	//returns the total count of infected + immune soldiers
{
	return es->getImmuneCount() + countOfInfected() + uml->getTotalInfCount();
}

ArmyUnit* EarthArmy::pickFromUML()
{
	return  uml->pickUnit();
}

void EarthArmy::setThreshold(int limit)
{
	threshold = limit;
}

bool EarthArmy::addToUML(ArmyUnit* unit)
{
	if ((unit->getHealth() < 0.2 * unit->getStartHlth() && (unit->getType() == ET || unit->getType() == ES))) {
		unit->setTjUML();
		return uml->addUnit(unit);
	}
	else
		return false;
	
}


bool EarthArmy::limitReached()//if the percentage of infected solidiers surpassed a certain threshold this returns true
{
	if (!countOf(ES)) return false;
	return (countOfInfected() * 100.0 / countOf(ES) >= threshold);
}

int EarthArmy::getUMLESCount()
{
	return uml->getESCount();
}

EarthArmy::~EarthArmy()
{
	delete t;
	delete es;
	delete g;
	delete hl;
	delete uml;
}

void EarthArmy::incHealed()
{
	totalHealed++;
}
int EarthArmy::getHealedCount()
{
	return totalHealed;
}

ArmyUnit* EarthArmy::pickEUnit(unitType u)
{
	switch (u)
	{
	case ES:
	return es->pickUnit();
		break;
	case ET:
	return t->pickUnit();
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

int EarthArmy::getUMLCount()
{
	return uml->getCount();
}

ArmyUnit* EarthArmy::pickInfUnit()
{
	return es->pickInfected();
}

void EarthArmy::spreadInfection()
{
	int numOfInfected = es->getInfectedCount();
	while (numOfInfected--)
	{
		random_device rd;
		mt19937 gen(rd());
		int infectionSpreadProb = (gen() % (101)); //(rand() % (ub - lb + 1)) + lb
		if (infectionSpreadProb < 2)
		{
			es->infectRandomly();
		}
	}
}
