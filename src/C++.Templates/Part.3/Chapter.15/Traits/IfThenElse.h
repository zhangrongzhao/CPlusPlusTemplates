#include "../stdafx.h"

#ifndef IF_THEN_ELSE_H
#define IF_THEN_ELSE_H
//根据第一个模板参数来选择结果类型:B==true，选择T1作为ResultT；B==false，选择T2作为ResultT。
template<bool B,typename T1,typename T2>
class IfThenElse;

//局部特化：B==true，选择T1作为ResultT
template<typename T1,typename T2>
class IfThenElse<true,T1,T2>{
public:
	typedef T1 ResultT;
};

//局部特化：B==false,选择T2作为ResultT
template<typename T1,typename T2>
class IfThenElse<false,T1,T2>{
public:
	typedef T2 ResultT;
};

#endif//IF_THEN_ELSE_H