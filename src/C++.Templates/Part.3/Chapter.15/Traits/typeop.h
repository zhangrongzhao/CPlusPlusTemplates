#include "../stdafx.h"

#ifndef TYPE_OP_H
#define TYPE_OP_H

//基本模板:处理基本类型
template<typename T>
class TypeOp{
public:
	typedef T ArgT;
	typedef T BareT;
	typedef T const ConstT;
	typedef T& RefT;
	typedef T& RefBareT;
	typedef T const& RefConstT;
};

//针对const类型的局部特化
template<typename T>
class TypeOp<T const>{
public:
	typedef T const ArgT;
	typedef T BareT;          
	typedef T const ConstT;
	typedef T const& RefT;
	typedef T& RefBareT;
	typedef T const& RefConstT;
};

//针对引用的局部特化
template<typename T>
class TypeOp<T&> {
public:
	typedef T& ArgT;
	typedef typename TypeOp<T>::BareT BareT;
	typedef T const ConstT;
	typedef T& RefT;
	typedef typename TypeOp<T>::RefBareT RefBareT;
	typedef T const& RefConstT;
};

//针对void的特化：指向void的引用是不允许的。要对指向void的引用进行全局特化。
template<>
class TypeOp<void>{
public:
	typedef void ArgT;
	typedef void BareT;
	typedef void const ConstT;
	typedef void RefT;
	typedef void RefBareT;
	typedef void RefConstT;
};

#endif//TYPE_OP_H
