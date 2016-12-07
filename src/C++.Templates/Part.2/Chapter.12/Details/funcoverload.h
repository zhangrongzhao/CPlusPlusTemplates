#include "../stdafx.h"

#ifndef FUNCTION_OVERLOAD_H
#define FUNCTION_OVERLOAD_H

template<typename T>
int f(T){ 
	return 1;
}

template<typename T>
int f(T*){
	return 2;
}

void test(){
	//f<int*>((int*)0);
	//f<int>((int*)0);

	f((int*)0);
}
//
//template<typename T1,typename T2>
//void f1(T2,T1){
//	std::cout << "f1(T2,T1)\n";
//}
//
//
//void test(){
//	f1<int, int>(1,1);
//}

#endif//FUNCTION_OVERLOAD_H