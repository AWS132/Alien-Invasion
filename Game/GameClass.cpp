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
    PrintGame();
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

void GameClass::initializer()
{
    if(crntTime==0)
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
        //for the - sign in the input file
        EUPend = abs(EUPend);   AUPend = abs(AUPend);
        EHend = abs(EHend);     AHend = abs(AHend);
        EACapend = abs(EACapend);   AACapend = abs(AACapend);
    }
	    randGenerator->setParameters(N, prob, ESPer, ETPer, EGPer, EUPstart, EHstart, EACapstart, EUPend, EHend, EACapend,
		ASPer, ADPer, AMPer, AUPstart, AHstart, AACapstart, AUPend, AHend, AACapend);
}

ArmyUnit* GameClass::PickUnit(unitType unit,ArmyUnit*& d1, ArmyUnit*& d2,int dm)
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
        return AArmy->PickAunit(AD, d1, d2,dm);
    default:
        return nullptr;
    }
}


bool GameClass::AddToKilledList(ArmyUnit* unit)
{
    if (unit)
        return klst->addUnit(unit);
    else return false;
}

void GameClass::PrintGame() const
{
    cout << "Current time step: " << this->crntTime<<endl;
    EArmy->PrintArmy();
    AArmy->PrintArmy();
    klst->printKilled();
    cout << "==============================================================================\n\n";
}

void GameClass::AddUnit(ArmyUnit* u1)
{
    if(u1)
    {
        switch (u1->getType())
        {
        case ES:
        case ET:
        case EG:
            EArmy->AddUnit(u1); break;
        case AS:
        case AM:
        case AD:
            AArmy->AddUnit(u1); break;
        }
    }
}

void GameClass::TmpListfn(unitType type, int capacity, int damage)
{
    ArmyUnit* nl1 = nullptr ,*nl2 =nullptr;
    tmpList tmpLst;
    if (type == AD)
    {
        for (int i = 0; i < capacity/2; i++)
        {
            PickUnit(type, nl1, nl2);
            if(nl1)
            { 
            nl1->DecHlth(damage);
            tmpLst.addUnit(nl1);

            }
            if(nl2)
            { 
            nl2->DecHlth(damage);
            tmpLst.addUnit(nl2);
            }
        }
    }
    else
    { 
        for (int i = 0; i < capacity; i++)
        {
            ArmyUnit* unt = PickUnit(type, nl1, nl2);
            if (unt) {
                unt->DecHlth(damage);
                tmpLst.addUnit(unt);
            }
        }
    }
    int count = tmpLst.getCount();
    for (int i = 0; i < count; i++)
    {
        nl1=tmpLst.PickUnit();
        AddUnit(nl1);
    }
}

int GameClass::CountOf(unitType ut)
{
    switch (ut)
    {
    case ES:
    case ET:
    case EG:
        return EArmy->CountOf(ut);
    case AS:
    case AM:
    case AD:    
        return AArmy->CountOf(ut);
    default:return 0;
    }
}




