#include "Mammal.h"


Mammal::Mammal()
{
	this->_animalType = 1;
	cout << "(Mammal constructor) Mammal got milk? (y/n): " << endl;
	char t;
	cin >> t;
	if (t == 'Y' || t == 'y')
		this->_gotMilk = true;
	else
		this->_gotMilk = false;
	cout << "(Mammal) Mammal constructed\n";
}

Mammal::~Mammal()
{
	cout << "(Mammal) Mammal destroyed\n";
}

void Mammal::print() const
{
	Animal::print();
	if (this->_gotMilk)
		cout << "(Mammal print) Mammal got milk\n";
	else
		cout << "(Mammal print) Mammal didn't get milk\n";
}


void Mammal::makeNoise() const
{
	cout << "(Mammal makeNoise) Mammal noise...zzz...\n";
}


void Mammal::gotMilk() const
{

}