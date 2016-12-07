#include "../stdafx.h"

#ifndef SIMPLE_REFERENCE_COUNT_H
#define SIMPLE_REFERENCE_COUNT_H

#include <stddef.h>
//#include <alloc>
//�򵥵ķ�����ʽ������
class SimpleReferenceCount{
private:
	size_t* counter;//�Ѿ�����ļ�����
public:
	SimpleReferenceCount(){
		counter = NULL;
	}

	//ȱʡ�Ŀ������캯���Ϳ�����ֵ�������������ģ���Ϊ����ֻ�ǿ����������ļ�����
public:
	//�������������������ֵ��ʼΪ1
	template<typename T>
	void init(T*){
		counter = alloc_counter();
		*(counter) = 1;
	}

	//�ͷŸü�����
	template<typename T>
	void dispose(T*){
		dealloc_counter(counter);
	}

	//����ֵ��1
	template<typename T>
	void increment(T*){
		++(*counter);
	}

	//����ֵ��1
	template<typename T>
	void decrement(T*){
		--(*counter);
	}

	//������ֵ�Ƿ�Ϊ0
	template<typename T>
	bool is_zero(T*){
		return *(counter) == 0;
	}
};



#endif//SIMPLE_REFERENCE_COUNT_H