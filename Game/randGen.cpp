#include "../Game/randGen.h"
#include "../Army units/Tanks.h"
#include "../Army units/Esoldier.h"
#include "../Army units/Asoldier.h"
#include "../Army units/Tank.h"
#include "../Army units/Gunnery.h"
#include "../Army units/Monster.h"
#include "../Army units/HU.h"
ArmyUnit* randGen::createUnit(unitType type)
{
	random_device rd;
	mt19937 gen(rd());
	int Upwr = (gen() % (EUP2 - EUP1 + 1)) + EUP1;
	int h = (gen() % (EH2 - EH1 + 1)) + EH1;
	int atk = (gen() % (EACap2 - EACap1 + 1)) + EACap1;
	/*int eID = game->getEArmy()->getId();
	int aID = game->getAArmy()->getId();*/
	int ID = (type == 6 || type < 3) ? game->getEArmy()->getId() : game->getAArmy()->getId();
	int tj = game->getTime();
	ArmyUnit* createdUnit = nullptr;
	switch (type)
	{
	case ES:
		createdUnit = new Esoldier(/*eID*/ID, tj, h, Upwr, atk, game);
		break;
	case ET:
		createdUnit = new Tank(/*eID*/ID, tj, h, Upwr, atk, game);
		break;
	case EG:
		createdUnit = new Gunnery(/*eID*/ID, tj, h, Upwr, atk, game);
		break;
	case HU_:
		createdUnit = new HU(/*eID*/ID, tj, h, Upwr, atk, game);
		break;
	case AS:
		createdUnit = new Asoldier(/*aID*/ID, tj, h, Upwr, atk, game);
		break;
	case AM:
		createdUnit = new Monster(/*aID*/ID, tj, h, Upwr, atk, game);
		break;
	case AD:
		createdUnit = new Drone(/*aID*/ID, tj, h, Upwr, atk, game);
		break;
	default:
		createdUnit = nullptr;

	}
	return createdUnit;
}



randGen::randGen(GameClass* game)
{
	this->game = game;
}

void randGen::generator()
{
	game->incrementTime();
	random_device rd;
	mt19937 gen(rd());

	int A = (gen() % (100)) + 1;    //(rand() % (ub - lb + 1)) + lb

	if (A <= prob) {
		//for earth
		for (int i{};i < N;i++) {
			random_device rd;
			mt19937 gen(rd());
			int B = (gen() % (100)) + 1;	//(rand() % (ub - lb + 1)) + lb			
			if (B <= ESpc) {
				game->getEArmy()->AddUnit(createUnit(ES));
			}
			else if (B <= ESpc + ETpc) {
				game->getEArmy()->AddUnit(createUnit(ET));
			}
			else if (B <= ESpc + ETpc + EGpc)
				game->getEArmy()->AddUnit(createUnit(EG));
			else
				game->getEArmy()->AddUnit(createUnit(HU_));
		}
		//for aliens
		for (int i{};i < N;i++) {
			random_device rd;
			mt19937 gen(rd());
			int B = (gen() % (100)) + 1;	//(rand() % (ub - lb + 1)) + lb			
			if (B <= ASpc) {
				game->getAArmy()->AddUnit(createUnit(AS));
			}
			else if (B <= ASpc + AMpc) {
				game->getAArmy()->AddUnit(createUnit(AM));
			}
			else
				game->getAArmy()->AddUnit(createUnit(AD));
		}
	}

}

void randGen::setParameters(int N, int prob, int ESPer, int ETPer, int EGPer, int HUPer, int EUPstart, int EHstart, int EACapstart, int EUPend, int EHend, int EACapend,
	int ASPer, int ADPer, int AMPer, int AUPstart, int AHstart, int AACapstart, int AUPend, int AHend, int AACapend)
{
	this->N = N;
	this->prob = prob;
	this->ESpc = ESPer; this->ETpc = ETPer; this->EGpc = EGPer; HUpc = HUPer;	//setting Earths' %
	EUP1 = EUPstart; EH1 = EHstart; EACap1 = EACapstart; EUP2 = EUPend; EH2 = EHend; EACap2 = EACapend;	//setting Earths' ranges
	ASpc = ASPer;  ADpc = ADPer, AMpc = AMPer;	//setting Aliens' %
	AUP1 = AUPstart; AH1 = AHstart; AACap1 = EACapstart; AUP2 = AUPend; AH2 = AHend; AACap2 = AACapend;	//setting Aliens' ranges
}
