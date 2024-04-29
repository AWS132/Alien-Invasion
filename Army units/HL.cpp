#include "HL.h"

HL::HL()
{
}

bool HL::addUnit(ArmyUnit* Unit)
{

	return push(Unit);
}

ArmyUnit* HL::pickHealer()
{
	return pop();	//returning either a healer or NULL
}

int HL::getCount() const
{
	return top + 1;
}

void HL::printHeal()
{
	cout << "============== Heal Units ===============\n";
	cout << getCount() << " HU [";
	if (getCount() >= 1) {
		for (int i = 0; i <= top; i++)
		{
			items[i]->Print();
			if (i - top)
				cout << ", ";
		}
	}
	cout << "]\n";
}

HL::~HL()
{
	for (int i = 0; i <= top; i++)
	{
		delete items[i];
	}
}