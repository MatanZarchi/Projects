#pragma once
#include <iostream>
#include <string>
using namespace std;


class Animal
{
protected:
	int _animalType;
private:
	string _animalName;
	int _animaleAge;
public:
	Animal();
	virtual ~Animal();
	virtual void print() const;
	virtual void maKeNoise() const;
	string getName()const { return this->_animalName; }
};

