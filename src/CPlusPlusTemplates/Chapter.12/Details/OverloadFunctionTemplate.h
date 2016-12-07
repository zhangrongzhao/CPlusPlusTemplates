#include "../stdafx.h"
#include <iostream>
/**/
template<typename T>
int f(T){
	return 1;
}

template<typename T>
int f(T*){
	return 2;
}

template<typename T1,typename T2>
void f1(T1, T2){
	std::cout << "f1(T1,T2)" << std:endl;
}                                                          

template<typename T1,typename T2>
void f2(T2, T1){
	std::cout << "f1(T2,T1)" << std::endl;
}

template<typename T>
long f2(T);

template<typename T>
char f2(T);
/*
template<typename T>
void t(T*,T const*=0,...);

template<typename T>
void t(T const*,T*,T*=0);

void example(int* p){
	t(p,p);
}
*/






