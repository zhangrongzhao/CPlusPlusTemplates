#include "../stdafx.h"

#ifndef MIN_H
#define MIN_H

//�����������е���Сֵ
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

//�������ֵ�Ƚϴ�С
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

//���ض��º������ض��������ض�ֵ
template<typename F,int P,int V>
class BindIntStatically;

#endif//MIN_H