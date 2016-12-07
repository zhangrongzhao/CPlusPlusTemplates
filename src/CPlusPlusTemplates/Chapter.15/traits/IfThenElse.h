#include "../stdafx.h"

#ifndef IFTHENELSE_H
#define IFTHENELSE_H

//primary template:���ݵ�һ��ʵ������������ѡ���2��ʵ�Σ����ǵ�����ʵ��
template<bool C,typename Ta,typename Tb>
class IfThenElse;

//partail specialization: trueѡ��ڶ���ʵ��
template<typename Ta,typename Tb>
class IfThenElse<true,Ta,Tb>{
public:
	typedef Ta ResultT;
};

//partial specialization:falseѡ�������ʵ��
template<typename Ta,typename Tb>
class IfThenElse<false,Ta,Tb>{
public:
	typedef Tb ResultT;
};

#endif//IFTHENELSE_H