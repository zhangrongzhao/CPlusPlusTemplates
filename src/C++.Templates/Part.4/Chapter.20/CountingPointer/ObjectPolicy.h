#include "../stdafx.h"

#ifndef OBJECT_POLICY_H
#define OBJECT_POLICY_H
//������������ͷţ���ͨ����==>delete;�������==>delete[];C����==>free.
#include "CounterPolicy.h"

template<typename T>
class ObjectPolicy{
public:
	ObjectPolicy();
	ObjectPolicy(CounterPolicy<T> const&);
	~ObjectPolicy();
	ObjectPolicy<T>& operator=(ObjectPolicy<T> const&);

	//�ͷŶ��󣺼���T����ָ���������͡�
	void dispose(T*);
};

class StandardObjectPolicy{
public:
	template<typename T>
	void dispose(T* object){
		delete object;
	}
};

class StandardArrayPolicy{
public:
	template<typename T>
	void dispose(T* oArray){
		delete[] oArray;
	}
};

#endif//OBJECT_POLICY_H