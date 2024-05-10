#include "GameClass.h"
#include <fstream>
#include <iostream>
using namespace std;
GameClass::GameClass()
{
    crntTime = 0;
    this->AArmy = new AlienArmy();
    this->EArmy = new EarthArmy();
    this->randGenerator = new randGen(this);
    this->klst = new genQueueADT();
}

void GameClass::incrementTime()
{
    crntTime++;
}

int GameClass::getTime() const
{
    return crntTime;
}

EarthArmy* GameClass::getEArmy()
{
	return EArmy;
}

AlienArmy* GameClass::getAArmy()
{
	return AArmy;
}

void GameClass::initializer(int flag, int fileName)
{
    loadData(fileName);
    if (flag)
        cout << "Active Mode\n";
    else
        cout << "Silent Mode\n";
    cout << "Simulation Starts.....\n";
    while ((EArmy->getCount() && AArmy->getCount() || crntTime <= 40))
    {
        EArmy->SpreadInfection();
        randGenerator->generator();
        if (flag)
            PrintArmies();
        pokeUnits(flag);
        if (flag) {
            cout << "=======================Killed/destructed units=======================\n";
            klst->printList();
            cout << "==============================================================================\n\n";
            //   cout << "Press Enter to Continue";
              // cin.ignore();
        }
    }
    int x;// used to send the winner to the output file
    if (!EArmy->getCount() && AArmy->getCount()) {
        x = 0;
        if (flag)
            cout << "Aliens won the war\n";
    }
    else if (!AArmy->getCount() && EArmy->getCount()) {
        x = 1;
        if (flag)
            cout << "Humans won the war\n";
    }
    else {
        x = -1;
        if (flag)
            cout << "the battle ended up as a draw\n";
    }
    createOFile(x);
    cout << "Simulation Ends, output file is created\n";
}

void GameClass::pokeUnits(int flag)
{
    ArmyUnit* nl1 = nullptr;
    ArmyUnit* nl2 = nullptr;
   
    if (flag)
        cout << "===========Units Fighting at Current Step=============\n";
    if (EArmy->CountOf(ET))
        EArmy->peekEUnit(ET)->Attack(flag);
    if (EArmy->CountOf(EG))
        EArmy->peekEUnit(EG)->Attack(flag);
    if (EArmy->CountOf(ES))
        EArmy->peekEUnit(ES)->Attack(flag);
    if (AArmy->CountOf(AM))
        AArmy->peekAunit(AM, nl1, nl2)->Attack(flag);
    if (AArmy->CountOf(AS))
        AArmy->peekAunit(AS, nl1, nl2)->Attack(flag);
    if (AArmy->CountOf(AD)) {
        AArmy->peekAunit(AD, nl1, nl2);
        if (nl1 && nl2) {
            nl1->Attack(flag);
            nl2->Attack(flag);
        }
    }
    if (EArmy->CountOf(HU_))
        EArmy->peekEUnit(HU_)->Attack(flag);    
}

void GameClass::loadData(int fileName)
{
    int N, prob, ESPer, ETPer, EGPer, HUPer, EUPstart, EUPend, EHstart, EHend, EACapstart, EACapend,
        ASPer, AMPer, ADPer, AUPstart, AHstart, AACapstart, AUPend, AHend, AACapend, infection_Prob;
    string s;
    switch (fileName) {
    case(2):
        s = "2";
        break;
    case(3):
        s = "3";
        break;
    case(4):
        s = "4";
        break;
    case(5):
        s = "5";
        break;
    case(6):
        s = "6";
        break;
    default:
        s = "1";
        break;

    }
    ifstream dataFile("Inputs/data (" + s + ").txt");
    if (!dataFile)
        cout << "File is not found" << endl;
    else
    {
        //according to the input file's order
        dataFile >> N >> ESPer >> ETPer >> EGPer >> HUPer >> ASPer >> AMPer >> ADPer >> prob >>infection_Prob>>
            EUPstart >> EUPend >> EHstart >> EHend >> EACapstart >> EACapend >>	//ranges for earths' units
            AUPstart >> AUPend >> AHstart >> AHend >> AACapstart >> AACapend;	//ranges for aliens' units
        //for the - sign in the input file
        EUPend = abs(EUPend);   AUPend = abs(AUPend);
        EHend = abs(EHend);     AHend = abs(AHend);
        EACapend = abs(EACapend);   AACapend = abs(AACapend);
    }
    randGenerator->setParameters(N, prob, ESPer, ETPer, EGPer, HUPer, EUPstart, EHstart, EACapstart, EUPend, EHend, EACapend,
        ASPer, ADPer, AMPer, AUPstart, AHstart, AACapstart, AUPend, AHend, AACapend, infection_Prob);
}

