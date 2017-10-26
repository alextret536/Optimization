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
	F1 f1; Area1dim2 D; Area2dim4 D1;
	GradientNorm gradnorm; NumberOfIterations numiter;
	vector<double> x = {1,2};
	cout << endl;
	PolakRibiere polak_rib;
	vector<double> res1(polak_rib.minimize(f1, D, gradnorm, numiter, x));
	cout << polak_rib.name() << endl;
	cout << "x= " << endl;
	vprint(res1);
	cout << "f = " << f1.f(res1) << endl;

	RandomSearch rand_search(0.8);
	vector<double> res(rand_search.minimize(f1, D, gradnorm, numiter, x));
	cout << rand_search.name() << endl;
	cout << "x= " << endl;
	vprint(res);
	cout << "f = " << f1.f(res) << endl;

	F2 f2;
//	vector<double> x = {0,1.5};
	cout << endl;
	vector<double> res2(polak_rib.minimize(f2, D, gradnorm, numiter, x));
	cout << polak_rib.name() << endl;
	cout << "x= " << endl;
	vprint(res2);
	cout << "f = " << f2.f(res2) << endl;

	vector<double> res3(rand_search.minimize(f2, D, gradnorm, numiter, x));
	cout << rand_search.name() << endl;
	cout << "x= " << endl;
	vprint(res3);
	cout << "f = " << f2.f(res3) << endl;

	F3 f3;
	x = {0,1,1,1};
	cout << endl;
	vector<double> res4(polak_rib.minimize(f3, D1, gradnorm, numiter, x));
	cout << polak_rib.name() << endl;
	cout << "x= " << endl;
	vprint(res4);
	cout << "f = " << f3.f(res4) << endl;

	vector<double> res5(rand_search.minimize(f3, D1, gradnorm, numiter, x));
	cout << rand_search.name() << endl;
	cout << "x= " << endl;
	vprint(res5);
	cout << "f = " << f3.f(res5) << endl;
    return 0;
}

