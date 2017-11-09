// Optimiz1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "Function.h"
#include "Area.h"
#include "Const.h"
#include "StopCriterion.h"
#include "Optimization.h"
using namespace std;

int main(){
	double eps, delta, maxiter, maxiter_s = 0;
	cout << "Input eps " << endl;
	cin >> eps;
	cout << "Input delta" << endl;
	cin >> delta;
	cout << "Input max iteration " << endl;
	cin >> maxiter;
	cout << "Input max success iteration " << endl;
	cin >> maxiter_s;
	//eps = 1e-3; delta = 1e-8; maxiter = 20000; maxiter_s = 10000;
	Constant par(eps, delta, maxiter, maxiter_s);

	cout << endl << "Please, choose function: " << endl;
	cout << "1 - (y-x)^2+100*(1-x)" << endl;
	cout << "2 - 100*(y-x)^2+(1-x)^2" << endl;
	cout << "3 - x1^2+x2^2+x3^2+x4^2" << endl;

	int Func;
	double FuncNumber = 0;
	cin >> FuncNumber;
	while (!(FuncNumber == 1 || FuncNumber == 2 || FuncNumber == 3)) {
		cout << "This number is not correct. Repeat, please!" << endl;
		cin.clear();
		while (cin.get() != '\n');
		cin >> FuncNumber;
		continue;
	}
	Func = FuncNumber;
	Function * F = 0;
	switch (Func) {
	case 1: {
		F = new F1();
		break;
	}
	case 2: {
		F = new F2();
		break;
	}
	case 3: {
		F = new F3();
		break;
	}
	}

	cout << "Please, choose optimization method: " <<endl << "1 - Polak-Ribiere Method"<<endl << "2 - Random Search Method" << endl;
	int method;
	double MethodNumber=0;
	cin >> MethodNumber;
	while (!(MethodNumber == 1 || MethodNumber == 2)) {
		cout << "This number is not correct. Repeat, please!" << endl;
		cin.clear();
		while (cin.get() != '\n');
		cin >> MethodNumber;
		continue;
	}
	method = MethodNumber;

	cout << "Please, choose criterion: " << endl << "1 - ||Gragient||<eps" << endl << "2 - Number of success iterations" << endl;
	int Crit;
	double CritNumber=0;
	cin >> CritNumber;
	while (!(CritNumber == 1 || CritNumber == 2)) {
		cout << "This number is not correct. Repeat, please!" << endl;
		cin.clear();
		while (cin.get() != '\n');
		cin >> CritNumber;
		continue;
	}
	Crit = CritNumber;
	int dim = F->GetDim();
	vector<double> l(dim);
	vector<double> r(dim);
	for (int i = 0; i < dim; i++) { l[i] = -5; r[i] = 8; }
	Area* Ar = new Area1(l,r);

	cout << endl<<"Input vector x:" << endl;
	vector<double> x(dim);
	vread(x);
		for (int i = 0; i < dim; ++i) {
			if ((x[i] > Ar->GetR()[i]) || x[i] < Ar->GetL()[i]) { throw exception("Error: vector is not in the area"); return 1; }
		}

		StopCriterion * St=0;
		switch (Crit){
		case 1: {
		St = new GradientNorm();
			break;
		}
		case 2: {
			St = new NumberOfIterations();
			break;
		}
		}

	vector<double> res;
	Optimization* Opt = 0;
	switch (method){
	case 1: {
		Opt = new PolakRibiere();
		res = Opt->minimize(F, Ar, St, x, par);
		break;
	}
	case 2: {
		cout << endl<< "Input probability" << endl;
		double p;
		cin >> p;
		double num = 0;
		Opt = new RandomSearch(p);
		res = Opt->minimize(F, Ar, St, x, par);
		break;
	}
	}
	cout << endl << "Result:";
	cout <<endl<< "Min: ";
		vprint(res);
		cout << "f = " << F->f(res) << endl;
		cout << "iterations = " << Opt->GetIter() << endl;

	delete F;
	delete St;
	delete Ar;
	delete Opt;
	system("Pause");
    return 0;
}

