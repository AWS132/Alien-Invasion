 #include<iostream>
#include "Army units/Drones.h"
#include "Army units/Tanks.h"
using namespace std;
int main()
{
	Tanks a;
	a.CreatTank(10, 20, 20, 20, 20);
	a.CreatTank(10, 20, 20, 20, 20);
	a.CreatTank(10, 20, 20, 20, 20);
	cout << a.getCount();
	return 0;
}