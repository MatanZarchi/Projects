#include "Lion.h"


Lion::Lion()
{
	this->_animalType = 3;
	cout << "(Lion) Enter lion's volume:\n";
	cin >> this->_volume;
	cout << "(Lion) Lion constructed\n";
}
Lion::~Lion()
{
	cout << "(Lion) Lion is destroyed\n";
}
void Lion::print() const
{
	Mammal::print();
	cout << "(Lion print) Volume is: " << this->_volume << endl;
}
void Lion::makeNoise() const
{
	cout << "(Lion makeNoise) Lion noise...zzz...\n";
}