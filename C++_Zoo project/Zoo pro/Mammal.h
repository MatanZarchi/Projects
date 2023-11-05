#pragma once
#include "Animal.h"
class Mammal : public Animal
{
private:
	bool _gotMilk;
public:
	Mammal();
	~Mammal();
	void print() const;
	void makeNoise() const;
	void gotMilk() const;
};

