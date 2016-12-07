#include "../stdafx.h"

#ifndef FUNCTION_WRAPPER_H
#define FUNCTION_WRAPPER_H

#include <vector>
#include <iostream>
#include <cstdlib>

//���ڰѺ���ָ���װΪ��������ķ�װ��
template<int (*FP)()>
class FunctionReturningIntWrapper{
public:
	int operator()(){
		return FP();
	}
};

//Ҫ���з�װ�ĺ���ʵ��
int random_int(){
	return std::rand();//���ñ�׼��C����
}

//�ͻ��ˣ���ʹ����ģ��������ݽ����ĺ�����������
template<typename FO>
void initialize(std::vector<int>& coll){
	FO fo;//������������
	for (std::vector<int>::size_type i = 0; i < coll.size();++i){
		coll[i] = fo();//�����ɺ��������ʾ�ĺ���
	}
}

#endif//FUNCTION_WRAPPER_H