#include "../stdafx.h"
#include "IfThenElse.h"

#ifndef SQRT_H
#define SQRT_H

//��ģ�������Ϊresult�Ļ���ģ��
template<int N>
class Value{
public:
	enum{Result=N};
};

//primary template
template<int N,int I=0>
class Sqrt{
public:

	//��ʵ������һ��Sqrt<N,I+1>���߽������Value<I>��Ϊ������֧
	typedef IfThenElse<(I*I<N),Sqrt<N,I+1>,Value<I>>::Result SubT;

	//ʹ�÷�֧���͵Ľ��
	enum{result=SubT::Result};
};
#endif//SQRT_H