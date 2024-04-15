#include "../Game/randGen.h"
#include "../Army units/Tanks.h"
#include "../Army units/Esoldier.h"
#include "../Army units/Asoldier.h"
#include "../Army units/Tank.h"
#include "../Army units/Gunnery.h"
#include "../Army units/Monster.h"
ArmyUnit* randGen::createUnit(unitType type)
{
	//stack<ArmyUnit*> createdUnit;
	srand(time(0));
	int Upwr = (rand() % (EUP2 - EUP1 + 1)) + EUP1;
	int h = (rand() % (EH2 - EH1 + 1)) + EH1;
	int atk = (rand() % (EACap2 - EACap1 + 1)) + EACap1;
	int eID = game->getEArmy()->getId();
	int aID = game->getAArmy()->getId();
	int tj = game->getTime();
	ArmyUnit* createdUnit=nullptr;
    switch (type)
	{
    case ES:
		createdUnit = new Esoldier(eID, tj, h, Upwr, atk);
	 break;
	case ET:
		createdUnit = new Tank(eID, tj, h, Upwr, atk);
		 break;
	case EG:
		createdUnit = new Gunnery(eID, tj, h, Upwr, atk);
		 break;
	case AS:
		createdUnit = new Asoldier(aID, tj, h, Upwr, atk);
		 break;
	case AM:
		createdUnit = new Monster(aID, tj, h, Upwr, atk);
		 break;
	case AD:
		createdUnit = new Drone(aID, tj, h, Upwr, atk);
		 break;
	default:
		createdUnit = nullptr;

    }
	return createdUnit;
}



randGen::randGen(GameClass*game)
{
	this->game = game;
}

void randGen::generator()
{
	game->incrementTime();
	random_device rd;
	mt19937 gen(rd());
	
	int A = (gen() % (100 - 1 + 1)) + 1;	//(rand() % (ub - lb + 1)) + lb
	cout << A<<endl;
	if (A <= prob)
	{
		//for earth
		for (int i{};i < N;i++) 
		{
			int B = (gen() % (100 - 1 + 1)) + 1;	//(rand() % (ub - lb + 1)) + lb			
			if (B <= ESpc) {
				game->getEArmy()->AddUnit(createUnit(ES));
			}
			else if (B <= ESpc + ETpc) {
				game->getEArmy()->AddUnit(createUnit(ET));
			}else
				game->getEArmy()->AddUnit(createUnit(EG));
		}
		//for aliens
		for (int i{};i < N;i++) {
			int B = (gen() % (100 - 1 + 1)) + 1;	//(rand() % (ub - lb + 1)) + lb			
			if (B <= ASpc) {
				game->getAArmy()->AddUnit(createUnit(AS));
			}
			else if (B <= ASpc + AMpc) {
				game->getAArmy()->AddUnit(createUnit(AM));
			}
			game->getAArmy()->AddUnit(createUnit(AD));
		}
	}
	
}

void randGen::setParameters(int N, int prob, int ESPer, int ETPer, int EGPer, int EUPstart, int EHstart, int EACapstart, int EUPend, int EHend, int EACapend,
	int ASPer, int ADPer, int AMPer, int AUPstart, int AHstart, int AACapstart, int AUPend, int AHend, int AACapend)
{
	this->N = N;
	this->prob = prob;
	this->ESpc = ESPer; this->ETpc = ETPer; this->EGpc = EGPer;	//setting Earths' %
	EUP1 = EUPstart; EH1 = EHstart; EACap1 = EACapstart; EUP2 = EUPend; EH2 = EHend; EACap2 = EACapend;	//setting Earths' ranges
	ASpc = ASPer; ADPer = ADpc, AMPer = AMpc;	//setting Aliens' %
	AUP1 = AUPstart; AH1 = AHstart; AACap1 = EACapstart; AUP2 = AUPend; AH2 = AHend; AACap2 = AACapend;	//setting Aliens' ranges

	//this->prob = prob;
	//this->EUP1 = EUPstart; this->EH1 = EHstart; this->EACap1 = EACapstart; this->EUP2 = EUPend; this->EH2 = EHend; this->EACap2 = EACapend;	//setting Earths' ranges

}
