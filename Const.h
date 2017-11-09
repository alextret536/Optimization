#pragma once



class Constant {
double eps;
double delta;
int maxiter;
int maxiter_success;
public:
Constant(double _eps=1e-3, double _delta=1e-9, int _maxiter=10000,int _maxiter_success=20000) : eps(_eps), delta(_delta),maxiter(_maxiter), maxiter_success(_maxiter_success) {};
double GetEps() const { return eps; };
double GetDelta() const { return delta; };
double GetMaxiter() const { return maxiter; };
double GetMaxiterSuccess() const { return maxiter_success; };
Constant() = default;
};
const double c = 0.6; ///<For making epsilon in Random Search smaller