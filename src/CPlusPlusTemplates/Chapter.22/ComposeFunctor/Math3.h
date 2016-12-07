#include "../stdafx.h"

#ifndef MATH_3_H
#define MATH_3_H

#include <cmath>
#include <cstdlib>

template<typename T>
class Abs{
public:
	//使之适合模板
	enum{NumParams=1};
	typedef T ReturnT;
	typedef T Param1T;

	//函数调用
	T operator()(T v) const{
		return std::abs(v);
	}
};

template<typename T>
class Sine{
public:
	//使之适合模板
	enum{NumParams=1};
	typedef T ReturnT;
	typedef T Param1T;

	//函数调用
	T operator()(T a) const{
		return std::sin(a);
	}
};


#endif//MATH_3_H