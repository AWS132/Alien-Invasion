#pragma once
#include "../Game/GameClass.h"
#include "../Army units/ArmyUnit.h"
#include "../Army units/EarthArmy.h"
#include "../Army units/AlienArmy.h"
#include <random>
#include <time.h>
class GameClass;
class randGen
{
private:
	GameClass* game;
	// pc stands for PerCentage
	int ESpc, ETpc, EGpc, HUpc, EUP1, EH1, EACap1, EUP2, EH2, EACap2,	//earth attack cap //(1-->start , 2-->end) boundaries of ranges 
		ASpc, ADpc, AMpc, AUP1, AH1, AACap1, AUP2, AH2, AACap2,	//alien attack cap 
		N, prob,infection_Prob;
public:
	ArmyUnit* createUnit(unitType type);	//utility function
	randGen(GameClass* game);
	void generator();
	void setParameters(int N, int prob, int ESPer, int ETPer, int EGPer, int HUPer, int EUPstart, int EHstart, int EACapstart, int EUPend, int EHend, int EACapend,
		int ASPer, int ADPer, int AMPer, int AUPstart, int AHstart, int AACapstart, int AUPend, int AHend, int AACapend,int infProb);
	int getInfection_perc();
};
