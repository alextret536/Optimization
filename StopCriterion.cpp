#include"StopCriterion.h"

bool const NumberOfIterations:: StopCheck(Function& f, vector<double> const& x, int iter) const {
	return (iter <= T);
};
bool const GradientNorm:: StopCheck(Function& f, vector<double> const& x, int iter) const {
	return (norm(f.gradient(x)) >= eps);
};
StopCriterion:: ~StopCriterion() {};