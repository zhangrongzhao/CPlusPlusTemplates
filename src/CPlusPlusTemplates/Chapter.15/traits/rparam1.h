#include "../stdafx.h"
#include "RParam.h"
#include "rParamCls.h"

//允许参数以传值或者传引用的方式传递参数的函数
template<typename T1,typename T2>
void foo(typename RParam<T1>::Type p1,
	     typename RParam<T2>::Type p2){

}
