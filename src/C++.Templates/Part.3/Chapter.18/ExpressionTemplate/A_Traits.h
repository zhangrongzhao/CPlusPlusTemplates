#include "../stdafx.h"

#ifndef A_TRAITS_H
#define A_TRAITS_H
#include "A_Scalar.h"
//基本模板
template<typename T>
class A_Traits{
public:
	typedef T const& ExprRef;//将类型转换为常引用类型。
};


template<typename T>
class A_Traits <A_Scalar<T> > {
public:
	typedef A_Scalar<T> const& ExprRef;//将类型A_scalar转换为const&类型。
};
#endif//A_TRAITS_H