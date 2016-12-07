#include "../stdafx.h"

#ifndef IF_THEN_ELSE_H
#define IF_THEN_ELSE_H
//���ݵ�һ��ģ�������ѡ��������:B==true��ѡ��T1��ΪResultT��B==false��ѡ��T2��ΪResultT��
template<bool B,typename T1,typename T2>
class IfThenElse;

//�ֲ��ػ���B==true��ѡ��T1��ΪResultT
template<typename T1,typename T2>
class IfThenElse<true,T1,T2>{
public:
	typedef T1 ResultT;
};

//�ֲ��ػ���B==false,ѡ��T2��ΪResultT
template<typename T1,typename T2>
class IfThenElse<false,T1,T2>{
public:
	typedef T2 ResultT;
};

#endif//IF_THEN_ELSE_H