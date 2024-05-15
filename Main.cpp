 #include<iostream>
#include "Game/GameClass.h"


using namespace std;
int main()
{
	GameClass game;
	cout << "Which mode of operation you want to select:\n1) Active mode\n2) Silent mode\n";
	int mode,fileName;
	cin >> mode;
	game.initializer(mode%2);
}