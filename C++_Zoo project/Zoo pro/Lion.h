#pragma once
#include "Mammal.h"
class Lion : public Mammal
{
private:
	int _volume;
public:
	Lion();
	~Lion();
	void print() const;
	void makeNoise() const;
};

