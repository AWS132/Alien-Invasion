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
	random_device rd;
	mt19937 gen(rd());
	int Upwr = (gen() % (EUP2 - EUP1 + 1)) + EUP1;
	int h = (gen() % (EH2 - EH1 + 1)) + EH1;
	int atk = (gen() % (EACap2 - EACap1 + 1)) + EACap1;
	int eID = game->getEArmy()->getId();
	int aID = game->getAArmy()->getId();
	int tj = game->getTime();
	ArmyUnit* createdUnit=nullptr;
    switch (type)
	{
    case ES:
		createdUnit = new Esoldier(eID, tj, h, Upwr, atk,game);
	 break;
	case ET:
		createdUnit = new Tank(eID, tj, h, Upwr, atk,game);
		 break;
	case EG:
		createdUnit = new Gunnery(eID, tj, h, Upwr, atk,game);
		 break;
	case AS:
		createdUnit = new Asoldier(aID, tj, h, Upwr, atk,game);
		 break;
	case AM:
		createdUnit = new Monster(aID, tj, h, Upwr, atk,game);
		 break;
	case AD:
		createdUnit = new Drone(aID, tj, h, Upwr, atk,game);
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

    int A = (gen() % (100)) + 1;    //(rand() % (ub - lb + 1)) + lb

    if (A <= prob)//!!!!!NEEDS TO BE CHANGED!!!!!!
    {
        //for earth
        float  S = N * ESpc / 100.0, T = N * ETpc / 100.0, G = N * EGpc / 100.0;
        if (S / 1 == 0) S = ceil(S);
        if (T / 1 == 0) T = ceil(T);
        if (G / 1 == 0) G = ceil(G);
		for (int i = 0; i < N; i++)
        {
            if (i < S)
                game->getEArmy()->AddUnit(createUnit(ES));
            else if (i < S + T)
                game->getEArmy()->AddUnit(createUnit(ET));
            else
                game->getEArmy()->AddUnit(createUnit(EG));
        }
        //for aliens
        float So = N * ASpc / 100.0, M = N * AMpc / 100.0, D = N * ADpc / 100;
        if (So / 1 == 0) So = ceil(So);
        if (M / 1 == 0) M = ceil(M);
        if (D / 1 == 0) D = ceil(D);
        for (int i{}; i < N; i++) {

            if (i < So) {
                game->getAArmy()->AddUnit(createUnit(AS));
            }
            else if (i < So + M) {
                game->getAArmy()->AddUnit(createUnit(AM));
            }
            else
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
	ASpc = ASPer;  ADpc= ADPer,   AMpc= AMPer;	//setting Aliens' %
	AUP1 = AUPstart; AH1 = AHstart; AACap1 = EACapstart; AUP2 = AUPend; AH2 = AHend; AACap2 = AACapend;	//setting Aliens' ranges

	//this->prob = prob;
	//this->EUP1 = EUPstart; this->EH1 = EHstart; this->EACap1 = EACapstart; this->EUP2 = EUPend; this->EH2 = EHend; this->EACap2 = EACapend;	//setting Earths' ranges

}
