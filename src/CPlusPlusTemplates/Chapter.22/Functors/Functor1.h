#include "../stdafx.h"

#ifndef FUNCTOR_1_H
#define FUNCTOR_1_H

#include <iostream>

//���з��س�ֵ�ĺ����������
class ConstantIntFunctor{
private:
	int value;//"��������"�����ص�ֵ
public:
	//ConstantIntFunctor() :value(){}
	ConstantIntFunctor(int c):value(c){ }

	//"��������"
	int operator() () const{
		return value;
	}
};

//ʹ�����桰�������󡱵Ŀͻ��˺���
void client(ConstantIntFunctor const&  cif){
	std::cout << "calling back functor yields" << cif() << std::endl;
}


#endif//FUNCTOR_1_H
