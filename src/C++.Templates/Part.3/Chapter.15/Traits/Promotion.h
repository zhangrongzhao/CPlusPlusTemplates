#include "../stdafx.h"
#ifndef PROMOTION_H
#define PROMOTION_H
#include <array>
#include "IfThenElse.h"
//����ģ�壺��������
//�����������ʹ�(sizeof�������ý������)����Ϊ�������
template<typename T1,typename T2>
class Promotion{
public:
	typedef typename IfThenElse<(sizeof(T1)>sizeof(T2)),
		                        T1,
								IfThenElse<(sizeof(T1)<sizeof(T2)),
								           T2,
										   void>
								>::ResultT ResultT;
};

//�ֲ��ػ�����ͬ��������
template<typename T>
class Promotion<T,T>{
public:
	typedef T ResultT;
};

//�ֲ��ػ����������,����Ԫ�����Ͳ�ͬ
template<typename T1,typename T2>
class Promotion<array<T1>,array<T2> >{
public:
	typedef array<typename Promotion<T1, T2>::ResultT> ResultT;
};

//�ֲ��ػ���������飬����Ԫ����ͬ
template<typename T>
class Promotion<array<T>,array<T> >{
public:
	typedef array<typedef Promotion<T, T>::ResultT> ResultT;
};

//���������������꣺����Դ�����������
#define MK_PROMOTION(T1,T2,Tr)                  \
template<>                                      \
class Promotion<T1,T2>{                         \
public:                                         \
	typedef Tr ResultT;                         \
};                                              \
	                                            \
template<>                                      \
class Promotion<T2,T1>{                         \
public:                                         \
	typedef Tr ResultT;                         \
};                                              \

MK_PROMOTION(bool,char,int);
MK_PROMOTION(bool,unsigned char,int);
MK_PROMOTION(bool,signed char,int);
#endif//PROMOTION_H