#include "../stdafx.h"
#ifndef SQRT_H
#define SQRT_H

//primary template
template<int N,int I=0>
class Sqrt{
public:
	enum{ result = (I*I) ? (Sqrt<N, I + 1>::Result):(I) };
};


//���ڽ�����ģ���ػ�
template<int N>
class Sqrt<N,N>{
public:
	enum{result=N};
};

#endif//SQRT_H