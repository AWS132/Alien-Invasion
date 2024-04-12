 #include<iostream>
#include "Army units/Drones.h"
#include "Army units/Tanks.h"
#include "Army units/Monsters.h"
#include "Army units/Gunnerys.h"
using namespace std;
int main()
{
	Monsters a;
	a.CreatMonster(10, 55, 55, 55, 55);
	a.CreatMonster(20, 55, 55, 55, 55);
	a.CreatMonster(30, 55, 55, 55, 55);
	a.CreatMonster(40, 55, 55, 55, 55);
	a.CreatMonster(50, 55, 55, 55, 55);
	for (int i = 0; i < 10; i++)
	{
	a.printMonsters();
	cout << endl << endl;
	a.pickMonster();
	}
	return 0;
}