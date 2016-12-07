#include "../stdafx.h"

#ifndef AMBIGUOUS_NAME_H
#define AMBIGUOUS_NAME_H

class Top{
public:
	virtual ~Top(){ }
	virtual void f(){ }
};

class Left :virtual public Top{
public:
	void f(){ }
};

class Right :virtual public Top{ };

class Bottom :public Left, public Right{ };

void test_A_name(){
	Bottom b;
	b.f();
}
#endif//AMBIGUOUS_NAME_H