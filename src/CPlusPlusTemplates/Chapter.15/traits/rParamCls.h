#include "../stdafx.h"
#include <iostream>
#include "RParam.h"

class MyClass1{
public:
	MyClass1(){}
	MyClass1(MyClass1 const&){
		std::cout << "MyClass1 copy constructor called" << std::endl;
	}
};

class MyClass2{
public:
	MyClass2(){}
	MyClass2(MyClass2 const&){
		std::cout << "MyClass2 copy constructor called" << std::endl;
	}
};

//对于RParam<>的MyClass2参数，以传值的方式进行传递
template<>
class RParam<MyClass2>{
public:
	typedef MyClass2 Type;
};