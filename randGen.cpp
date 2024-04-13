#include "randGen.h"
#include "Army units/Tanks.h"
#include "Army units/Esoldier.h"
#include "Army units/Asoldier.h"
#include "Army units/Tank.h"
#include "Army units/Gunnery.h"
#include "Army units/Monster.h"
ArmyUnit* randGen::createUnit(int type)
{
	//stack<ArmyUnit*> createdUnit;
    switch (type) {
		srand(time(0));
		int Upwr = (rand() % (EUP2 - EUP1 + 1)) + EUP1;
		int h = (rand() % (EH2 - EH1 + 1)) + EH1;
		int atk = (rand() % (EACap2 - EACap1 + 1)) + EACap1;
		int eID = game->getEArmy()->getId();
		int aID = game->getAArmy()->getId();
		int tj = game->getTime();
    case ES:
		Esoldier* es = new Esoldier(eID, tj, h, Upwr, atk);
		return es;
	case ET:
		Tank* t = new Tank(eID, tj, h, Upwr, atk);
		return t;
	case EG:
		Gunnery* g = new Gunnery(eID, tj, h, Upwr, atk);
		return g;
	case AS:
		Asoldier* as = new Asoldier(aID, tj, h, Upwr, atk);
		return as;
	case AM:
		Monster* m = new Monster(aID, tj, h, Upwr, atk);
		return m;
	case AD:
		Drone* d = new Drone(aID, tj, h, Upwr, atk);
		return d;
	default:
		break;
    }
}

ArmyUnit* randGen::generator()
{
	game->incrementTime();
	srand(time(0));
	int A = (rand() % (100 - 1 + 1)) + 1;	//(rand() % (ub - lb + 1)) + lb
	if (A <= prob) {
		//for earth
		for (int i{};i < N;i++) {
			int B = (rand() % (100 - 1 + 1)) + 1;	//(rand() % (ub - lb + 1)) + lb			
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
			int B = (rand() % (100 - 1 + 1)) + 1;	//(rand() % (ub - lb + 1)) + lb			
			if (B <= ASpc) {
				game->getAArmy()->AddUnit(createUnit(AS));
			}
			else if (B <= ASpc + AMpc) {
				game->getEArmy()->AddUnit(createUnit(AM));
			}
			game->getEArmy()->AddUnit(createUnit(AD));
		}
	}

}

void randGen::setParameters(int N, int prob, int ESPer, int ETPer, int EGPer, int EUPstart, int EHstart, int EACapstart, int EUPend, int EHend, int EACapend,
	int ASPer, int ADPer, int AMPer, int AUPstart, int AHstart, int AACapstart, int AUPend, int AHend, int AACapend)
{


	ESpc = ESPer, ETPer = ETpc, EGPer = EGpc,	//setting Earths' %
		EUP1 = EUPstart, EH1 = EHstart, EACap1 = EACapstart, EUP2 = EUPend, EH2 = EHend, EACap2 = EACapend;	//setting Earths' ranges
	ASpc = ASPer, ADPer = ADpc, AMPer = AMpc,	//setting Aliens' %
		AUP1 = AUPstart, AH1 = AHstart, AACap1 = EACapstart, AUP2 = AUPend, AH2 = AHend, AACap2 = AACapend;	//setting Aliens' ranges


}
