#include "../stdafx.h"

#ifndef COMPOUND_TYPE_H
#define COMPOUND_TYPE_H
#include "IsFunctionT.h"
//����ģ�壺���������͡�
template<typename T>
class CompoundT{
public:
	enum { IsPointerT = 0, IsReferenceT = 0, IsArrayT = 0, IsFunctionT = IsFunctionT<T>::Yes, IsPointerToMemberT = 0 };
	typedef T BaseT;//����ģ�������ֱ������
	typedef T BottomT;//ȥ��ָ�룬���ã����ڹ���T��ԭʼ���͡����磺int**,BaseT==>int*;BottomT==>int;
	                  //��Աָ�����ͣ�����TΪ��Աָ�����ͣ�int(X::*)(),BaseT==>int(),BottomT==>X.
	typedef CompoundT<void> ClassT;
};

//�ػ���ָ������
template<typename T>
class CompoundT<T*>{
public:
	enum { IsPointerT = 1, IsReferenceT = 0, IsArrayT = 0, IsFunctionT = 0, IsPointerToMemberT = 0 };
	typedef T BaseT;        //����ģ�������ֱ������
	typedef typename CompoundT<T>::BottomT BottomT;//ȥ��ָ�룬���ã����ڹ���T��ԭʼ���͡����磺int**,BaseT==>int*;BottomT==>int;
	                                              //��Աָ�����ͣ�����TΪ��Աָ�����ͣ�int(X::*)(),BaseT==>int(),BottomT==>X.
	typedef CompoundT<void> ClassT;
};

//�ػ�����������
template<typename T>
class CompoundT<T&> {
public:
	enum { IsPointerT = 0, IsReferenceT = 1, IsArrayT = 0, IsFunctionT = 0, IsPointerToMemberT = 0 };
	typedef T BaseT;//����ģ�������ֱ������
	typedef typename CompoundT<T>::BottomT BottomT;//ȥ��ָ�룬���ã����ڹ���T��ԭʼ���͡����磺int**,BaseT==>int*;BottomT==>int;
	                                               //��Աָ�����ͣ�����TΪ��Աָ�����ͣ�int(X::*)(),BaseT==>int(),BottomT==>X.
	typedef CompoundT<void> ClassT;
};

//�ػ�����������
template<typename T,size_t N>
class CompoundT<T[N]>{
public:
	enum { IsPointerT = 0, IsReferenceT = 0, IsArrayT = 1, IsFunctionT = 0, IsPointerToMemberT = 0 };
	typedef T BaseT;//����ģ�������ֱ������
	typedef typename CompoundT<T>::BottomT BottomT;
	typedef CompoundT<void> ClassT;
};

//�ػ���������
template<typename T>
class CompoundT<T[]>{
public:
	enum { IsPointerT = 0, IsReferenceT = 0, IsArrayT = 1, IsFunctionT = 0, IsPointerToMemberT = 0 };
	typedef T BaseT;//����ģ�������ֱ������
	typedef typename CompoundT<T>::BottomT BottomT;
	typedef CompoundT<void> ClassT;
};
 
//�ػ�����Աָ��
template<typename T,typename C>
class CompoundT<T C::*>{
public:
	enum { IsPointerT = 0, IsReferenceT = 0, IsArrayT = 0, IsFunctionT = 0, IsPointerToMemberT = 1 };
	typedef T BaseT;//����ģ�������ֱ������
	typedef typename CompoundT<T>::BottomT BottomT;
	typedef C ClassT;
};

//�ػ������������
template<typename R>
class CompoundT<R()>{
public:
	enum { IsPointerT = 0, IsReferenceT = 0, IsArrayT = 0, IsFunctionT = 1, IsPointerToMemberT = 1 };
	typedef R BaseT();//����ģ�������ֱ������
	typedef R BottomT();
	typedef CompoundT<void> ClassT;
};

template<typename R,typename P1>
class CompoundT<R(P1)>{
public:
	enum { IsPointerT = 0, IsReferenceT = 0, IsArrayT = 0, IsFunctionT = 1, IsPointerToMemberT = 1 };
	typedef R BaseT(P1);//����ģ�������ֱ������
	typedef R BottomT(P1);
	typedef CompoundT<void> ClassT;
};

template<typename R, typename P1>
class CompoundT<R(P1,...)>{
public:
	enum { IsPointerT = 0, IsReferenceT = 0, IsArrayT = 0, IsFunctionT = 1, IsPointerToMemberT = 1 };
	typedef R BaseT(P1);//����ģ�������ֱ������
	typedef R BottomT(P1);
	typedef CompoundT<void> ClassT;
};
#endif//COMPOUND_TYPE_H