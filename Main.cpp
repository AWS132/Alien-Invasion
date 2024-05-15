 #include<iostream>
#include <vector>
#include "Game/GameClass.h"
using namespace std;
int main()
{
	GameClass game;
	cout << "Which mode of operation you want to select:\n1) Active mode\n2) Silent mode\n";
	int mode;
	cin >> mode;
	game.initializer(mode%2);
	vector<bool> x(game.getSArmy()->getId()-4000, false);
	game.check(x);
	for (auto value : x) {
		cout << value;
	}
}