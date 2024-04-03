 #include<iostream>
#include "Army units/Drones.h"
#include "Army units/Tanks.h"
using namespace std;
int main()
{
	Tanks z;
	z.CreatTank(5, 10, 1200, 15, 20);
	z.CreatTank(145, 10, 1200, 15, 20);
	z.CreatTank(5564, 1460, 416200, 145, 20);
	z.printTanks();
	return 0;
}