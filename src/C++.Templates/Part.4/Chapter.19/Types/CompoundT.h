#include "../stdafx.h"

#ifndef COMPOUND_TYPE_H
#define COMPOUND_TYPE_H
#include "IsFunctionT.h"
//基本模板：辨别基本类型。
template<typename T>
class CompoundT{
public:
	enum { IsPointerT = 0, IsReferenceT = 0, IsArrayT = 0, IsFunctionT = IsFunctionT<T>::Yes, IsPointerToMemberT = 0 };
	typedef T BaseT;//构造模板参数的直接类型
	typedef T BottomT;//去除指针，引用，用于构造T的原始类型。例如：int**,BaseT==>int*;BottomT==>int;
	                  //成员指针类型：假设T为成员指针类型，int(X::*)(),BaseT==>int(),BottomT==>X.
	typedef CompoundT<void> ClassT;
};

//特化：指针类型
template<typename T>
class CompoundT<T*>{
public:
	enum { IsPointerT = 1, IsReferenceT = 0, IsArrayT = 0, IsFunctionT = 0, IsPointerToMemberT = 0 };
	typedef T BaseT;        //构造模板参数的直接类型
	typedef typename CompoundT<T>::BottomT BottomT;//去除指针，引用，用于构造T的原始类型。例如：int**,BaseT==>int*;BottomT==>int;
	                                              //成员指针类型：假设T为成员指针类型，int(X::*)(),BaseT==>int(),BottomT==>X.
	typedef CompoundT<void> ClassT;
};

//特化：引用类型
template<typename T>
class CompoundT<T&> {
public:
	enum { IsPointerT = 0, IsReferenceT = 1, IsArrayT = 0, IsFunctionT = 0, IsPointerToMemberT = 0 };
	typedef T BaseT;//构造模板参数的直接类型
	typedef typename CompoundT<T>::BottomT BottomT;//去除指针，引用，用于构造T的原始类型。例如：int**,BaseT==>int*;BottomT==>int;
	                                               //成员指针类型：假设T为成员指针类型，int(X::*)(),BaseT==>int(),BottomT==>X.
	typedef CompoundT<void> ClassT;
};

//特化：数组类型
template<typename T,size_t N>
class CompoundT<T[N]>{
public:
	enum { IsPointerT = 0, IsReferenceT = 0, IsArrayT = 1, IsFunctionT = 0, IsPointerToMemberT = 0 };
	typedef T BaseT;//构造模板参数的直接类型
	typedef typename CompoundT<T>::BottomT BottomT;
	typedef CompoundT<void> ClassT;
};

//特化：空数组
template<typename T>
class CompoundT<T[]>{
public:
	enum { IsPointerT = 0, IsReferenceT = 0, IsArrayT = 1, IsFunctionT = 0, IsPointerToMemberT = 0 };
	typedef T BaseT;//构造模板参数的直接类型
	typedef typename CompoundT<T>::BottomT BottomT;
	typedef CompoundT<void> ClassT;
};
 
//特化：成员指针
template<typename T,typename C>
class CompoundT<T C::*>{
public:
	enum { IsPointerT = 0, IsReferenceT = 0, IsArrayT = 0, IsFunctionT = 0, IsPointerToMemberT = 1 };
	typedef T BaseT;//构造模板参数的直接类型
	typedef typename CompoundT<T>::BottomT BottomT;
	typedef C ClassT;
};

//特化：辨别函数类型
template<typename R>
class CompoundT<R()>{
public:
	enum { IsPointerT = 0, IsReferenceT = 0, IsArrayT = 0, IsFunctionT = 1, IsPointerToMemberT = 1 };
	typedef R BaseT();//构造模板参数的直接类型
	typedef R BottomT();
	typedef CompoundT<void> ClassT;
};

template<typename R,typename P1>
class CompoundT<R(P1)>{
public:
	enum { IsPointerT = 0, IsReferenceT = 0, IsArrayT = 0, IsFunctionT = 1, IsPointerToMemberT = 1 };
	typedef R BaseT(P1);//构造模板参数的直接类型
	typedef R BottomT(P1);
	typedef CompoundT<void> ClassT;
};

template<typename R, typename P1>
class CompoundT<R(P1,...)>{
public:
	enum { IsPointerT = 0, IsReferenceT = 0, IsArrayT = 0, IsFunctionT = 1, IsPointerToMemberT = 1 };
	typedef R BaseT(P1);//构造模板参数的直接类型
	typedef R BottomT(P1);
	typedef CompoundT<void> ClassT;
};
#endif//COMPOUND_TYPE_H