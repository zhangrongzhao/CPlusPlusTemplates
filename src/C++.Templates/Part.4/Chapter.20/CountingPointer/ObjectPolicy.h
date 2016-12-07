#include "../stdafx.h"

#ifndef OBJECT_POLICY_H
#define OBJECT_POLICY_H
//对象的析构和释放：普通对象==>delete;数组对象==>delete[];C对象==>free.
#include "CounterPolicy.h"

template<typename T>
class ObjectPolicy{
public:
	ObjectPolicy();
	ObjectPolicy(CounterPolicy<T> const&);
	~ObjectPolicy();
	ObjectPolicy<T>& operator=(ObjectPolicy<T> const&);

	//释放对象：假设T是所指向对象的类型。
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