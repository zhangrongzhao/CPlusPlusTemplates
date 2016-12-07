#include "stdafx.h"
#include "FundamentalType.h"
#include <iostream>

template<typename T>
void test(T const& t){
	if (IsFundaT<T>::Yes){
		std::cout << "T is fundamental type " << std::endl;
	}
	else{
		std::cout << "T is not fundamental type " << std::endl;
	}
}

//class MyType{};
//
//void main(){
//	test(7);
//	test(MyType());
//}