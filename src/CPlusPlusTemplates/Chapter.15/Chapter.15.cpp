// Chapter.15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include "Details\accum6.h"
//#include "Details\multPolicy1.h"
//#include "Details\sumpolicy1.h"
#include <iostream>
#include <typeinfo>

#include "traits\sizeof.cpp"
#include "traits\elementtype.h"

void test_TypeSize(){
	std::cout << "TypeSize<int>::value=" << TypeSize<int>::value << std::endl;
}

template<typename T>
void print_element_type(T const& c){
	std::cout << "Container of " << typeid(typename ElementT<T>::Type).name() << " elements." << std::endl;
}

/*
void test(){
	//����һ������5������ֵ������
	int num[] = { 1, 2, 3, 4, 5 };
	//���ƽ��ֵ
	std::cout << "the average value of the integer value is " << accum(&num[0], &num[5]) / 5 << std::endl;

	//�����ַ�ֵ����
	char name[] = "templates";
	int length = sizeof(name) - 1;

	//(��ͼ)���ƽ�����ַ�ֵ
	std::cout << "the average value of the characters in \""
		<< name
		<< "\" is "
		<< accum(&name[0], &name[length]) / length
		<< std::endl;

	//������еĳ˻�
	std::cout << "the product of the integer values is "
		<< Accum<int>::accum(&num[0], &num[5])
		<< std::endl;


	//test_TypeSize();
	std::stack<bool> s;
	print_element_type(s);
}

*/
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}


