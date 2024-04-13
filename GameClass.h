#pragma once
#include "Army units/EarthArmy.h"
#include "Army units/AlienArmy.h"
#include "randGen.h"
#include <iostream>
#include <fstream>
using namespace std;
class GameClass
{
private:
	EarthArmy* EArmy;
	AlienArmy* AArmy;
	randGen* randGenerator;
public:

	EarthArmy* getEArmy();
	AlienArmy* getAArmy();
	void initializer();
	void loadData();//needs to be edited
};

