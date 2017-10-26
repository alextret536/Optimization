#include "Function.h"

double F1::f(vector<double>const& x) {
	return ((x[1] - x[0] * x[0])*(x[1] - x[0] * x[0]) + 100 * (1 - x[0])*(1 - x[0]));
		//(x[1] - x[0] * x[0])*(x[1] - x[0] * x[0]) + (1 - x[0])*(1 - x[0]);
};
double F2::f(vector<double>const& x) {
	return 100 * (x[1] - x[0] * x[0])*(x[1] - x[0] * x[0]) + (1 - x[0])*(1 - x[0]);
};
double F3::f(vector<double>const& x) {
	return ((x[0] + 10 * x[1])*(x[0] + 10 * x[1]) + 5 * pow(x[2] - x[3], 2) + pow(x[1] - 2 * x[2], 4) + 10 * pow(x[0] - x[3], 4));
};
Function:: Function(int d) { dim = d; }
int const Function:: GetDim() const { return dim; }
Function:: ~Function() {};

vector<double> Function::gradient(vector<double> const& x) {
	vector<double> grad(x.size());
	for (int i = 0; i < x.size(); i++) {
		std::vector<double> delt(x.size());
		delt.at(i) = delta;
		grad[i] = (f(x + delt) - f(x - delt)) / (2 * delta);
	}
	return grad;
}

double Function::df(vector<double> x, vector<double> p) {
	return((f(x + (p*(1 / norm(p)))* delta) - f(x + (p*(1 / norm(p)))* (-1)* delta)) / (2 * delta));
}

vector<double> operator+(vector<double> const& x, vector<double> const& y) {
	std::vector<double> res;
	for (int i = 0; i < x.size(); i++) {
		res.push_back(x.at(i) + y.at(i));
	}
	return res;
}

vector<double> operator-(vector<double> const& x, vector<double> const& y) {
	std::vector<double> res;
	for (int i = 0; i < x.size(); i++) {
		res.push_back(x.at(i) - y.at(i));
	}
	return res;
}
vector<double> operator*(vector<double> const& x, const double c) {
	vector<double> res;
	for (int i = 0; i < x.size(); i++) {
		res.push_back(c* x.at(i));
	}
	return res;
}

double norm(vector<double> const& x) {
	double accum = 0.;
	for (int i = 0; i < x.size(); ++i) {
		if (abs(x[i]) > accum) accum = abs(x[i]);
	}
	return accum;
}

double scalpr(std::vector<double> const& x, std::vector<double> const& y) {
	double prod = 0;
	for (int i = 0; i < x.size(); i++) {
		prod += x.at(i)*y.at(i);
	}
	return prod;
}

void vprint(vector<double> x) {
	for (int i = 0; i < x.size(); ++i)
		cout << x[i] << "   ";
	cout << endl;
}