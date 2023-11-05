#include "Insect.h"


Insect::Insect()
{
	this->_animalType = 2;
	cout << "(Insect constructor) Enter num of legs: " << endl;
	cin >> this->_numOfLegs;
	cout << "(Insect) Insect constructed\n";
}


Insect::~Insect()
{
	cout << "(Insect) Insect destroyed\n";
}


void Insect::print() const
{
	Animal::print();
	cout << "(Insect print) Num of legs: " << this->_numOfLegs << endl;
}