#include <iostream>
#include "polynomial.h"
#include "rational.h"
#include <assert.h>     
#define _CRT_SECURE_NO_WARNING
using namespace std;

int Polynomial::maxDegree = 0;

Polynomial::Polynomial(int degree) :degree(degree)
{
	arr = new double[degree + 1];
	for (int i = 0; i < degree + 1; i++)
		arr[i] = 0;
}


Polynomial::Polynomial(double* other, int degree) :degree(degree)
{
	int i, index = 0;
	this->arr = new double[degree + 1];
	for (i = degree; i >= 0; i--)
	{
		arr[i] = other[i];
		if (other[i] != 0 && index == 0)
			index = i;
	}
	if ((this->maxDegree) < index)
		this->maxDegree = index;
}


Polynomial::Polynomial(const Polynomial& other) :degree(other.degree)
{
	arr = new double[degree + 1];
	for (int i = 0; i < degree + 1; i++)
		this->arr[i] = other.arr[i];
}


Polynomial::~Polynomial()
{
	delete arr;
}
void Polynomial::setCoeff(int degree, double num)
{
	if (degree > maxDegree)
		maxDegree = degree;
	this->arr[degree] = num;
}
int Polynomial::getMaxDegree()
{
	return maxDegree;
}
int Polynomial::getDegree(bool val) const
{
	if (val == false)
		return this->degree;
	if (val == true)
	{
		for (int i = this->degree; i >= 0; i--)
		{
			if (this->arr[i] != 0)
				return i+1;
		}
	}
	return 0;
}
void Polynomial::print() const
{
	cout << "polynomial = ";
	int index = getDegree(true);
	if (index == 0)
		cout << 0;
	else
	{
		cout << arr[0];
		for (int i = 1; i < index; i++)
		{
			if (arr[i] >= 0)
				cout << '+';
			cout <<'('<< arr[i] <<')'<<'*'<<'X'<<'^'<< i;
		}
	}
	cout << endl;
}
ostream& operator<<(ostream& os, const Polynomial& p)
{
	p.print();
	return os;
}


Polynomial Polynomial::operator*(const Polynomial& p) const // member 
{
	int active_index = this->getDegree(true), i, j;
	int p_index = p.getDegree(true);
	int newDeg = (active_index + p_index);
	double* mulArr = new double[newDeg + 1];
	for (i = 0; i <= newDeg; i++)
		mulArr[i] = 0;
	for (i = 0; i <= this->degree; i++)
	{
		if (this->arr[i])
		{
			for (j = 0; j <= p.degree; j++)
				mulArr[j + i] += this->arr[i] * p.arr[j];
		}
	}
	Polynomial pMul(mulArr, newDeg);
	return pMul;
}

const Polynomial Polynomial::operator=(const Polynomial& right)
{
	if (&right != this)
	{  // check for self-assignment
		for (int i = 0; i <= right.getDegree(true); i++)
			this->arr[i] = right.arr[i];  // copy array into object
	}
	return *this;   // enables x = y = z;
}

Polynomial operator*(double num, const Polynomial& p) // non member 
{
	double* mulArr = new double[(p.degree) + 1];
	for (int i = 0; i <= p.degree; i++)
		mulArr[i] = num * (p.arr[i]);
	Polynomial newP(mulArr, p.degree);
	return newP;
}


Polynomial Polynomial::operator+(const Polynomial& p) const
{
	int newDegree = (p.degree > this->degree) ? p.degree : this->degree;
	double* arrSum = new double[newDegree + 1];
	int i = 0, pIndex = 0, thisIndex = 0;
	while (pIndex <= p.degree && thisIndex <= this->degree)
		arrSum[i++] = p.arr[pIndex++] + this->arr[thisIndex++];
	while (pIndex <= p.degree)
		arrSum[i++] = p.arr[pIndex++];
	while (thisIndex <= this->degree)
		arrSum[i++] = this->arr[pIndex++];
	Polynomial pSum(arrSum, newDegree);
	return pSum;
}

Polynomial Polynomial::operator-(const Polynomial& p) const
{
	int newDegree = (p.degree > this->degree) ? p.degree : this->degree;
	double* arrMinus = new double[newDegree + 1];
	int i = 0, pIndex = 0, thisIndex = 0;
	while (pIndex <= p.degree && thisIndex <= this->degree)
		arrMinus[i++] = this->arr[thisIndex++] - p.arr[pIndex++];
	while (pIndex <= p.degree)
		arrMinus[i++] = p.arr[pIndex++];
	while (thisIndex <= this->degree)
		arrMinus[i++] = this->arr[pIndex++];
	Polynomial pMinus(arrMinus, newDegree);
	return pMinus;
	/*return Polynomial(arrMinus, newDegree);*/
}

double & Polynomial::operator[](int num) const // return &p2.arr[5]
{
	return this->arr[num];
}

double& Polynomial::operator[](const int num) // return &p2.arr[5]
{
	return this->arr[num];
}






