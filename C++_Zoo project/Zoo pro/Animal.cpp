#include "Animal.h"
//virtual - יורד כמה שיותר למטה כלומר לעומק בלי וירטואל בדיוק להפך

Animal::Animal()
{
	cout << "(Animal constructor) Enter the animal's name: " << endl;
	cin >> this->_animalName;
	cout << "(Animal constructor) Enter the animal's age: " << endl;
	cin >> this->_animaleAge;
	if (this->_animaleAge < 0)
	{
		this->_animaleAge = 1;
		throw "Age is invalid";
	}
	this->_animalType = 0;
	cout << "(Animal) Animal constructed\n";
}

Animal::~Animal()
{
	cout << "(Animal) Animal destroyed\n";
}


void Animal::print() const
{
	cout << "(Animal print) Animal's name: " << this->_animalName << endl;
	cout << "(Animal print) Animal's age: " << this->_animaleAge << endl;
}


void Animal::maKeNoise() const
{
	cout << "(Animal maKeNoise) Animal noise...zzz...\n";
}




