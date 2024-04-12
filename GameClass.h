#pragma once
#include "Army units/EarthArmy.h"
#include "Army units/AlienArmy.h"
#include "randGen.h"
class GameClass
{
private:
	EarthArmy* EArmy;
	AlienArmy* AArmy;
	randGen* randGenerator;
public:
	EarthArmy* getEArmy();
	AlienArmy* getAArmy();
	void loadData();//needs to be edited
};

