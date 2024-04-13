#include "GameClass.h"
GameClass::GameClass()
{
    crntTime = 0;
    this->AArmy = new AlienArmy();
    this->EArmy = new EarthArmy();
    this->randGenerator = new randGen(this);
    this->klst = new KilledList();
}

void GameClass::incrementTime()
{
    crntTime++;
}

int GameClass::getTime() const
{
    return crntTime;
}

EarthArmy* GameClass::getEArmy()
{
	return EArmy;
}

AlienArmy* GameClass::getAArmy()
{
	return AArmy;
}

void GameClass::initializer()//needs to be modified
{
	loadData();
	randGenerator->generator();
}

void GameClass::loadData()
{
    int N, prob, ESPer, ETPer, EGPer, EUPstart, EUPend, EHstart, EHend, EACapstart, EACapend,
        ASPer, AMPer, ADPer, AUPstart, AHstart, AACapstart, AUPend, AHend, AACapend;
    ifstream dataFile("data.txt");
    int a;
    if (!dataFile)
        cout << "the file is not found" << endl;
    else
    {
        //according to the input file's order
        dataFile >> N >> ESPer >> ETPer >> EGPer >> ASPer >> AMPer >> ADPer >> prob >>
            EUPstart >> EUPend >> EHstart >> EHend >> EACapstart >> EACapend >>	//ranges for earths' units
            AUPstart >> AUPend >> AHstart >> AHend >> AACapstart >> AACapend;	//ranges for aliens' units
        //for the - sign in the input file (needs to be in a better way)
        EUPend = abs(EUPend);   AUPend = abs(AUPend);
        EHend = abs(EHend);     AHend = abs(AHend);
        EACapend = abs(EACapend);   AACapend = abs(AACapend);
    }
	    randGenerator->setParameters(N, prob, ESPer, ETPer, EGPer, EUPstart, EHstart, EACapstart, EUPend, EHend, EACapend,
		ASPer, ADPer, AMPer, AUPstart, AHstart, AACapstart, AUPend, AHend, AACapend);
}

ArmyUnit* GameClass::PickUnit(unitType unit,ArmyUnit* d1 = nullptr, ArmyUnit* d2=nullptr)
{
    switch (unit)
    {
    case ES:
        return EArmy->pickEUnit(ES);
    case ET:
        return EArmy->pickEUnit(ET);
    case EG:
        return EArmy->pickEUnit(EG);
    case AS:
        return AArmy->PickAunit(AS,d1,d2);
    case AM:
        return AArmy->PickAunit(AM, d1, d2);
    case AD:
        return AArmy->PickAunit(AD, d1, d2);
    default:
        return nullptr;
    }
}

void GameClass::insert(ArmyUnit* unt)
{
    switch (unt->getType())
    {
    case ES:
    case ET:
    case EG:
       EArmy->AddUnit(unt); break;
    case AS:
    case AM:
    case AD:
         AArmy->AddUnit(unt); break;

    }
}

bool GameClass::AddToKilledList(ArmyUnit* unit)
{
    return klst->addUnit(unit);
}



