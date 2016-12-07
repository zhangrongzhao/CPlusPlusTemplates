#include "../stdafx.h"

#ifndef FUNCTION_POINTER_H
#define FUNCTION_POINTER_H

//void foo(void(*pf)()){
//	pf();//通过函数指针pf对函数进行间接调用
//}

#include <iostream>
#include <typeinfo>

void foo(){
	std::cout << "foo() called " << std::endl;
}

typedef void FooT();//FooT是一个函数类型，与foo()函数具有相同的类型

//void main(){
//	foo();//直接调用
//
//	//输出foo和FooT的类型
//	std::cout << "Type of foo:" << typeid(foo).name() << std::endl;
//	std::cout << "Type of FooT:" << typeid(FooT).name() << std::endl;
//
//	FooT* pf = foo;//隐式转型decay
//	pf();//通过指针的间接调用
//	(*pf)();//等价于pf()
//
//	//打印出pf的类型
//	std::cout << "Type of pf:" << typeid(pf).name() << std::endl;
//	
//	FooT& rf = foo;//没有隐式转型
//	rf();//通过引用的间接调用
//
//	//输出rf的类型
//	std::cout << "Type of rf:" << typeid(rf).name() << std::endl;
//}


#endif//FUNCTION_POINTER_H+