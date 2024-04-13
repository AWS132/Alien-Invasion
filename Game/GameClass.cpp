#include "GameClass.h"

GameClass::GameClass()
{
    crntTime = 0;
    this->randGenerator = nullptr;
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
        this->randGenerator = new randGen(this);
	    randGenerator->setParameters(N, prob, ESPer, ETPer, EGPer, EUPstart, EHstart, EACapstart, EUPend, EHend, EACapend,
		ASPer, ADPer, AMPer, AUPstart, AHstart, AACapstart, AUPend, AHend, AACapend);
}
