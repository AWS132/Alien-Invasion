#pragma once
#include "GameClass.h"
#include "Army units/ArmyUnit.h"
#include "Army units/EarthArmy.h"
#include "Army units/AlienArmy.h"
class randGen
{
private: 
	GameClass* game;
	
	int ESpc, ETpc, EGpc, EUP1, EH1, EACap1, EUP2, EH2, EACap2,	//earth attack cap 1-->start , 2-->end boundaries of ranges 
		ASpc, ADpc, AMpc, AUP1, AH1, AACap1, AUP2, AH2, AACap2,	//alien attack cap 
		N, prob;
	ArmyUnit* createUnit(int type);	//utility function
public:
	ArmyUnit* generator();
	void setParameters(int N, int prob, int ESPer, int ETPer, int EGPer, int EUPstart, int EHstart, int EACapstart, int EUPend, int EHend, int EACapend,
		int ASPer, int ADPer, int AMPer, int AUPstart, int AHstart, int AACapstart, int AUPend, int AHend, int AACapend);
};
