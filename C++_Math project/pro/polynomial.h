#pragma once
#include <iostream>
using namespace std;

class Polynomial
{
public:
	Polynomial(double*, int);
	Polynomial(int degree = 0);
	~Polynomial();
	Polynomial(const Polynomial& other);
	void setCoeff(int, double);
	int getDegree(bool) const;
	int static getMaxDegree();
	void print() const;


	friend ostream& operator<<(ostream&, const Polynomial&);
	friend Polynomial operator*(double num, const Polynomial& p);
	Polynomial operator*(const Polynomial& p) const;
	const Polynomial operator=(const Polynomial&); // assign arrays   
	Polynomial operator+(const Polynomial& p) const;
	Polynomial operator-(const Polynomial& p) const;
	double & operator[](int)const;
	double& operator[](const int);



private:
	double* arr;
	int const degree;
	int static maxDegree;

};
