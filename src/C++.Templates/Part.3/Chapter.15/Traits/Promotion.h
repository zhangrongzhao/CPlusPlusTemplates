#include "../stdafx.h"
#ifndef PROMOTION_H
#define PROMOTION_H
#include <array>
#include "IfThenElse.h"
//基本模板：类型提升
//提升规则：类型大(sizeof计算所得结果大者)的作为结果类型
template<typename T1,typename T2>
class Promotion{
public:
	typedef typename IfThenElse<(sizeof(T1)>sizeof(T2)),
		                        T1,
								IfThenElse<(sizeof(T1)<sizeof(T2)),
								           T2,
										   void>
								>::ResultT ResultT;
};

//局部特化：相同类型提升
template<typename T>
class Promotion<T,T>{
public:
	typedef T ResultT;
};

//局部特化：针对数组,数组元素类型不同
template<typename T1,typename T2>
class Promotion<array<T1>,array<T2> >{
public:
	typedef array<typename Promotion<T1, T2>::ResultT> ResultT;
};

//局部特化：针对数组，数组元素相同
template<typename T>
class Promotion<array<T>,array<T> >{
public:
	typedef array<typedef Promotion<T, T>::ResultT> ResultT;
};

//基本类型提升（宏：减少源代码的数量）
#define MK_PROMOTION(T1,T2,Tr)                  \
template<>                                      \
class Promotion<T1,T2>{                         \
public:                                         \
	typedef Tr ResultT;                         \
};                                              \
	                                            \
template<>                                      \
class Promotion<T2,T1>{                         \
public:                                         \
	typedef Tr ResultT;                         \
};                                              \

MK_PROMOTION(bool,char,int);
MK_PROMOTION(bool,unsigned char,int);
MK_PROMOTION(bool,signed char,int);
#endif//PROMOTION_H