#include "../stdafx.h"
#include <iostream>

template<typename T1,typename T2>
void f(T2,T1){
	std::cout << "f1(T2,T1)" << std::endl;
}

extern void g();//�����ڷ��뵥Ԫ1��