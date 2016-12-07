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

//���ڽ����ݹ�ľֲ��ػ�
template<int N,int S>
class Sqrt<N,S,S>{
public:
	enum{Result=1};
};

#endif//SQRT_H
