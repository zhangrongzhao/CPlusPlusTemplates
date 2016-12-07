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

void B1::mf1(){//mf1()能够被类型B1的对象调用，mf1()的this指针将会引用类型为B1的对象。
	std::cout << "b1=" << b1 << std::endl;
}

class B2{
private:
	int b2;
public:
	void mf2();
};

void B2::mf2(){//mf2()所期望的隐含参数this指针会指向B2类型的子对象
	std::cout << "b2=" << b2 << std::endl;
}

//同时继承自B1，B2的新类
class D :public B1, public B2{
private:
	int d;
};

void call_memfun(D obj, void (D::*pmf)()){
	(obj.*pmf)();
}

#endif//MEMBER_FUNCTION_POINTER_H