#include "Fly.h"


Fly::Fly()
{
	this->_animalType = 5;
	cout << "(Fly) Enter fly's lifetime:\n";
	cin >> this->_lifeTime;
	cout << "(Fly) Fly constructed\n";
}


Fly::~Fly()
{
	cout << "(Fly) Fly is destroyed\n";
}


void Fly::print() const
{
	Insect::print();
	cout << "(Fly print) Lifetime is: " << this->_lifeTime << endl;
}


void Fly::makeNoise() const
{
	cout << "(Lion makeNoise) Lion noise...zzz...\n";
}
