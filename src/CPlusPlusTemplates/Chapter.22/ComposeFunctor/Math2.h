#include "../stdafx.h"

#ifndef MATH_2_H
#define MATH_2_H

#include <cmath>
#include <cstdlib>

class Abs{
public:
	//使之适合框架
	enum{NumParam=1};
	typedef double ReturnT;
	typedef double Param1T;

	//函数调用
	double operator()(double v) const{
		return std::abs(v);
	}
};

class Sine{
public:
	//使之适合框架
	enum{ NumParams = 1 };
	typedef double ReturnT;
	typedef double Param1T;

	//函数调用
	double operator()(double a) const{
		return std::sin(a);
	}
};

#endif//MATH_2_H