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

//����RParam<>��MyClass2�������Դ�ֵ�ķ�ʽ���д���
template<>
class RParam<MyClass2>{
public:
	typedef MyClass2 Type;
};