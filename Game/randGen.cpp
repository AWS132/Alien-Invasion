#include "../Game/RandGen.h"
#include "../Army units/GenStackADT.h"
#include "../Army units/Esoldier.h"
#include "../Army units/Asoldier.h"
#include "../Army units/Tank.h"
#include "../Army units/Gunnery.h"
#include "../Army units/Monster.h"
#include "../Army units/HU.h"
#include "../Army units/SU.h"
ArmyUnit* RandGen::createUnit(unitType type)
{
	random_device rd;
	mt19937 gen(rd());
	int Upwr;
	int h;
	int atk;
	int ID;
	if (type < 4) {
		Upwr = (gen() % (EUP2 - EUP1 + 1)) + EUP1;
		h = (gen() % (EH2 - EH1 + 1)) + EH1;
		atk = (gen() % (EACap2 - EACap1 + 1)) + EACap1;
		ID = game->getEArmy()->getId();
	}
	else if (type < 7) {
		Upwr = (gen() % (AUP2 - AUP1 + 1)) + AUP1;
		h = (gen() % (AH2 - AH1 + 1)) + AH1;
		atk = (gen() % (AACap2 - AACap1 + 1)) + AACap1;
		ID = game->getAArmy()->getId();
	}
	else {
		Upwr = (gen() % (SUP2 - SUP1 + 1)) + SUP1;
		h = (gen() % (SH2 - SH1 + 1)) + SH1;
		atk = (gen() % (SACap2 - SACap1 + 1)) + SACap1;
		ID = game->getSArmy()->getId();
	}

	int tj = game->getTime();
	ArmyUnit* createdUnit = nullptr;
	switch (type)
	{
	case ES:
		createdUnit = new Esoldier(ID, tj, h, Upwr, atk, game);
		break;
	case ET:
		createdUnit = new Tank(ID, tj, h, Upwr, atk, game);
		break;
	case EG:
		createdUnit = new Gunnery(ID, tj, h, Upwr, atk, game);
		break;
	case HU_:
		createdUnit = new HU(ID, tj, h, Upwr, atk, game);
		break;
	case AS:
		createdUnit = new Asoldier(ID, tj, h, Upwr, atk, game);
		break;
	case AM:
		createdUnit = new Monster(ID, tj, h, Upwr, atk, game);
		break;
	case AD:
		createdUnit = new Drone(ID, tj, h, Upwr, atk, game);
		break;
	case SU_:
		createdUnit = new SU(ID, tj, h, Upwr, atk, game);
		break;
	default:
		createdUnit = nullptr;

	}
	return createdUnit;
}



RandGen::RandGen(GameClass* game)
{
	this->game = game;
}

void RandGen::generator()
{
	game->incrementTime();
	random_device rd;
	mt19937 gen(rd());

	int A = (gen() % (100)) + 1;    //(rand() % (ub - lb + 1)) + lb

	if (A <= prob) {
		//for earth
		for (int i{}; i < N; i++) {
			if (game->getEArmy()->checkID()) {
				random_device rd;
				mt19937 gen(rd());
				int B = (gen() % (100)) + 1;	//(rand() % (ub - lb + 1)) + lb			
				if (B <= ESpc) {
					game->getEArmy()->addUnit(createUnit(ES));
				}
				else if (B <= ESpc + ETpc) {
					game->getEArmy()->addUnit(createUnit(ET));
				}
				else if (B <= ESpc + ETpc + EGpc)
					game->getEArmy()->addUnit(createUnit(EG));
				else
					game->getEArmy()->addUnit(createUnit(HU_));
			}
		}
		//for aliens

		for (int i{}; i < N; i++) {
			if (game->getAArmy()->checkID()) {
				random_device rd;
				mt19937 gen(rd());
				int B = (gen() % (100)) + 1;	//(rand() % (ub - lb + 1)) + lb			
				if (B <= ASpc) {
					game->getAArmy()->addUnit(createUnit(AS));
				}
				else if (B <= ASpc + AMpc) {
					game->getAArmy()->addUnit(createUnit(AM));
				}
				else
					game->getAArmy()->addUnit(createUnit(AD));
			}
		}
	}
	//for Ally units
	if (A <= Sprob && game->getSArmy()->getStatus()) {
		for (int i = 0; i < SN; i++) {
			if (game->getSArmy()->checkID())
				game->getSArmy()->addUnit(createUnit(SU_));
		}
	}
}

void RandGen::setParameters(int N, int prob, int sn, int sprob, int ESPer, int ETPer, int EGPer, int HUPer, int EUPstart, int EHstart, int EACapstart, int EUPend, int EHend, int EACapend,
	int ASPer, int ADPer, int AMPer, int AUPstart, int AHstart, int AACapstart, int AUPend, int AHend, int AACapend, int SHstart, int SHend, int SPstart, int SPend, int SCstart, int SCend, int infProb)
{
	this->N = N;
	this->prob = prob;
	SN = sn;
	Sprob = sprob;
	this->ESpc = ESPer; this->ETpc = ETPer; this->EGpc = EGPer; HUpc = HUPer;	//setting Earths' %
	EUP1 = EUPstart; EH1 = EHstart; EACap1 = EACapstart; EUP2 = EUPend; EH2 = EHend; EACap2 = EACapend;	//setting Earths' ranges
	ASpc = ASPer;  ADpc = ADPer, AMpc = AMPer;	//setting Aliens' %
	AUP1 = AUPstart; AH1 = AHstart; AACap1 = AACapstart; AUP2 = AUPend; AH2 = AHend; AACap2 = AACapend;	//setting Aliens' ranges
	SUP1 = SPstart; SUP2 = SPend; SH1 = SHstart; SH2 = SHend; SACap1 = SCstart; SACap2 = SCend;
	infectionProb = infProb;
}

int RandGen::getInfectionPerc()
{
	return infectionProb;
}
