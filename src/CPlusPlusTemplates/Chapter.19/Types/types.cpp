#include "stdafx.h"
#include "TypeT.h"
#include <iostream>

class MyClass{};

void myFunc(){};

enum E{e1};

//��鴫�ݽ�����ģ��ʵ�ε�����
template<typename T>
void check(){
	if (TypeT<T>::IsFuncT){
		std::cout << " IsFuncT" << std::endl;
	}
	else if (TypeT<T>::IsFundaT){
		std::cout << " IsFundaT " << std::endl;
	}
	else if (TypeT<T>::IsEnumT){
		std::cout << " IsEnumT " << std::endl;
	}
	else if (TypeT<T>::IsPtrT){
		std::cout << "IsPtrT " << std::endl;
	}
	else if (TypeT<T>::IsRefT){
		std::cout << " IsRefT " << std::endl;
	}
	else if (TypeT<T>::IsPtrMemT){
		std::cout << " IsPrtMemT " << std::endl;
	}
	else if (TypeT<T>::IsArrayT){
		std::cout << " IsArrayT " << std::endl;
	}
	else if (TypeT<T>::IsClassT){
		std::cout << " IsClassT " << std::endl;
	}
}

//��鴫�ݽ����ĺ�������ʵ�ε�����
template<typename T>
void checkT(T){
	check<T>();

	//���ָ�����ͣ�������������õ�����
	if (TypeT<T>::IsPtrT || TypeT<T>::IsPtrMemT){
		check<typename CompoundT<T>::BaseT>();
	}
}

//int main(){
//	std::cout << "int:" << std::endl; 
//	check<int>();
//
//	std::cout << "int&:" << std::endl;
//	check<int&>();
//
//	std::cout << "char[42]" << std::endl;
//	check<char[42]>();
//
//	std::cout << "MyClass:" << std::endl;
//	check<MyClass>();
//
//	std::cout << "Ptr to enum:" << std::endl;
//	E* ptr = 0;
//	checkT(ptr);
//
//	std::cout << "42:" << std::endl;
//	checkT(42);
//
//	std::cout << "myFunc():" << std::endl;
//	checkT(myFunc);
//
//	std::cout << "memptr to array:" << std::endl;
//	char(MyClass::* memptr)[]=0;
//	checkT(memptr);
//}