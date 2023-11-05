#include <iostream>
#include "rational.h"
#include "polynomial.h"
#define _CRT_SECURE_NO_WARNING
using namespace std;

Rational::Rational() :denom(), nom()
{
	this->denom.setCoeff(0, 1.0);
}
Rational::Rational(Polynomial p1, Polynomial p2) : nom(p1), denom(p2)
{

}

void Rational::print() const
{
	this->nom.print();
	cout << "--------------------------" << endl;
	this->denom.print();
}

ostream &operator<<(ostream &os, const Rational r)
{
	r.print();
	return os;
}

Polynomial Rational::getDenom()const
{
	return denom;
}
Polynomial Rational::getNom()const
{
	return nom;
}


const Rational Rational::operator=(const Rational& right)
{
	if (&right != this) // check for self-assignment
	{ 
		this->nom = right.nom;
		this->denom= right.denom;
	}
	return *this;   // enables x = y = z;
}

Rational Rational::operator*(const Rational& r) const // member 
{
	rational result(this->nom * r.nom, this->denom * r.denom);
	return result;
}


 Rational Rational::operator+(const Rational& right) const
{
	 rational result((this->denom * right.nom) + (this->nom * right.denom), this->denom * right.denom);
	 return result;
}