#include "../stdafx.h"

#ifndef SIMPLE_REFERENCE_COUNT_H
#define SIMPLE_REFERENCE_COUNT_H

#include <stddef.h>
//#include <alloc>
//简单的非侵入式计数器
class SimpleReferenceCount{
private:
	size_t* counter;//已经分配的计数器
public:
	SimpleReferenceCount(){
		counter = NULL;
	}

	//缺省的拷贝构造函数和拷贝赋值运算符都是允许的，因为他们只是拷贝这个共享的计数器
public:
	//分配计数器，并把它的值初始为1
	template<typename T>
	void init(T*){
		counter = alloc_counter();
		*(counter) = 1;
	}

	//释放该计数器
	template<typename T>
	void dispose(T*){
		dealloc_counter(counter);
	}

	//计数值加1
	template<typename T>
	void increment(T*){
		++(*counter);
	}

	//计数值减1
	template<typename T>
	void decrement(T*){
		--(*counter);
	}

	//检查计数值是否为0
	template<typename T>
	bool is_zero(T*){
		return *(counter) == 0;
	}
};



#endif//SIMPLE_REFERENCE_COUNT_H