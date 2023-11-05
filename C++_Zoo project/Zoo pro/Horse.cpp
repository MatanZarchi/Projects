#include "Horse.h"


Horse::Horse()
{
	this->_animalType = 4;
	cout << "(Horse) Enter horse's speed:\n";
	cin >> this->_speed;
	cout << "(Horse) Horse constructed\n";
}
Horse::~Horse()
{
	cout << "(Horse) Horse is destroyed\n";
}

void Horse::print() const
{
	Mammal::print();
	cout << "(Horse print) Speed is: " << this->_speed << endl;
}


void Horse::makeNoise() const
{
	cout << "(Horse makeNoise) Horse noise...zzz...\n";
}



