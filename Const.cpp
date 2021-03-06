#include "Const.h"

Constant::Constant(double _eps = 1e-3, double _delta = 1e-9,
    int _maxiter = 10000, int _maxiter_success = 20000) :
    eps(_eps), delta(_delta), maxiter(_maxiter),
    maxiter_success(_maxiter_success) {};
double Constant:: GetEps() const { return eps; };
double Constant::GetDelta() const { return delta; };
double Constant:: GetMaxiter() const { return maxiter; };
double Constant::GetMaxiterSuccess() const { return maxiter_success; };
