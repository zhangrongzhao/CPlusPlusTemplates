#include "../stdafx.h"
#include <stddef.h>

#ifndef COMPUND_TYPE
#define COMPUND_TYPE
#include "IsFunctionType.h"
/****************************primary template***********************************/
//primary template
template<typename T>
class CompoundT{
public:
	enum{ IsPtrT = 0, IsRefT = 0, IsArrayT = 0, IsFuncT = IsFunctionT<T>::Yes, IsPtrMemT = 0 };
	typedef T BaseT;
	typedef T BottomT;
	typedef CompoundT<void> ClassT;
};

/***************************specialization:Pointer Type************************/
//partial specialization
//针对指针类型局部特化
template<typename T>
class CompoundT<T*> {
public:
	enum{ IsPtrT = 1, IsRefT = 0, IsArrayT = 0, IsFuncT = 0, IsPtrMemT = 0 };
	typedef T BaseT;
	typedef typename CompoundT<T>::BottomT BottomT;//如果T是多级指针，则使用基本模板，递归获取最底层指针所指向的类型。
	typedef CompoundT<void> ClassT;
};

/***************************specialization:reference Type**********************/
//partial specialization
//针对引用类型局部特化
template<typename T>
class CompoundT<T&>{
public:
	enum{ IsPtrT = 0, IsRefT = 1, IsArrayT = 0, IsFuncT = 0, IsPrtMemT = 0 };
	typedef T BaseT;
	typedef typename CompoundT<T>::BottomT BottomT;
	typedef CompoundT<void> ClassT;
};

/***************************specialization:Array Type**********************/
//partial specialization 
//针对数组的局部特化
template<typename T,size_t N>
class CompoundT<T[N]>{
public:
	enum{ IsPtrT = 0, IsRefT = 0, IsArrayT = 1, IsFuncT = 0, IsPtrMemT = 0 };
	typedef T BaseT;
	typedef typename CompoundT<T>::BottomT BottomT;
	typedef CompoundT<void> ClassT;
};

//针对空数组的局部特化
template<typename T>
class CompoundT<T[]>{
public:
	enum{ IsPtrT = 0, IsRefT = 0, IsArrayT = 1, IsFuncT = 0, IsPtrMemT = 0 };
	typedef T BaseT;
	typedef typename CompoundT<T>::BottomT BottomT;
	typedef CompoundT<void> ClassT;
};

/***************************specialization:Pointer Member Type*************/
//针对成员指针的局部特化
template<typename T,typename C>
class CompoundT<T C::*>{
public:
	enum{ IsPtrT = 0, IsRefT = 0, IsArrayT = 0, IsFuncT = 0, IsPtrMemT = 1 };
	typedef T BaseT;
	typedef typename CompoundT<T>::BottomT BottomT;
	typedef C ClassT;
};

/***************************specialization:Function Type******************/
//针对函数类型进行特化:函数无参数
template<typename R>
class CompoundT<R()>{
public:
	enum{ IsPtrT = 0, IsRefT = 0, IsArrayT = 0, IsFuncT = 1, IsPtrMemT = 0 };
	typedef R Base();
	typedef R Bottom();
	typedef CompoundT<void> ClassT;
};

//函数：有一个参数
template<typename R,typename P1>
class CompoundT<R(P1)>{
public:
	enum{ IsPtrT = 0, IsRefT = 0, IsArrayT = 0, IsFuncT = 1, IsPtrMemT = 0 };
	typedef R BaseT(P1);
	typedef R BottomT(P1);
	typedef CompoundT<void> ClassT;
};

//可变参数
template<typename R,typename P1>
class CompoundT<R(P1,...)>{
public:
	enum{ IsPtrT = 0, IsRefT = 0, IsArrayT = 0, IsFuncT = 1, IsPtrMemT = 0 };
	typedef R BaseT(P1);
	typedef R BottomT(P1);
	typedef CompoundT<void> ClassT;
};
#endif//COMPUND_TYPE