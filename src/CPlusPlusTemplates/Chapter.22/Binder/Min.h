#include "../stdafx.h"

#ifndef MIN_H
#define MIN_H

//求两个参数中的最小值
template<typename T>
class Min{
public:
	typedef T ReturnT;
	typedef T Param1T;
	typedef T Param2T;
	enum{NumParams=2};
	ReturnT operator()(Param1T a,Param2T b){
		return a < b ? a : b;
	}
};

//与给定常值比较大小
template<typename T,T max_result>
class Clamp :private Min<T>{
public:
	typedef T ReturnT;
	typedef T Param1T;
	enum{NumParams=1};
	ReturnT operator()(Param1T a){
		return Min<T>::operator()(a,max_result);
	}
};

//给特定仿函数的特定参数绑定特定值
template<typename F,int P,int V>
class BindIntStatically;

#endif//MIN_H