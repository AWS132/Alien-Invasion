 #include<iostream>
#include "Army units/Drones.h"
#include "Army units/Tanks.h"
#include "Army units/Monsters.h"
#include "Army units/Gunnery.h"
using namespace std;
int main()
{
	Gunnery a;
	a.CreatGunnery(1, 50, 1500, 66, 4);
	a.CreatGunnery(11, 50, 150, 666666, 4);
	a.CreatGunnery(111, 50, 150, 60, 4);
	a.CreatGunnery(1111, 50, 1500, 65454, 4);
	for(int i=0;i<10;i++){
	a.printGunnery();
	cout << endl << endl;
	a.dequeue();
	}
	return 0;
}