#include "../stdafx.h"

#ifndef POW_3_H
#define POW_3_H
#include <iostream>
template<int N>
class Pow3{
public:
	enum{ result = 3 * Pow3<N - 1>::result };
};

template<>
class Pow3<0>{
public:
	enum{ result = 1 };
};

void test_pow3(){
	std::cout << "Pow3<7>::result:" << Pow3<7>::result << std::endl;;
}

#endif//POW_3_H