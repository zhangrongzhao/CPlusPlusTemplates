#include "../stdafx.h"

#ifndef R_PARAM_H
#define R_PARAM_H
#include <array>
#include "IsClassT.h"
#include "IfThenElse.h"

////只读参数传递：小于2个指针大小的类型，采用值传递；大于2个指针大小的类型，采用(传递const&)const&.
//template<typename T>
//class RParam{
//public:
//	typedef typename IfThenElse<(sizeof(T)<2*sizeof(void*)),T,T const&>::ResultT ResultT;
//};

//只读参数传递：类类型==>const&,非类类型==>值传递。
template<typename T>
class RParam{
public:
	typedef typename IfThenElse<IsClassT<T>::Yes,T const&,T>::ResultT Type;
};

////局部特化：针对容器类型,采用const&，处理原始数据，并对原始数据加以保护。原因：sizeof返回很小的值，但是可能涉及到昂贵的构造函数。
//template<typename T>
//class RParam<array<T> >{
//public:
//	typedef array<T> const& Type;
//};

#endif//R_PARAM_H