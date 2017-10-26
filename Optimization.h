#pragma once
#include <random>
#include <time.h>
#include "Const.h"
#include "Function.h"
#include "Area.h"
#include"StopCriterion.h"

class Optimization {
public:
	//Optimization(int n = 0);
	virtual vector<double> minimize(Function& f, Area& area, StopCriterion& crit1, StopCriterion& crit2, vector<double> x) = 0;
	virtual ~Optimization();
	virtual const char* name() const = 0;
};

class PolakRibiere : public Optimization {
public:
	const char* name() const override;
	double right_value(vector<double> x, vector<double> l, vector<double> r, vector<double> p);
	double argmin(vector<double> const& x, vector<double> const& p, Function& f, Area& area);
	vector<double> minimize(Function& f, Area& area, StopCriterion& crit1, StopCriterion& crit2, vector<double> x);
};

class RandomSearch : public Optimization {
	std::mt19937 mt_rand;
	std::uniform_real_distribution<> u;
	double p;
public:
	RandomSearch() = default;
	RandomSearch(double prob);
	const char* name() const override;
	vector<double> RandInArea(Area& D);
	vector<double> minimize(Function& f, Area& area, StopCriterion& crit1, StopCriterion& crit2, vector<double> x);
};