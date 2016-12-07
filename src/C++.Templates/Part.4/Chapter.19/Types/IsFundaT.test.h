#include "../stdafx.h"

#ifndef IS_FUNDA_TEST_H
#define IS_FUNDA_TEST_H
#include <iostream>
#include "IsFundaT.h"

template<typename T>
void test(T const& t){
	if (IsFundaT<T>::Yes){
		std::cout << "T is fundamental type." << std::endl;
	}
	else{
		std::cout << "T is not fundamental type." << std::endl;
	}
}

class MyType{ };

void test_IsFundaT(){
	test(7);
	test(MyType());
}

#endif//IS_FUNDA_TEST_H