#include "../stdafx.h"

#ifndef A_TRAITS_H
#define A_TRAITS_H
#include "A_Scalar.h"
//����ģ��
template<typename T>
class A_Traits{
public:
	typedef T const& ExprRef;//������ת��Ϊ���������͡�
};


template<typename T>
class A_Traits <A_Scalar<T> > {
public:
	typedef A_Scalar<T> const& ExprRef;//������A_scalarת��Ϊconst&���͡�
};
#endif//A_TRAITS_H