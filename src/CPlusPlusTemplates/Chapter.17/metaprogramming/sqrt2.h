#include "../stdafx.h"
#include "IfThenElse.h"

#ifndef SQRT_H
#define SQRT_H

//primary template
template<int N,int LOW=0,int HIGH=N>
class Sqrt{
public:
	enum{ mid = (LOW+HIGH+1)/2 };
	typedef typename IfThenElse<(N<mid*mid), Sqrt<N,LOW,mid-1>, Sqrt<N,mid,HIGH>>::Result SubT;
	enum{result=SubT::Result};
};

//用于结束递归的局部特化
template<int N,int S>
class Sqrt<N,S,S>{
public:
	enum{Result=1};
};

#endif//SQRT_H
