#include "../stdafx.h"

#ifndef FUNCTOR_1_H
#define FUNCTOR_1_H

#include <iostream>

//含有返回常值的函数对象的类
class ConstantIntFunctor{
private:
	int value;//"函数调用"所返回的值
public:
	//ConstantIntFunctor() :value(){}
	ConstantIntFunctor(int c):value(c){ }

	//"函数调用"
	int operator() () const{
		return value;
	}
};

//使用上面“函数对象”的客户端函数
void client(ConstantIntFunctor const&  cif){
	std::cout << "calling back functor yields" << cif() << std::endl;
}


#endif//FUNCTOR_1_H
