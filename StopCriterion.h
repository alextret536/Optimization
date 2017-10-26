#pragma once
#include "Const.h"
#include "Function.h"
#include<vector>
using namespace std;

class StopCriterion {
public:
	virtual const bool StopCheck(Function& f, vector<double> const& x, int iter) const = 0;
	virtual ~StopCriterion();
};

class NumberOfIterations : public StopCriterion {
public:
	bool const StopCheck(Function& f, vector<double> const& x, int iter) const override;
};

class GradientNorm : public StopCriterion {
public:
	bool const StopCheck(Function& f, vector<double> const& x, int iter) const override;
};