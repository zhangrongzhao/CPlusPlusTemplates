#include "../stdafx.h"

#ifndef FUNCTION_POINTER_H
#define FUNCTION_POINTER_H

//void foo(void(*pf)()){
//	pf();//ͨ������ָ��pf�Ժ������м�ӵ���
//}

#include <iostream>
#include <typeinfo>

void foo(){
	std::cout << "foo() called " << std::endl;
}

typedef void FooT();//FooT��һ���������ͣ���foo()����������ͬ������

//void main(){
//	foo();//ֱ�ӵ���
//
//	//���foo��FooT������
//	std::cout << "Type of foo:" << typeid(foo).name() << std::endl;
//	std::cout << "Type of FooT:" << typeid(FooT).name() << std::endl;
//
//	FooT* pf = foo;//��ʽת��decay
//	pf();//ͨ��ָ��ļ�ӵ���
//	(*pf)();//�ȼ���pf()
//
//	//��ӡ��pf������
//	std::cout << "Type of pf:" << typeid(pf).name() << std::endl;
//	
//	FooT& rf = foo;//û����ʽת��
//	rf();//ͨ�����õļ�ӵ���
//
//	//���rf������
//	std::cout << "Type of rf:" << typeid(rf).name() << std::endl;
//}


#endif//FUNCTION_POINTER_H+