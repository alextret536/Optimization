#include"Optimization.h"
#include <vector>
#include <cstdio>
#include <iostream>
#include <random>
#include <time.h>
using namespace std;

const char* PolakRibiere:: name() const { return "Polak-Ribiere Method"; };
double PolakRibiere::right_value(vector<double> x, vector<double> l, vector<double> r, vector<double> p) {
	double bord, t;
	if (p[0] > 0) bord = (r[0] - x[0]) / p[0];
	else bord = (l[0] - x[0]) / p[0];
	for (int i = 0; i < x.size(); ++i) {
		if (p[i] > 0) t = (r[i] - x[i]) / p[i];
		else t = (l[i] - x[i]) / p[i];
		if (abs(t) < bord) bord = abs(t);
	}
	return bord;
};
double PolakRibiere::argmin(vector<double> const& x, vector<double> const& p, Function& f, Area& area) {
	double l = 0, r = right_value(x, area.GetL(), area.GetR(), p);
	double m = (l + r) / 2;
	//while (abs((r - l)) > eps) {
	while (abs(f.df(x + p*m, p)) >= eps) {
		if (f.df(x + p*m, p) > 0)
			r = m;
		else l = m;
		m = (l + r) / 2;
	}
	// // //

	return m;
};
vector<double> PolakRibiere:: minimize(Function& f, Area& area, StopCriterion& crit1, StopCriterion& crit2, vector<double> x) {
	double beta = 0; double alpha = 1;
	vector<double> oldGrad(f.gradient(x));
	vector<double> newGrad(x.size());
	vector<double> p(oldGrad*(-1));
	int k = 1;
	while (crit1.StopCheck(f, x, k) && crit2.StopCheck(f, x, k)) {
		alpha = argmin(x, p, f, area);
		//cout << "alpha=  " << alpha << endl;
		x = x + p*alpha;
		newGrad = f.gradient(x);
		//cout << "norm grad  =  " << norm(newGrad) << endl;
		beta = scalpr(newGrad, newGrad - oldGrad) / scalpr(oldGrad, oldGrad);
		p = newGrad*(-1) + p*beta;
		oldGrad = newGrad;
		k++;
	}
	//cout << norm(newGrad) << endl;
	return x;
};

RandomSearch::RandomSearch(double prob) : p(prob) {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<> d(0, 1);
	u = d;
}

const char* RandomSearch::name() const { return "Random Search Method"; };
vector<double> RandomSearch::RandInArea(Area& D) {
	int dim = D.GetL().size();
	vector<double> res;
	for (int k = 0; k < dim; ++k) {
		res.push_back(D.GetL()[k] + (D.GetR()[k] - D.GetL()[k])*u(mt_rand));
	}
	return res;
}
vector<double>RandomSearch::minimize(Function& f, Area& area, StopCriterion& crit1, StopCriterion& crit2, vector<double> x) {
	int count = 0; int iter = 0;
	double ksi; double eps1 = eps; 
	std::vector<double> xi(area.GetL().size());
	std::vector<double> yi(area.GetL().size());
	std::vector<double> br(area.GetL().size());
	std::vector<double> bl(area.GetL().size());
	yi = RandInArea(area);
	for (int i = 0; count<STOP_RAND; i++) {
		ksi = u(mt_rand);
		if (ksi <= p) {
			xi = RandInArea(area);
		}
		else {
			for (int k = 0; k < area.GetL().size(); k++) {
				if (abs(area.GetR()[k] - yi[k]) > eps1) {
					br[k] = yi[k] + eps1;
				}
				else br[k] = area.GetR()[k];
				if (abs(area.GetL()[k] - yi[k]) > eps1) {
					bl[k] = yi[k] - eps1;
				}
				else bl[k] = area.GetL()[k];
			}
			for (int j = 0; j < area.GetL().size(); j++) {
				uniform_real_distribution<double> u1(yi[j] - eps1, yi[j] + eps1);
				xi[j] = u1(mt_rand);
			}
			eps1 *= c;
		}
		if (f.f(yi) > f.f(xi)) {
			yi = xi, count = 0;
		}
		else count++;
		iter++;
	}
	return yi;
}

Optimization:: ~Optimization() {};