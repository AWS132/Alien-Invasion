#include <iostream>
#include "Data Structures/DLinkedQueue.h"
#include "Data Structures/LinkedQueue.h"
using namespace std;
int main()
{
	//Declare a queue of integers named "Q"
	DLinkedQueue<int> Q;
	int x;
	cout << "Testing Q:" << endl;
	cout << "inserting 5 values into Q:" << endl;

	cout << "Please Enter the 5 values to enqueue :";
	for (int i = 0; i < 5; i++)
	{
		cin >> x;
		if(i%2)
		Q.enqueue(x); //enqueue x to Q
		else {
			Q.push(x);
		}
	}

	cout << "Testing dequeue operation:\n ";

	while (Q.dequeue(x))
		cout << x << " ";

	cout << endl;

	//Write code to test empty case and to test peek function
	return 0;
}