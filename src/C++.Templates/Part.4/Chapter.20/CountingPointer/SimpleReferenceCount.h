#include "../stdafx.h"

#ifndef SIMPLE_REFERENCE_COUNT_H
#define SIMPLE_REFERENCE_COUNT_H

//һ���򵥵ķ�����ʽ��������
class SimpleReferenceCount{
private:
	size_t counter;
public:
	SimpleReferenceCount():counter(0){ }
public:
	template<typename T>
	void init(T*){
		counter = 1;
	}

	template<typename T>
	void dispose(T*){
		counter = 0;
	}

	template<typename T>
	void increment(T*){
		counter++;
	}

	template<typename T>
	void decrement(T*){
		counter--;
	}

	template<typename T>
	bool is_zero(){
		return counter == 0;
	}
};
#endif//SIMPLE_REFERENCE_COUNT_H