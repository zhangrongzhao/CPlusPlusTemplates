#include "../stdafx.h"

#ifndef VIRTUAL_PARAMTER_H
#define VIRTUAL_PARAMTER_H
#include <iostream>

class NotVirtual{ };
class Virtual{
public:
	virtual void foo(){ }
};

template<typename VBase>
class Base :private VBase{
public:
	void foo(){
		std::cout << "Base::foo()" << "\n";
	}
};

template<typename V>
class Derived :public Base<V>{
public:
	void foo(){
		std::cout << "Derived::foo()" << "\n";
	}
};

void test_virtual(){
	Base<NotVirtual>* p1 = new Derived<NotVirtual>;
	p1->foo();

	Base<Virtual>* p2 = new Derived<Virtual>;
	p2->foo();
}

#endif//VIRTUAL_PARAMTER_H