#include "../stdafx.h"
#ifndef SQRT_H
#define SQRT_H
//用于计算sqrt(N)的基本模板
template<int N,int LOW=0,int HIGH=N>
class Sqrt{
public:
	//计算中点
	enum{ mid = (LOW+HIGH+1)/2 };

	//借助二分查找一个较小的result
	enum{ result = (N<mid*mid) ? (Sqrt<N, LOW, mid - 1>::result) : (Sqrt<N,mid,HIGH>::result) };
};

//局部特化，适用于LOW==HIGH
template<int N,int M>
class Sqrt<N,M,M>{
public:
	enum{result=M};
};
#endif//SQRT_H