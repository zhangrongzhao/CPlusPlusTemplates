#include "../stdafx.h"

#ifndef EMPTY_BASE_CLASS_OPTIMIZATION
#define EMPTY_BASE_CLASS_OPTIMIZATION
#include <iostream>
class Empty{ 
public :
	typedef int Int;
};
class EmptyToo :public Empty{ };
class EmptyThree :public EmptyToo{ };
//class NonEmpty :public Empty, public EmptyToo{ };

void test_ECBO(){
	std::cout << "sizeof(Empty):" << sizeof(Empty) << std::endl;
	std::cout << "sizeof(EmptyToo):" << sizeof(EmptyToo) << std::endl;
	std::cout << "sizeof(EmptyThree):" << sizeof(EmptyThree) << std::endl;
	//std::cout << "sizeof(NonEmpty):" << sizeof(NonEmpty) << std::endl;
}

#endif//EMPTY_BASE_CLASS_OPTIMIZATION