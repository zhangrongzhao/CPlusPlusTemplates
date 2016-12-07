#include "../stdafx.h"

#ifndef HOLDER_TEST
#define HOLDER_TEST
#include "Holder1.h"

class Something{
public:
	Something(){}
	void perform(){ }
};


void test_two_things(){
	Holder<Something> first(new Something);
	first->perform();

	Holder<Something> second(new Something);
	second->perform();
}
#endif//HOLDER_TEST
