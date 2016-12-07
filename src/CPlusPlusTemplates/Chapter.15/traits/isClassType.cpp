#include "stdafx.h"
#include <iostream>
#include "isClassType.h"

class MyClass{};

struct MyStruct{};

union MyUnion{};

void myFun(){};

enum E{e1} e;

//以模板实参的方式传递类型，并对该类型进行检查
template<typename T>
void check(){
	if (IsClassType<T>::Yes){
		std::cout << "IsClassType " << std::endl;
	}
	else{
		std::cout << "!IsClassType " << std::endl;
	}
}

//以函数调用的方式传递类型，并对该类型进行检查
template<typename T>
void checkT(T){
	check<T>();
}

