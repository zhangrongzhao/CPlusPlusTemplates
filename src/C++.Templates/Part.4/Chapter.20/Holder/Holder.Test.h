#include "../stdafx.h"

#ifndef HOLDER_TEST_H
#define HOLDER_TEST_H
#include "Holder.h"

class Something{ 
public:
	void perform(){ }
};
void test_holder(){
	Holder<Something> first(new Something);
	first->perform();

	Holder<Something> second(new Something);
	second->perform();
}

#endif//HOLDER_TEST_H