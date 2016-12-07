#include "../stdafx.h"

#ifndef MEMBER_FUNCTION_POINTER_H
#define MEMBER_FUNCTION_POINTER_H
#include <iostream>

class B1{
private:
	int b1;
public:
	void mf1();
};

void B1::mf1(){//mf1()�ܹ�������B1�Ķ�����ã�mf1()��thisָ�뽫����������ΪB1�Ķ���
	std::cout << "b1=" << b1 << std::endl;
}

class B2{
private:
	int b2;
public:
	void mf2();
};

void B2::mf2(){//mf2()����������������thisָ���ָ��B2���͵��Ӷ���
	std::cout << "b2=" << b2 << std::endl;
}

//ͬʱ�̳���B1��B2������
class D :public B1, public B2{
private:
	int d;
};

void call_memfun(D obj, void (D::*pmf)()){
	(obj.*pmf)();
}

#endif//MEMBER_FUNCTION_POINTER_H