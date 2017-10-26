
#include <iostream>
#include<vector>
#pragma once
#include "Const.h"
using namespace std;

class Area {
	vector<double> l;
	vector<double> r;
public:
	Area(vector<double> left, vector<double> right) : l(left), r(right) {};
	const vector<double> GetL() const;
	const vector<double> GetR() const;
	virtual ~Area();
};

class Area1dim2 : public Area {
public:
	Area1dim2(vector<double> left = { -3,-3 }, vector<double> right = { 4,4 }) : Area(left, right) {};
};

class Area2dim4 : public Area {
public:
	Area2dim4(vector<double> left = { -3,-3,-3,-3 }, vector<double> right = { 4,4,4,4 }) : Area(left, right) {};
};