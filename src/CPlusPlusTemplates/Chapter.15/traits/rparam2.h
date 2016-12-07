#include "../stdafx.h"
#include "RParam.h"
#include "rParamCls.h"

//允许以传值或者传引用的方式传递参数的函数
template<typename T1,typename T2>
void foo_core(typename RParam<T1>::Type p1,typename RParam<T2>::Type p2){
   
}

//为了避免指定显示模板参数而实现的wrapper
template<typename T1,typename T2>
inline void foo(T1 const& p1,T2 const& p2){
	foo_core<T1,T2>(p1,p2);
}

int main(){
	MyClass1 mc1;
	MyClass2 mc2;
	foo(mc1, mc2);
}