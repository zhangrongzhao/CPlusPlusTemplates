#include "../stdafx.h"

#ifndef MEMBER_REFERENCE_COUNT_H
#define MEMBER_REFERENCE_COUNT_H

//����ʽ������ģ��
template<typename ObjectT,//����������������
         typename CountT,//������������
		 CountT ObjectT::*CountP//��������λ��
>
class MemberReferenceCount{
public:
	//ȱʡ���캯���������������������

	//�ü�������ֵ��ʼ��Ϊ1
	void init(ObjectT* object){
		object->*CountP = 1;
	}

	//���ڼ��������ͷţ�������Ҫ��ʾִ���κβ���
	void dispose(ObjectT* object){}

	//����ֵ��1
	void increment(ObjectT* object){
		++(object->*CountP);
	}

	//��������1
	void decrement(ObjectT* object){
		--(object->*CountP);
	}

	//������ֵ�Ƿ�Ϊ0
	template<typename T>
	bool is_zero(ObjectT* object){
		return (object->*CountP) == 0;
	}
};

#endif//MEMBER_REFERENCE_COUNT_H