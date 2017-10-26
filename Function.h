#pragma once
#include <iostream>
#include<vector>
#include "Const.h"
using namespace std;

class Function {
	int dim;
public:
	vector<double> gradient(vector<double> const& x);
	double df(vector<double> x, vector<double> p);
	virtual double f(vector<double> const& x) = 0;
	Function(int d);
	int const GetDim() const;
	virtual ~Function();
	friend vector<double> operator+(vector<double> const& x, vector<double> const& y);
	friend vector<double> operator-(vector<double> const& x, vector<double> const& y);
	friend vector<double> operator*(vector<double> const& x, const double c);
	friend double norm(vector<double> const& x);
	friend double scalpr(vector<double> const& x, vector<double> const& y);
};

class F1 : public Function {
public:
	F1() : Function(2) {}
	double f(vector<double>const& x) override;
};

class F2 : public Function {
public:
	F2() : Function(2) {}
	double f(vector<double>const& x) override;
};

class F3 : public Function {
public:
	F3() : Function(4) {}
	double f(vector<double>const& x) override;
};
void vprint(vector<double> x);