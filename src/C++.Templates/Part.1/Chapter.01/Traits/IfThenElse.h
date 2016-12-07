#include "../stdafx.h"

#ifndef IF_THEN_ELSE_H
#define IF_THEN_ELSE_H

//根据第一个参数的结果，true选择第二个类型参数，false选择第三个类型参数
template<bool C,typename T1,typename T2>
class IfThenElse;

//局部特化：partial specialization
template<typename T1,typename T2>
class IfThenElse<true,T1,T2>{
public:
	typedef T1 ResultT;
};

template<typename T1,typename T2>
class IfThenElse<false,T1,T2>{
public:
	typedef T2 ResultT;
};


#endif//IF_THEN_ELSE_H