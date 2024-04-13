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
}