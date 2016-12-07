#include "../stdafx.h"
#include <iostream>
class NonVirtual{};

class Virtual{
public:
	virtual void foo(){};
};

template<typename VBase>
class Base :public VBase{
public:
	//foo()函数的虚拟性依赖于它在基类VBase中的声明。
	void foo(){
		std::cout << "Base::foo()" << std::endl;
	}
};

template<typename V>
class Derived :public Base<V>{
public:
	void foo(){
		std::cout << "Derived::foo()" << std::endl;
	}
};

void test_virtual(){
	Base<NonVirtual>* p1 = new Derived<NonVirtual>();
	p1->foo();

	Base<Virtual>* p2 = new Derived<Virtual>();
	p2->foo();
}