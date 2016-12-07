#include "../stdafx.h"
#include <iostream>
//primary template
template<int N>
class Pow3{
public:
	//static int const result = 3 * Pow3<N-1>::result;//静态成员变量只能是左值，赋值给其他变量时，编译器强制实例化静态成员变量，并为该定义分配内存。不在局限于编译器效果。
	enum{ result = 3 * Pow3<N-1>::result };//
};

//global sepialization
template<>
class Pow3 <0> {
public:
	//static int const result = 1;
	enum{ result = 1 };
};

void test_pow3(){
	std::cout << "Pow3<7>::result" << Pow3<7>::result << std::endl;
}
