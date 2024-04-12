#include "randGen.h"
#include "Army units/Tanks.h"
ArmyUnit* randGen::createUnit(int type)
{
	stack<ArmyUnit*> createdUnit;
    switch (type) {
    case ES:
		srand(time(0));
		int upwr = (rand() % (EUP2 - EUP1 + 1)) + EUP1;
		int h = (rand() % (EH2 - EH1 + 1)) + EH1;
		int atk = (rand() % (EACap2 - EACap1 + 1)) + EACap1;
		
		ArmyUnit* es = new ArmyUnit(0, ES, 0, h, upwr, atk);//id and tj need to be modified
		return es;
	case ET:
    }
}

ArmyUnit* randGen::generator()
{

	srand(time(0));
	int A = (rand() % (100 - 1 + 1)) + 1;	//(rand() % (ub - lb + 1)) + lb
	if (A <= prob) {
		//for earth
		for (int i{};i < N;i++) {
			int B = (rand() % (100 - 1 + 1)) + 1;	//(rand() % (ub - lb + 1)) + lb			
			if (B <= ESpc) {
				game->getEArmy()->addUnit(createUnit(ES));
			}
			else if (B <= ESpc + ETpc) {

			}
		
		}
		//for aliens
		for (int i{};i < N;i++) {
			int B = (rand() % (100 - 1 + 1)) + 1;	//(rand() % (ub - lb + 1)) + lb			
			if (B <= ESpc) {
				game->getAArmy()->addUnit(createUnit(ES));
			}
			else if (B <= ESpc + ETpc) {

			}

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
