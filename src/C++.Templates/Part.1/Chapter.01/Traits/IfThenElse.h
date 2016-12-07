#include "../stdafx.h"

#ifndef IF_THEN_ELSE_H
#define IF_THEN_ELSE_H

//���ݵ�һ�������Ľ����trueѡ��ڶ������Ͳ�����falseѡ����������Ͳ���
template<bool C,typename T1,typename T2>
class IfThenElse;

//�ֲ��ػ���partial specialization
template<typename T1,typename T2>
class IfThenElse<true,T1,T2>{
public:
	typedef T1 ResultT;
};

template<typename T1,typename T2>
class IfThenElse<false,T1,T2>{
public:
	typedef T2 ResultT;
};


#endif//IF_THEN_ELSE_H