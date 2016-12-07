#include "stdafx.h"

#include <iostream>
#include <string>
#include <typeInfo>
#include "FuncPtr.h"

double seven(){
	return 7.0;
}

std::string more(){
	return std::string("more");
}

template<typename FunctorT>
void demo(FunctorT func){
	std::cout << "Functor returns type: "
		<< typeid(typename FunctorT::ReturnT).name() << "\n"
		<< "Functor return value: "
		<< func() << "\n";
}

//int main(){
//	demo(func_ptr(seven));
//	demo(func_ptr(more));
//}