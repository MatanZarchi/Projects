#pragma once
#include "Animal.h"
class Insect : public Animal
{
private:
	int _numOfLegs;
public:
	Insect();
	~Insect();
	void print() const;
	//void Insect:: makeNoise() const{}
};

