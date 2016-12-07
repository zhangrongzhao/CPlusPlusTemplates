#include "../stdafx.h"

#ifndef APPLY_H
#define APPLY_H
#include <iostream>
#include "typeop.h"
//���ܸ��ݵ�һ���������Ƶ�ģ�����T����ΪT�����������С�ֻ�ܸ��ݵڶ����������Ƶ�ģ�����T��
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