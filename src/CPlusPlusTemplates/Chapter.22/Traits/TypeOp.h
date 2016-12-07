#include "../stdafx.h"

#ifndef TYPE_OP_H
#define TYPE_OP_H
//基本模板
template<typename T>
class TypeOp{
public:
	typedef T ArgT;
	typedef T BareT;
	typedef T const ConstT;
	typedef T& RefT;
	typedef T& RefBareT;
	typedef T const & RefConstT;
};

//针对常量类型局部特化
template<typename T>
class TypeOp<T const>{//针对const类型的局部特化
public:
	typedef T const ArgT;
	typedef T BareT;
	typedef T const ConstT;
	typedef T const& RefT;
	typedef T & RefBareT;
	typedef T const& RefConstT;
};

//针对引用类型局部特化
template<typename T>
class TypeOp<T&>{//针对引用的局部特化
public:
	typedef T& ArgT;
	typedef T& RefT;
	typedef T const ConstT;
	typedef typename TypeOp<T>::BareT BareT;
	typedef typename TypeOp<T>::BareT & RefBareT;
	typedef T const & RefConstT;
};

//针对void类型进行全局特化
template<>
class TypeOp<void>{//针对void的全局特化
public:
	typedef void ArgT;
	typedef void BareT;
	typedef void const ConstT;
	typedef void RefT;
	typedef void RefBareT;
	typedef void RefConstT;
};


#endif//TYPE_OP_H