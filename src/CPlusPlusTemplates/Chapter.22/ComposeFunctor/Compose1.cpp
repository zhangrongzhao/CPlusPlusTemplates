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
    //���sin(abs(0.5))
	//std::cout << Composer<Abs, Sine>(Abs(),Sine())(0.5) << "\n\n";

	//���ĳЩֵ��abs()
	//print_values(Abs());
	//std::cout << "\n";

	//���ĳЩֵ��Sin()
	//print_values(Sine());
	//std::cout << "\n";

	//���ĳЩֵ��Sin(abs())
	//print_values(Composer<Abs,Sine>(Abs(),Sine()));
	//std::cout << "\n";

	//���ĳЩֵ��abs(sin())
	//print_values(Composer<Sine,Abs>(Sine(),Abs()));
//}