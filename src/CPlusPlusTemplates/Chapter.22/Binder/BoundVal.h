#include "../stdafx.h"

#ifndef BOUND_VALUE_H
#define BOUND_VALUE_H

#include "../Traits/TypeOp.h"

//�����ڱ����ֵ
template<typename T>
class BoundVal{
private:
	T value;
public:
	typedef T ValueT;
	BoundVal(T v):value(v){ }

	typename TypeOp<T>::RefT get(){
		return value;
	}
};

//�����ڱ����ֵ
template<typename T, T Val>
class StaticBoundVal{
public:
	typedef T ValueT;
	T get(){
		return Val;
	}
};


#endif//BOUND_VALUE_H