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
//���ָ�����;ֲ��ػ�
template<typename T>
class CompoundT<T*> {
public:
	enum{ IsPtrT = 1, IsRefT = 0, IsArrayT = 0, IsFuncT = 0, IsPtrMemT = 0 };
	typedef T BaseT;
	typedef typename CompoundT<T>::BottomT BottomT;//���T�Ƕ༶ָ�룬��ʹ�û���ģ�壬�ݹ��ȡ��ײ�ָ����ָ������͡�
	typedef CompoundT<void> ClassT;
};

/***************************specialization:reference Type**********************/
//partial specialization
//����������;ֲ��ػ�
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
//�������ľֲ��ػ�
template<typename T,size_t N>
class CompoundT<T[N]>{
public:
	enum{ IsPtrT = 0, IsRefT = 0, IsArrayT = 1, IsFuncT = 0, IsPtrMemT = 0 };
	typedef T BaseT;
	typedef typename CompoundT<T>::BottomT BottomT;
	typedef CompoundT<void> ClassT;
};

//��Կ�����ľֲ��ػ�
template<typename T>
class CompoundT<T[]>{
public:
	enum{ IsPtrT = 0, IsRefT = 0, IsArrayT = 1, IsFuncT = 0, IsPtrMemT = 0 };
	typedef T BaseT;
	typedef typename CompoundT<T>::BottomT BottomT;
	typedef CompoundT<void> ClassT;
};

/***************************specialization:Pointer Member Type*************/
//��Գ�Աָ��ľֲ��ػ�
template<typename T,typename C>
class CompoundT<T C::*>{
public:
	enum{ IsPtrT = 0, IsRefT = 0, IsArrayT = 0, IsFuncT = 0, IsPtrMemT = 1 };
	typedef T BaseT;
	typedef typename CompoundT<T>::BottomT BottomT;
	typedef C ClassT;
};

/***************************specialization:Function Type******************/
//��Ժ������ͽ����ػ�:�����޲���
template<typename R>
class CompoundT<R()>{
public:
	enum{ IsPtrT = 0, IsRefT = 0, IsArrayT = 0, IsFuncT = 1, IsPtrMemT = 0 };
	typedef R Base();
	typedef R Bottom();
	typedef CompoundT<void> ClassT;
};

//��������һ������
template<typename R,typename P1>
class CompoundT<R(P1)>{
public:
	enum{ IsPtrT = 0, IsRefT = 0, IsArrayT = 0, IsFuncT = 1, IsPtrMemT = 0 };
	typedef R BaseT(P1);
	typedef R BottomT(P1);
	typedef CompoundT<void> ClassT;
};

//�ɱ����
template<typename R,typename P1>
class CompoundT<R(P1,...)>{
public:
	enum{ IsPtrT = 0, IsRefT = 0, IsArrayT = 0, IsFuncT = 1, IsPtrMemT = 0 };
	typedef R BaseT(P1);
	typedef R BottomT(P1);
	typedef CompoundT<void> ClassT;
};
#endif//COMPUND_TYPE