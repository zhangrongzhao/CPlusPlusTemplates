#include "../stdafx.h"

#ifndef R_PARAM_CLS_H
#define R_PARAM_CLS_H
#include <iostream>
#include "RParam.h"
class MyClass1{
public:
	MyClass1(){}
	MyClass1(MyClass1 const&){
		std::cout << "MyClass1 copy constructor called\n";
	}
};

class MyClass2{
public:
	MyClass2(){}
	MyClass2(MyClass2 const&){
		std::cout << "MyClass2 copy constructor called\n";
	}
};

template<>
class RParam<MyClass2>{
public:
	typedef MyClass2 Type;
};

//如果直接使用，无法使用函数模板的实参推导。
template<typename T1,typename T2>
void foo_core(typename RParam<T1>::Type p1,typename RParam<T2>::Type p2){ }

//对foo_core函数封装，使客户端代码可是使用函数模板的实参推导
template<typename T1,typename T2>
void foo(T1 const& t1,T2 const& t2){
	foo_core<T1,T2>(t1,t2);
}

void test_foo(){
	MyClass1 mc1;
	MyClass2 mc2;
	foo(mc1,mc2);
}

#endif//R_PARAM_CLS_H