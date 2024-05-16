#include "GameClass.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
GameClass::GameClass()
{
    crntTime = 0;
    this->AArmy = new AlienArmy();
    this->EArmy = new EarthArmy();
    this->randGenerator = new RandGen(this);
    this->klst = new GenQueueADT();
    SArmy = new AllyArmy();
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

AllyArmy* GameClass::getSArmy()
{
    return SArmy;
}

void GameClass::initializer(bool gameMode) //resposible for the game logic
{
    //to load data from a valid input file
    int fileName;
    do {
    cout << "pick the number of the input file you want to select\n";
    cin >> fileName;
    } while (!loadData(fileName));
    if (gameMode)
        cout << "Active Mode\n";
    else
        cout << "Silent Mode\n";
    cout << "Simulation Starts.....\n";
    //the battle begins from here
    while ((EArmy->getCount() && AArmy->getCount() || crntTime <= 40))
    {
        EArmy->spreadInfection();
        randGenerator->generator();
        if (EArmy->limitReached())
            SArmy->call();
        if (!EArmy->countOfInfected())
            SArmy->withdraw();
        if (gameMode)
            printArmies();
        pokeUnits(gameMode);
        if (gameMode) {
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
        if (gameMode)
            cout << "Aliens won the war\n";
    }
    else if (!AArmy->getCount() && EArmy->getCount()) {
        x = 1;
        if (gameMode)
            cout << "Humans won the war\n";
    }
    else {
        x = -1;
        if (gameMode)
            cout << "the battle ended up as a draw\n";
    }
    createOFile(x);
    cout << "Simulation Ends, output file is created\n";
}

void GameClass::pokeUnits(bool gameMode) // a function to make aliens', earth's and allies' units attack each other
{
    ArmyUnit* nl1 = nullptr;
    ArmyUnit* nl2 = nullptr;
   
    if (gameMode)
        cout << "===========Units Fighting at Current Step=============\n";
    if (EArmy->countOf(ET))
        EArmy->peekEUnit(ET)->attack(gameMode);
    if (EArmy->countOf(EG))
        EArmy->peekEUnit(EG)->attack(gameMode);
    if (EArmy->countOf(ES))
        EArmy->peekEUnit(ES)->attack(gameMode);
    if (AArmy->countOf(AM))
        AArmy->peekAunit(AM, nl1, nl2)->attack(gameMode);
    if (AArmy->countOf(AS))
        AArmy->peekAunit(AS, nl1, nl2)->attack(gameMode);
    if (AArmy->countOf(AD)) 
    {
        AArmy->peekAunit(AD, nl1, nl2);
        if (nl1 && nl2) {
            nl1->attack(gameMode);
            nl2->attack(gameMode);
        }
    }
    if (EArmy->countOf(HU_))
        EArmy->peekEUnit(HU_)->attack(gameMode);
    if (SArmy->getCount()) 
        SArmy->peekSUnit()->attack(gameMode);
}

bool GameClass::loadData(int fileName)  // loads data from an input file returns true if a valid input file is entered and false otherwise
{
    int N, prob, SN, SProb, ESPer, ETPer, EGPer, HUPer, EUPstart, EUPend, EHstart, EHend, EACapstart, EACapend,
        ASPer, AMPer, ADPer, AUPstart, AHstart, AACapstart, AUPend, AHend, AACapend, SUPstart, SHstart, SACapstart, SUPend, SHend, SACapend, infection_Prob, threshold;
    string s = to_string(fileName);
    ifstream dataFile("Inputs/data (" + s + ").txt");
    if (!dataFile)
    {
        cout << "File is not found" << endl;
        return false;
    }
    else
    {
        //according to the input file's order
        dataFile >> N >> SN >> ESPer >> ETPer >> EGPer >> HUPer >> ASPer >> AMPer >> ADPer >> prob >> SProb >> infection_Prob >> threshold >>
            EUPstart >> EUPend >> EHstart >> EHend >> EACapstart >> EACapend >>	//ranges for earth's units
            AUPstart >> AUPend >> AHstart >> AHend >> AACapstart >> AACapend >>	//ranges for aliens' units
            SUPstart >> SUPend >> SHstart >> SHend >> SACapstart >> SACapend;	//ranges for allies' units
        //for the - sign in the input file
        EUPend = abs(EUPend);   AUPend = abs(AUPend); SUPend = abs(SUPend);
        EHend = abs(EHend);     AHend = abs(AHend); SHend = abs(SHend);
        EACapend = abs(EACapend);   AACapend = abs(AACapend); SACapend = abs(SACapend);
    }
    randGenerator->setParameters(N, prob, SN, SProb, ESPer, ETPer, EGPer, HUPer, EUPstart, EHstart, EACapstart, EUPend, EHend, EACapend,
        ASPer, ADPer, AMPer, AUPstart, AHstart, AACapstart, AUPend, AHend, AACapend, SHstart, SHend, SUPstart, SUPend, SACapstart, SACapend, infection_Prob);
    EArmy->setThreshold(threshold);
    return true;
}

ArmyUnit* GameClass::pickUnit(unitType unit,ArmyUnit*& d1, ArmyUnit*& d2,int dm) // used to pick a/two unit/s given a unit type
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
        return AArmy->pickAUnit(AS,d1,d2);
    case AM:
        return AArmy->pickAUnit(AM, d1, d2);
    case AD:
        return AArmy->pickAUnit(AD, d1, d2,dm);
    case SU_:
        return SArmy->pickSUnit();
    default:
        return nullptr;
    }
}


