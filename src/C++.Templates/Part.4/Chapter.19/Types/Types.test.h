#include "../stdafx.h"

#ifndef TYPES_TEST_H
#define TYPES_TEST_H
#include <iostream>
#include "IsFundaT.h"
#include "CompoundT.h"
#include "IsEnumT.h"
#include "IsFunctionT.h"
#include "IsClassT.h"

template<typename T>
class TypeT{
public:
	enum{
		IsFundaT=IsFundaT<T>::Yes,
		IsPointerT=CompoundT<T>::IsPointerT,
		IsReferenceT=CompoundT<T>::IsReferenceT,
		IsPointerToMemberT=CompoundT<T>::IsPointerToMemberT,
		IsArrayT=CompoundT<T>::IsArrayT,
		IsEnumT=IsEnumT<T>::Yes,
		IsClassT=IsClassT<T>::Yes,
		IsFunctionT=IsFunctionT<T>::Yes
	};
};

class MyClass{ };
void myFunction(){}
enum E{ e1 };

template<typename T>
void check(){
	if (TypeT<T>::IsFundaT){ std::cout << " IsFundaT "; }
	if (TypeT<T>::IsPointerT){ std::cout << " IsPointerT "; }
	if (TypeT<T>::IsReferenceT){ std::cout << " IsReferenceT "; }
	if (TypeT<T>::IsPointerToMemberT){ std::cout << " IsPointerToMemberT "; }
	if (TypeT<T>::IsArrayT){ std::cout << " IsArrayT "; }
	if (TypeT<T>::IsEnumT){ std::cout << " IsEnumT "; }
	if (TypeT<T>::IsClassT){ std::cout << " IsClassT "; }
	if (TypeT<T>::IsFunctionT){ std::cout << " IsFunctionT "; }
	std::cout << std::endl;
}

template<typename T>
void checkT(T){
	check<T>();

	//对于指针类型，检查他们所引用的类型
	if (TypeT<T>::IsPointerT || TypeT<T>::IsPointerToMemberT){
		check<typename CompoundT<T>::BaseT>();
	}
}


void test_types(){
	std::cout << "int:";
	check<int>();

	std::cout << "int&:" ;
	check<int&>();

	//std::cout << "char[42]:";
	//check<char[42]>();

	std::cout << "MyClass:";
	check<MyClass>();

	//std::cout << "Pointer to Enum:";
	//E* ptr = 0;
	//checkT(ptr);
 
	std::cout << "42:" ;
	checkT(42);

	//std::cout << "myfunc():";
	//checkT(myFunction);

	std::cout << "Member pointer to array:";
	char(MyClass::* memptr)[] = 0;
	checkT(memptr);
}


#endif//TYPES_TEST_H