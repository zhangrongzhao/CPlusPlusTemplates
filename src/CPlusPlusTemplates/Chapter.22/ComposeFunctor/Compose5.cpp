#include "stdafx.h"

#include <iostream>
#include "Math3.h"
#include "Compose5.h"

template<typename FO>
void print_values(FO fo){
	for (int i = -2; i < 3;++i){
		std::cout << "f(" << i*0.1 << ")=" << fo(i*0.1) << std::endl;
	}
}

//void main(){
    //输出sin(abs(0.5))
	//std::cout << compose(Abs<double>(),Sine<double>())(0.5) << "\n\n";

	////输出某些值得abs()
	//print_values(Abs<double>());
	//std::cout << "\n";

	////输出某些值的Sin()
	//print_values(Sine<double>());
	//std::cout << "\n";

	////输出某些值得sin(abs())
	//print_values(compose(Abs<double>(),Sine<double>()));
	//std::cout << "\n";

	////输出某些值得abs(sin())
	//print_values(compose(Sine<double>(),Abs<double>()));
	//std::cout << "\n";

	////输出某些值得sin(sin())
	//print_values(compose(Sine<double>(),Sine<double>()));
//}