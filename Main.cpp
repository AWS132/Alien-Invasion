 #include<iostream>
#include "Army units/Drones.h"
#include "Army units/Tanks.h"
#include "Army units/Monsters.h"
#include "Army units/Gunnerys.h"
#include "Game/GameClass.h"
#include "Game/randGen.h"

using namespace std;
int main()
{
	Monsters a;
	Monster *b=new Monster(10, 20, 30, 40, 50);
	Monster *c=new Monster(100, 20, 30, 40, 50);
	Monster *d=new Monster(140, 20, 30, 40, 50);
	Monster *e=new Monster(1490, 20, 30, 40, 50);
	a.addUnit(b);
	a.addUnit(c);
	a.addUnit(d);
	a.addUnit(e);
	a.printMonsters();
	Tanks tn;
	Tank *b2=new Tank(150, 20, 30, 40, 50);
	Tank *c2=new Tank(1060, 20, 30, 40, 50);
	Tank *d2=new Tank(140, 20, 30, 40, 50);
	Tank *e2=new Tank(1490, 20, 30, 40, 50);
	tn.addUnit(b2);
	tn.addUnit(c2);
	tn.addUnit(d2);
	tn.addUnit(e2);
	tn.printTanks();

	Gunnerys gn;
	Gunnery* b3 = new Gunnery(1500, 20, 30, 40, 50);
	Gunnery* c3 = new Gunnery(10600, 20, 30, 40, 50);
	Gunnery* d3 = new Gunnery(1402, 20, 30, 40, 50);
	Gunnery* e3 = new Gunnery(149055, 20, 30, 40, 50);
	gn.addUnit(b3);
	gn.addUnit(c3);
	gn.addUnit(d3);
	gn.addUnit(e3);
	gn.printGunnerys();

	Esoldiers es;
	Esoldier* es1 = new Esoldier(14, 14, 100, 200, 2);
	Esoldier* es2 = new Esoldier(150, 15, 130, 150, 5);
	es.addUnit(es1);
	es.addUnit(es2);
	es.printEsoldiers();

	Esoldiers as;
	Esoldier* as1 = new Esoldier(77, 134, 134, 130, 1);
	Esoldier* as2 = new Esoldier(140, 11, 50, 123, 4);
	es.addUnit(as1);
	es.addUnit(as2);
	es.printEsoldiers();

	/*Drones d;
	Drone* d1 = new Drone(77, 134, 134, 130, 1);
	Drone* d2 = new Drone(149055, 20, 30, 40, 50);
	*/

}