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
    SArmy = new allyArmy();
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

allyArmy* GameClass::getSArmy()
{
    return SArmy;
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
        if (EArmy->limitReached())
            SArmy->call();
        if (!EArmy->countOfInfected())
            SArmy->withdraw();
        if (flag)
            PrintArmies();
        pokeUnits(flag);
        if (flag) {
            cout << "=======================Killed/destructed units=======================\n";
            klst->printList();
            cout << "==============================================================================\n\n";
            cout << "Press Enter to Continue";
            cin.ignore();
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
    if (AArmy->CountOf(AD)) 
    {
        AArmy->peekAunit(AD, nl1, nl2);
        if (nl1 && nl2) {
            nl1->Attack(flag);
            nl2->Attack(flag);
        }
    }
    if (EArmy->CountOf(HU_))
        EArmy->peekEUnit(HU_)->Attack(flag);
    if (SArmy->getCount()) 
        SArmy->peekSUnit()->Attack(flag);
}

void GameClass::loadData(int fileName)
{
    int N, prob, SN, SProb, ESPer, ETPer, EGPer, HUPer, EUPstart, EUPend, EHstart, EHend, EACapstart, EACapend,
        ASPer, AMPer, ADPer, AUPstart, AHstart, AACapstart, AUPend, AHend, AACapend, SUPstart, SHstart, SACapstart, SUPend, SHend, SACapend, infection_Prob, threshold;
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
        dataFile >> N >> SN >> ESPer >> ETPer >> EGPer >> HUPer >> ASPer >> AMPer >> ADPer >> prob >> SProb >> infection_Prob >> threshold >>
            EUPstart >> EUPend >> EHstart >> EHend >> EACapstart >> EACapend >>	//ranges for earths' units
            AUPstart >> AUPend >> AHstart >> AHend >> AACapstart >> AACapend >>	//ranges for aliens' units
            SUPstart >> SUPend >> SHstart >> SHend >> SACapstart >> SACapend;	//ranges for aliens' units
        //for the - sign in the input file
        EUPend = abs(EUPend);   AUPend = abs(AUPend); SUPend = abs(SUPend);
        EHend = abs(EHend);     AHend = abs(AHend); SHend = abs(SHend);
        EACapend = abs(EACapend);   AACapend = abs(AACapend); SACapend = abs(SACapend);
    }
    randGenerator->setParameters(N, prob, SN, SProb, ESPer, ETPer, EGPer, HUPer, EUPstart, EHstart, EACapstart, EUPend, EHend, EACapend,
        ASPer, ADPer, AMPer, AUPstart, AHstart, AACapstart, AUPend, AHend, AACapend, SHstart, SHend, SUPstart, SUPend, SACapstart, SACapend, infection_Prob);
    EArmy->setThreshold(threshold);
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
    case HU_:
        return EArmy->pickEUnit(HU_);
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
    SArmy->PrintArmy();
    
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
        case HU_:
            EArmy->AddUnit(u1/*,flag*/); break;
        case AS:
        case AM:
        case AD:
            AArmy->AddUnit(u1/*,flag*/); break;
        case SU_:
            SArmy->AddUnit(u1);
        }
    }
}

void GameClass::createOFile(int winner)
{
    ofstream oFile("output.txt");
    //// Earth ouput 
    int S, T, G, HU, Df, Dd;
    oFile << "Earth Destructed units:\n";
    klst->outKilled(oFile, S, T, G, HU, Df, Dd);
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
    oFile << "Total HU: " << HU + EArmy->CountOf(HU_) << endl;
    if (S + EArmy->CountOf(ES))
        oFile << "Percentage of ES: " << double(S) / (S + EArmy->CountOf(ES)) << endl;
    if (T + EArmy->CountOf(ET))
        oFile << "Percentage of ET: " << double(T) / (T + EArmy->CountOf(ET)) << endl;
    if (G + EArmy->CountOf(EG))
        oFile << "Percentage of EG: " << double(G) / (G + EArmy->CountOf(EG)) << endl;
    if (HU + EArmy->CountOf(HU_))
        oFile << "Percentage of HU: " << double(HU) / (HU + EArmy->CountOf(HU_)) << endl;
    if ((S + G + T + EArmy->getCount()))
        oFile << "Percentage of Total destructed unites to Total units: " << double(S + G + T) / (S + G + T + HU + EArmy->getCount()) << endl;
    if ((S + G + T + HU)) {
        oFile << "Average of Df: " << double(Df) / (S + G + T + HU) << endl;
        oFile << "Average of Dd: " << double(Dd) / (S + G + T + HU) << endl;
        oFile << "Average of Db: " << double(Df + Dd) / (S + G + T + HU) << endl;
    }
    if (Df + Dd) {
        oFile << "Df/Db: " << double(Df) / (Df + Dd) * 100 << endl;
        oFile << "Dd/Db: " << double(Dd) / (Df + Dd) * 100 << endl;
    }
    //// Alien output 
    oFile << "Alien Destructed units:\n";
    klst->outKilled(oFile, S, T, G, HU, Df, Dd, 4);
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
    if ( (S + AArmy->CountOf(AS)))
        oFile << "Percentage of AS: " << double(S) / (S + AArmy->CountOf(AS)) << endl;
    if ( (T + AArmy->CountOf(AM)))
        oFile << "Percentage of AM: " << double(T) / (T + AArmy->CountOf(AM)) << endl;
    if ((G + AArmy->CountOf(AD)))
        oFile << "Percentage of AD: " << double(G) / (G + AArmy->CountOf(AD)) << endl;
    if  (S + G + T + AArmy->getCount())
        oFile << "Percentage of Total destructed unites to Total units: " << double(S + G + T) / (S + G + T + AArmy->getCount()) << endl;
    if ((S + G + T)) {
        oFile << "Average of Df: " << double(Df) / (S + G + T) << endl;
        oFile << "Average of Dd: " << double(Dd) / (S + G + T) << endl;
        oFile << "Average of Db: " << double(Df + Dd) / (S + G + T) << endl;
    }
    if (Df + Dd) {
        oFile << "Df/Db: " << double(Df) / (Df + Dd) * 100 << endl;
        oFile << "Dd/Db: " << double(Dd) / (Df + Dd) * 100 << endl;
    }
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




