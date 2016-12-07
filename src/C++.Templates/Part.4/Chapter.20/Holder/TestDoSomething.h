#include "../stdafx.h"

#ifndef TEST_DO_SOMETHING_H
#define TEST_DO_SOMETHING_H

class Something{
public:
	void perform(){
		throw;
	}
};

void do_something(){
	Something* first = 0;
	Something* second = 0;
	try{
		first = new Something;
		second = new Something;
		first->perform();
		second->perform();
		delete first;
		delete second;
	}
	catch (...){
		delete first;
		delete second;
		throw;
	}
}

void test_do_something(){
	do_something();
}

#endif//TEST_DO_SOMETHING_H