bool GameClass::addToKldList(ArmyUnit* unit)
{
    if (unit)
        return klst->addUnit(unit);
    else return false;
}

void GameClass::printArmies() const
{
    cout << "Current time step: " << this->crntTime<<endl;
    EArmy->printArmy();
    AArmy->printArmy();
    SArmy->printArmy();
    
}

void GameClass::addUnit(ArmyUnit* u1)
{
    if(u1)
    {
        switch (u1->getType())
        {
        case ES:
        case ET:
        case EG:
        case HU_:
            EArmy->addUnit(u1); break;
        case AS:
        case AM:
        case AD:
            AArmy->addUnit(u1); break;
        case SU_:
            SArmy->addUnit(u1);
        }
    }
}

void GameClass::createOFile(int winner) //creates the output file
{
    ofstream oFile("output.txt");
    //// Earth ouput 
    int S, T, G, HU, infectedUnits, Df, Dd;
    oFile << "Earth Destructed units:\n";
    klst->outKilled(oFile, S, T, G, HU, Df, Dd);
    infectedUnits = klst->getImmuneCount() + klst->getInfectedCount() + EArmy->countTotalInf();
    oFile << "Battle result:";
    if (winner == 1)
        oFile << " Win";
    else if (winner == 0)
        oFile << " Lose";
    else
        oFile << " Draw";
    oFile << endl;
    oFile << "Total ES: " << S + EArmy->countOf(ES) + EArmy->getUMLESCount() << endl;
    oFile << "Total ET: " << T + EArmy->countOf(ET) + EArmy->getUMLCount() - EArmy->getUMLESCount() << endl;
    oFile << "Total EG: " << G + EArmy->countOf(EG) << endl;
    oFile << "Total HU: " << HU + EArmy->countOf(HU_) << endl;
    oFile << "Total Units in the UML: " << EArmy->getUMLCount() << endl;
    oFile << "Total Infected Units: " << infectedUnits << endl;
    if (S + EArmy->countOf(ES) + EArmy->getUMLESCount()) {
        oFile << "Percentage of ES: " << double(S) / (S + EArmy->countOf(ES) + EArmy->getUMLESCount()) << endl;
        oFile << "Percentage of Infected ES: " << double(infectedUnits) / (S + EArmy->countOf(ES) + EArmy->getUMLESCount()) << endl;
    }
    if (T + EArmy->countOf(ET) + EArmy->getUMLCount() - EArmy->getUMLESCount())
        oFile << "Percentage of ET: " << double(T) / (T + EArmy->countOf(ET) + EArmy->getUMLCount() - EArmy->getUMLESCount()) << endl;
    if (G + EArmy->countOf(EG))
        oFile << "Percentage of EG: " << double(G) / (G + EArmy->countOf(EG)) << endl;
    if (HU + EArmy->countOf(HU_))
        oFile << "Percentage of HU: " << double(HU) / (HU + EArmy->countOf(HU_)) << endl;
    if ((S + G + T + HU + EArmy->getCount() + EArmy->getUMLCount())) {
        oFile << "Percentage of Total destructed units to Total units: " << double(S + G + T) / (S + G + T + HU + EArmy->getCount() + EArmy->getUMLCount()) << endl;
        oFile << "Percentage of Total Healed Units to Total Units: " << double(EArmy->getHealedCount()) / (S + G + T + HU + EArmy->getCount() + EArmy->getUMLCount()) << endl;
    }
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

    oFile << "Total AS: " << S + AArmy->countOf(AS) << endl;
    oFile << "Total AM: " << T + AArmy->countOf(AM) << endl;
    oFile << "Total AD: " << G + AArmy->countOf(AD) << endl;
    if ((S + AArmy->countOf(AS)))
        oFile << "Percentage of AS: " << double(S) / (S + AArmy->countOf(AS)) << endl;
    if ((T + AArmy->countOf(AM)))
        oFile << "Percentage of AM: " << double(T) / (T + AArmy->countOf(AM)) << endl;
    if ((G + AArmy->countOf(AD)))
        oFile << "Percentage of AD: " << double(G) / (G + AArmy->countOf(AD)) << endl;
    if (S + G + T + AArmy->getCount())
        oFile << "Percentage of Total Destructed Units to Total Units: " << double(S + G + T) / (S + G + T + AArmy->getCount()) << endl;
    if ((S + G + T)) {
        oFile << "Average of Df: " << double(Df) / (S + G + T) << endl;
        oFile << "Average of Dd: " << double(Dd) / (S + G + T) << endl;
        oFile << "Average of Db: " << double(Df + Dd) / (S + G + T) << endl;
    }
    if (Df + Dd) {
        oFile << "Df/Db: " << double(Df) / (Df + Dd) * 100 << endl;
        oFile << "Dd/Db: " << double(Dd) / (Df + Dd) * 100 << endl;
    }
    oFile << "Ally Army Destructed Units:\n";
    klst->outKilled(oFile, S, T, G, HU, Df, Dd, 7);
    oFile << "Total SU: " << S + SArmy->getCount() << endl;
    if ((S + SArmy->getCount()))
        oFile << "Percentage of SU: " << double(S) / (S + SArmy->getCount()) << endl;
    if ((S)) {
        oFile << "Average of Df: " << double(Df) / (S) << endl;
        oFile << "Average of Dd: " << double(Dd) / (S) << endl;
        oFile << "Average of Db: " << double(Df + Dd) / (S) << endl;
    }
    if (Df + Dd) {
        oFile << "Df/Db: " << double(Df) / (Df + Dd) * 100 << endl;
        oFile << "Dd/Db: " << double(Dd) / (Df + Dd) * 100 << endl;
    }
}

int GameClass::countOf(unitType ut)
{
    switch (ut)
    {
    case ES:
    case ET:
    case EG:
    case HU_:
        return EArmy->countOf(ut);
    case AS:
    case AM:
    case AD:    
        return AArmy->countOf(ut);
    case SU_:
        return SArmy->getCount();
    default:return 0;
    }
}
int GameClass::getInfectionPerc()
{
    return randGenerator->getInfectionPerc();
}

GameClass::~GameClass()
{
    delete EArmy;
    delete AArmy;
    delete SArmy;
    delete randGenerator;
    delete klst;
}
