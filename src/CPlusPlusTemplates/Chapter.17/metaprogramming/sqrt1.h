#include "../stdafx.h"
#ifndef SQRT_H
#define SQRT_H
//���ڼ���sqrt(N)�Ļ���ģ��
template<int N,int LOW=0,int HIGH=N>
class Sqrt{
public:
	//�����е�
	enum{ mid = (LOW+HIGH+1)/2 };

	//�������ֲ���һ����С��result
	enum{ result = (N<mid*mid) ? (Sqrt<N, LOW, mid - 1>::result) : (Sqrt<N,mid,HIGH>::result) };
};

//�ֲ��ػ���������LOW==HIGH
template<int N,int M>
class Sqrt<N,M,M>{
public:
	enum{result=M};
};
#endif//SQRT_H