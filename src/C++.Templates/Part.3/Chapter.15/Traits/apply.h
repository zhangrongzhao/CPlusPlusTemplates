#include "../stdafx.h"

#ifndef APPLY_H
#define APPLY_H
#include <iostream>
#include "typeop.h"
//不能根据第一个参数来推导模板参数T，因为T在受限名称中。只能根据第二个参数来推导模板参数T。
template<typename T>
void apply(typename TypeOp<T>::RefT arg,void(*pfunc)(T)){
	pfunc(arg);
}

//template<typename T>
//void apply(T& arg, void(*pfunc)(T)){
//	pfunc(arg);
//}

void increment(int& a){ 
	++a; 
}
void print(int& a){
	std::cout << a << std::endl;
}

void test_apply(){
	int x = 7;
	apply(x,increment);
	apply(x,print);
}

#endif//APPLT_H