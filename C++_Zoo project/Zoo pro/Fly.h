#pragma once
#include "Insect.h"
class Fly : public Insect
{
private:
	int _lifeTime;
public:
	Fly();
	~Fly();
	void print() const;
	void makeNoise() const;
};

