#include "../stdafx.h"

#ifndef DOMAINANCE_H
#define DOMAINANCE_H
#include <iostream>

class A{
public:
	virtual ~A(){ }
	virtual void f(){ std::cout << "A::f\n"; }
};

class B:virtual public A{
public:
	void f(){ std::cout << "B::f\n"; }
};

class C :public B{};
class D :public C, virtual public A{ };
void test_Domainance2(){
	B* p = new D;
	p->f();
	delete p;
}

#endif//DOMAINANCE_H