#include "../stdafx.h"

#ifndef MATH_1_H
#define MATH_1_H

#include <cmath>
#include <cstdlib>

class Abs{
public:
	//"函数调用"
	double operator()(double v) const{
		return std::abs(v);
	}
};

class Sine{
public:
	//函数调用
	double operator()(double a) const{
		return std::sin(a);
	}
};

//先计算给定角度的正玄值，然后在计算正弦值得绝对值
class AbsSins{
public:
	double operator()(double a){
		return std::abs(std::sin(a));
	}
};

//缺点：为每个已完成仿函数的功能组合功能都编写一个新的仿函数，这样不方便。
//编写一个实现组合两个仿函数功能的小工具


#endif//MATH_1_H