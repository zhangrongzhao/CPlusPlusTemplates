#include "stdafx.h"

#include <iostream>
#include "Math1.h"
#include "Compose1.h"

template<typename FO>
void print_values(FO fo){
	for (int i = -2; i < 3;++i){
		std::cout << "f(" << i*0.1 << ")=" << fo(i*0.1) << std::endl;
	}
}

//int main(){
//    //输出sin(abs(0.5))
//	std::cout << compose(Abs(),Sine())(0.5) << "\n\n";
//
//	//输出某些值得abs()
//	print_values(Abs());
//	std::cout << "\n";
//
//	//输出某些值得Sin()
//	print_values(Sine());
//	std::cout << "\n";
//
//	//输出某些值的Sin(abs())
//	print_values(compose(Abs(),Sine()));
//	std::cout << "\n";
//
//	//输出某些值得abs(sin())
//	print_values(compose(Sine(),Abs()));
//}