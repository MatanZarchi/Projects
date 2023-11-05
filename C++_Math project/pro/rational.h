#pragma once
#include <iostream>
#include "polynomial.h"
using namespace std;

typedef class Rational
{
public:
	Rational();
	Rational(Polynomial, Polynomial);
	void print()const;
	friend ostream& operator<<(ostream &, const Rational);
	Polynomial getNom()const;
	Polynomial getDenom()const;

	const Rational operator=( const Rational&); // assign arrays   
	Rational operator+(const Rational& p) const;
	Rational operator*(const Rational& p) const;

private:
	Polynomial nom;
	Polynomial denom;
}rational;