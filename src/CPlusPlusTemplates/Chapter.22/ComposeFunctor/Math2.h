#include "../stdafx.h"

#ifndef MATH_2_H
#define MATH_2_H

#include <cmath>
#include <cstdlib>

class Abs{
public:
	//ʹ֮�ʺϿ��
	enum{NumParam=1};
	typedef double ReturnT;
	typedef double Param1T;

	//��������
	double operator()(double v) const{
		return std::abs(v);
	}
};

class Sine{
public:
	//ʹ֮�ʺϿ��
	enum{ NumParams = 1 };
	typedef double ReturnT;
	typedef double Param1T;

	//��������
	double operator()(double a) const{
		return std::sin(a);
	}
};

#endif//MATH_2_H