ArmyUnit* GameClass::PickUnit(unitType unit,ArmyUnit*& d1, ArmyUnit*& d2,int dm)

 {
    switch (unit)
    {
    case ES:
        return EArmy->pickEUnit(ES);
    case ET:
        return EArmy->pickEUnit(ET);
    case EG:
        return EArmy->pickEUnit(EG);
    case AS:
        return AArmy->PickAunit(AS,d1,d2);
    case AM:
        return AArmy->PickAunit(AM, d1, d2);
    case AD:
        return AArmy->PickAunit(AD, d1, d2,dm);
    default:
        return nullptr;
    }
}


bool GameClass::AddToKldList(ArmyUnit* unit)
{
    if (unit)
        return klst->addUnit(unit);
    else return false;
}

void GameClass::PrintArmies() const
{
    cout << "Current time step: " << this->crntTime<<endl;
    EArmy->PrintArmy();
    AArmy->PrintArmy();
  
}

void GameClass::AddUnit(ArmyUnit* u1/*, bool flag*/)
{
    if(u1)
    {
        switch (u1->getType())
        {
        case ES:
        case ET:
        case EG:
            EArmy->AddUnit(u1/*,flag*/); break;
        case AS:
        case AM:
        case AD:
            AArmy->AddUnit(u1/*,flag*/); break;
        }
    }
}

void GameClass::createOFile(int winner)
{

    ofstream oFile("output.txt");
//// Earth ouput 
    int S, T, G,Df,Dd;
    oFile << "Earth Destructed units:\n";
    klst->outKilled(oFile,S,T,G,Df,Dd);
    oFile << "Battle result:";
    if (winner == 1)
        oFile << " Win";
    else if (winner == 0)
        oFile << " Lose";
    else
        oFile << " Draw";
    oFile << endl;
    oFile << "Total ES: " << S + EArmy->CountOf(ES) << endl;
    oFile << "Total ET: " << T + EArmy->CountOf(ET) << endl;
    oFile << "Total EG: " << G + EArmy->CountOf(EG) << endl;
    oFile << "Percentage of ES: " << double(S) / (S + EArmy->CountOf(ES)) << endl;
    oFile << "Percentage of ET: " << double(T) / (T + EArmy->CountOf(ET)) << endl;
    oFile << "Percentage of EG: " << double(G) / (G + EArmy->CountOf(EG)) << endl;
    oFile << "Percentage of Total destructed unites to Total units: " << double(S + G + T) / (S + G + T + EArmy->getCount()) << endl;
    oFile << "Average of Df: " << double(Df) / (S + G + T) << endl;
    oFile << "Average of Dd: " << double(Dd) / (S + G + T) << endl;
    oFile << "Average of Db: " << double(Df + Dd) / (S + G + T) << endl;
    oFile << "Df/Db: " << double(Df) / (Df + Dd) * 100 << endl;
    oFile << "Dd/Db: " << double(Dd) / (Df + Dd) * 100 << endl;
//// Alien output 
    oFile << "Alien Destructed units:\n";
    klst->outKilled(oFile, S, T, G, Df, Dd, 3);
    oFile << "Battle result:";
    if (winner == 0)
        oFile << " Win";
    else if (winner == 1)
        oFile << " Lose";
    else
        oFile << " Draw";
    oFile << endl;
    oFile << "Total AS: " << S + AArmy->CountOf(AS) << endl;
    oFile << "Total AM: " << T + AArmy->CountOf(AM) << endl;
    oFile << "Total AD: " << G + EArmy->CountOf(AD) << endl;
    oFile << "Percentage of AS: " << double(S) / (S + AArmy->CountOf(AS)) << endl;
    oFile << "Percentage of AM: " << double(T) / (T + AArmy->CountOf(AM)) << endl;
    oFile << "Percentage of AD: " << double(G) / (G + AArmy->CountOf(AD)) << endl;
    oFile << "Percentage of Total destructed unites to Total units: " << double(S + G + T) / (S + G + T + AArmy->getCount()) << endl;
    oFile << "Average of Df: " << double(Df) / (S + G + T) << endl;
    oFile << "Average of Dd: " << double(Dd) / (S + G + T) << endl;
    oFile << "Average of Db: " << double(Df + Dd) / (S + G + T) << endl;
    oFile << "Df/Db: " << double(Df) / (Df + Dd) * 100 << endl;
    oFile << "Dd/Db: " << double(Dd) / (Df + Dd) * 100 << endl;
}

int GameClass::CountOf(unitType ut)
{
    switch (ut)
    {
    case ES:
    case ET:
    case EG:
        return EArmy->CountOf(ut);
    case AS:
    case AM:
    case AD:    
        return AArmy->CountOf(ut);
    default:return 0;
    }
}

int GameClass::getInfection_perc()
{
    return randGenerator->getInfection_perc();
}




