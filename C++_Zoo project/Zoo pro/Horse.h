#pragma once
#include "Mammal.h"
class Horse : public Mammal
{
private:
	int _speed;
public:
	Horse();
	~Horse();
	void print() const;
	void makeNoise() const;
};

